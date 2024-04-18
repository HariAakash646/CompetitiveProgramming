#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;


void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}


int h, w, q;
int n;

int eval(int x, int y, int t) {
    return x*w + y + h*w * t;
}

struct Data {
    int x, y;
    int t = 0;
    int c = 0;

    int eval() {
        return x*w + y + h*w * t;
    }
};

int main() {
    // usaco();
    fastio();
    cin >> h >> w >> q;

    n = h * w;

    vector<vector<Data>> graph(2*n);

    frange(i, h) {
        frange(j, w) {
            Data tmp;
            tmp.x = i;
            tmp.y = j;
            tmp.t = 1;
            tmp.c = 1;
            graph[eval(i, j, 0)].pb(tmp);
        }
    }

    frange(i, h) {
        string str;
        cin >> str;
        frange(j, w-1) {

            if(str[j] == '1') {
                Data tmp;
                tmp.x = i;
                tmp.y = j+1;
                tmp.t = 0;
                tmp.c = 0;
                graph[eval(i, j, 0)].pb(tmp);
                tmp.t = 1;
                graph[eval(i, j, 1)].pb(tmp);
                tmp.y = j;
                tmp.t = 0;
                graph[eval(i, j+1, 0)].pb(tmp);
                tmp.t = 1;
                graph[eval(i, j+1, 1)].pb(tmp);

            }
            else {
                Data tmp;
                tmp.x = i;
                tmp.y = j+1;
                tmp.t = 1;
                tmp.c = 0;
                graph[eval(i, j, 1)].pb(tmp);
                tmp.y = j;
                graph[eval(i, j+1, 1)].pb(tmp);
            }
        }
    }

    frange(i, h-1) {
        string str;
        cin >> str;
        frange(j, w) {
            if(str[j] == '1') {
                Data tmp;
                tmp.x = i+1;
                tmp.y = j;
                graph[eval(i, j, 0)].pb(tmp);
                graph[eval(i, j, 1)].pb(tmp);
                tmp.x = i;
                graph[eval(i+1, j, 0)].pb(tmp);
                graph[eval(i+1, j, 1)].pb(tmp);
            }
        }
    }

    vi vec(h);
    frange(i, h) {
        cin >> (vec[i]);
    }

    frange(_, q) {
        int t;
        cin >> t;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        int st = eval(x1, y1, 0);
        int en1 = eval(x2, y2, 0);
        int en2 = eval(x2, y2, 1);
        vi dist(2*n, 1e9);
        deque<pair<int, int>> q;
        q.push_front(mp(st, 0));
        vb vis(2*n);

        while(q.size()) {
            auto p = q.front();
            q.pop_front();
            if(vis[p.f]) continue;
            vis[p.f] = true;
            dist[p.f] = p.s;

            // cout << p.f << " " << p.s << "\n";

            for(auto e : graph[p.f]) {
                if(e.c) {
                    q.pb(mp(e.eval(), dist[p.f]+e.c));
                }
                else q.push_front(mp(e.eval(), dist[p.f]));
            }
        }
        int mi = min(dist[en1], dist[en2]);
        if(mi >= 1e9) cout << ("-1\n");
        else cout << mi << "\n";
    }
}