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

vvi graph;
vi dp;

int ma = 0;

pii dfs(int x, int p, int p2, int d) {
    pii p1 = mp(d, x);
    for(auto e : graph[x]) {
        if(e != p && e != p2) {
            p1 = max(p1, dfs(e, x, p2, d+1));
        }
    }
    return p1;
}

// vi dist;

// void dfs2(int x, int p) {
//     dist[x] = dist[p] + 1;
//     for(auto e : graph[x]) {
//         if(e != p) dfs2(e, x);
//     }
// }

int main() {
    // usaco();
    int n;
    scd(n);

    graph = vvi(n+1);
    vii edg;

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
        edg.pb(mp(a, b));
    }

    dp = vi(n+1);

    for(auto p : edg) {
        int a = dfs(p.f, 0, p.s, 0).s;
        int d = dfs(a, 0, p.s, 0).f;

        a = dfs(p.s, 0, p.f, 0).s;
        d += dfs(a, 0, p.f, 0).f;
        ma = max(ma, d+1);

    }
    // dist = vi(n+1, -1);
    // dfs2(a, 0);
    // vi dista = dist;
    // dist = vi(n+1, -1);
    // dfs2(b, 0);

    // int ma = dist[a];

    // printf("%d %d ", a, b);

    // forr(i, 1, n+1) {
    //     ma = max(ma, dist[a] + (dista[i] + dist[i] - dist[a]) / 2);
    // }

    printf("%d", ma);
}