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
    int n, k;
    cin >> n >> k;
    vi vec(n);
    frange(i, n) {
        scd(vec[i]);
        vec[i]--;
    }

    vector<vb> con(k, vb(k));

    frange(i, k) {
        string str;
        cin >> str;
        frange(j, k) {
            con[i][j] = str[j] - '0';
        }
    }

    
    vector<vll> dist(n, vll(k+1, 1e18));
    vector<vb> vis(n, vb(k+1));
    queue<pii> q;

    q.push(mp(0, k));
    dist[0][k] = 0;
    while(q.size()) {
        auto p = q.front();
        q.pop();
        if(vis[p.f][p.s]) continue;
        vis[p.f][p.s] = true;
        int v = p.s;
        if(p.s == k) {
            v = vec[p.f];
        }
        // printf("%d %d\n", p.f, p.s);
        if(p.f + 1 < n) {
            if(dist[p.f][p.s] + 1 < dist[p.f+1][v]) {
                dist[p.f+1][v] = dist[p.f][p.s]+1;
                q.push(mp(p.f+1, v));
            }
            if(con[v][vec[p.f+1]]) {
                if(dist[p.f][p.s] + 1 < dist[p.f+1][k]) {
                    dist[p.f+1][k] = dist[p.f][p.s] + 1;
                    q.push(mp(p.f+1, k));
                }
            }
        }

        if(p.f - 1 >= 0) {
            if(dist[p.f][p.s] + 1 < dist[p.f-1][v]) {
                dist[p.f-1][v] = dist[p.f][p.s]+1;
                q.push(mp(p.f-1, v));
            }
            if(con[v][vec[p.f-1]]) {
                if(dist[p.f][p.s] + 1 < dist[p.f-1][k]) {
                    dist[p.f-1][k] = dist[p.f][p.s] + 1;
                    q.push(mp(p.f-1, k));
                }
            }
        }
    }

    if(dist[n-1][k] < 1e18) printf("%lld", dist[n-1][k]);
    else printf("-1");

}