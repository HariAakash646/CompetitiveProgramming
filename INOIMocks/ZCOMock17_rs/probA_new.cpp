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
vi dp1, dp2;

int ma = 0;

void dfs(int x, int p, int d) {
    mseti st1, st2;
    st1.insert(d);
    st2.insert(-1);
    dp1[x] = 0;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x, d+1);
            // ma = max(ma, (dp1[e]+1) + *prev(st2.end()) + 1 + *prev(st1.end()));
            // int v1 = dp2[e] + *prev(st1.end()) + 1;
            // if(st1.size() >= 2) {
            //     v1 += *prev(prev(st1.end()));
            // }
            // ma = max(ma, v1);
            // printf("%d %d %d %d %d %d\n", x, e, ma, *prev(st2.end()), dp1[e] + 1, *prev(st1.end()));
            dp2[x] = max(dp2[x], dp2[e]);
            dp1[x] = max(dp1[x], dp1[e]+1);
            st1.insert(dp1[e]+1);
            st2.insert(dp2[e]);
        }
    }

    for(auto e : graph[x]) {
        if(e != p) {
            int v1 = dp2[e]+1;
            st1.erase(st1.find(dp1[e]+1));
            v1 += *prev(st1.end());
            if(st1.size() >= 2) v1 += *prev(prev(st1.end()));
            ma = max(ma, v1);
            st1.insert(dp1[e]+1);
            // printf("%d %d %d %d %d %d\n", x, e, ma, v1, dp1[e] + 1, *prev(st1.end()));
        }
    }
    st1.erase(st1.find(d));
    if(st1.size() >= 2) dp2[x] = max(dp2[x], *prev(st1.end()) + *prev(prev(st1.end())));
    else if(st1.size() == 1) dp2[x] = max(dp2[x], *prev(st1.end()));
    dp2[x] = max(dp2[x], dp1[x]);
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

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dp1 = dp2 = vi(n+1);

    // int a = dfs(1, 0, 0).s;
    // int b = dfs(a, 0, 0).s;

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
    dfs(1, 0, 0);
    printf("%d", ma);
}
