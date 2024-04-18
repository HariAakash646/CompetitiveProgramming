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

int main() {
    // usaco();
    fastio();
    int n, m;
    cin >> n >> m;
    vvi grid(n, vi(m));
    queue<pii> q;
    pii st;

    vvi dist(n, vi(m, 1e9));

    vector<vii> pre(n, vii(m));

    frange(i, n) {
        string row;
        cin >> row;
        frange(j, m) {
            if(row[j] == '#') grid[i][j] = 1;
            else if(row[j] == 'M') {
                q.push({i, j});
                dist[i][j] = 0;
            }
            else if(row[j] == 'A') st = mp(i, j);
        }
    }

    while(q.size()) {
        auto p = q.front();
        q.pop();

        vii vec = {mp(1, 0), mp(-1, 0), mp(0, 1), mp(0, -1)};

        for(auto e : vec) {
            if(p.f + e.f >= 0 && p.f + e.f < n && p.s + e.s >= 0 && p.s + e.s < m) {
                if(!grid[p.f+e.f][p.s+e.s] && dist[p.f][p.s] + 1 < dist[p.f + e.f][p.s + e.s]) {
                    dist[p.f+e.f][p.s+e.s] = dist[p.f][p.s]+1;
                    q.push(mp(p.f+e.f, p.s+e.s));
                }
            }
        }
    }

    vvi dist2(n, vi(m, 1e9));
    dist2[st.f][st.s] = 0;

    // printf("%d %d\n", st.f, st.s);

    q.push(st);

    while(q.size()) {
        auto p = q.front();
        q.pop();

        vii vec = {mp(1, 0), mp(-1, 0), mp(0, 1), mp(0, -1)};

        for(auto e : vec) {
            if(p.f + e.f >= 0 && p.f + e.f < n && p.s + e.s >= 0 && p.s + e.s < m) {
                if(!grid[p.f+e.f][p.s+e.s] && dist2[p.f][p.s] + 1 < dist2[p.f + e.f][p.s + e.s] && dist2[p.f][p.s] + 1 < dist[p.f + e.f][p.s + e.s]) {
                    dist2[p.f+e.f][p.s+e.s] = dist2[p.f][p.s]+1;
                    pre[p.f+e.f][p.s+e.s] = mp(p.f, p.s);
                    q.push(mp(p.f+e.f, p.s+e.s));
                }
            }
        }
    }

    map<pii, char> mv;
    mv[mp(1, 0)] = 'U';
    mv[mp(-1, 0)] = 'D';
    mv[mp(0, 1)] = 'L';
    mv[mp(0, -1)] = 'R'; 

    auto output = [&](int x, int y) {
        cout << "YES\n";
        cout << dist2[x][y] << "\n";
        pii curr = mp(x, y);
        string out = "";

        frange(i, dist2[x][y]) {
            pii nex = pre[curr.f][curr.s];
            pii p = mp(nex.f - curr.f, nex.s - curr.s);
            // printf("%d %d\n", p.f, p.s);
            out += mv[p];
            curr = nex;
        }
        reverse(all(out));
        cout << out;
    };

    frange(i, n) {
        if(dist2[i][m-1] < 1e9) {
            output(i, m-1);
            return 0;
        }

        if(dist2[i][0] < 1e9) {
            output(i, 0);
            return 0;
        }
    }

    frange(i, m) {
        if(dist2[n-1][i] < 1e9) {
            output(n-1, i);
            return 0;
        } 
        if(dist2[0][i] < 1e9) {
            output(0, i);
            return 0;
        }
    }

    cout<<"NO";


}