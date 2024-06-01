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

vll dp;
vi sze;
vvi graph;

void dfs(int x, int p) {
    sze[x] = 1;
    lli sz = 0;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
            dp[x] += dp[e] + sze[e] + 2 * sz * sze[e];
            sz += sze[e];
            sze[x] += sze[e];
        }
    }
}

pii diam(int x, int p) {
    pii p1 = mp(0, x);

    for(auto e : graph[x]) {
        if(e != p) {
            pii out = diam(e, x);
            p1= max(p1, mp(out.f+1, out.s));
        }
    }
    return p1;
}

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
    int a = diam(1, 0).s;
    int b = diam(a, 0).s;
    dp = vll(n+1);
    sze = vi(n+1);
    dfs(a, 0);
    lli mi = dp[a];
    dfs(b, 0);
    mi = min(mi, dp[b]);
    // forr(i, 1, n+1) {
    //     dp = vll(n+1);
    //     sze = vi(n+1);
    //     dfs(i, 0);
    //     // printf("%d %lld\n", i, dp[i]);
    //     mi = min(mi, dp[i]);
    // }
    printf("%lld", mi);

}