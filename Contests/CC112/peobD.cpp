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

const lli mod = 1e9 + 7;

vvi graph;
vll dp0, dpb, dpr;

void dfs(int x, int p) {
    bool done = false;
    dpb[x] = 0;
    dpr[x] = 0;
    dp0[x] = 1;
    lli r2 = 0;
    lli b2 = 0;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
            lli v = dp0[x];
            dp0[x] *= dp0[e];
            dp0[x] %= mod;
            dp0[x] += dpr[x] * dpb[e];
            dp0[x] += dpb[x] * dpr[e];
            dp0[x] %= mod;
            r2 = r2 * dp0[e] + dpr[x] * dpr[e];
            r2 %= mod;
            b2 = b2 * dp0[e] + dpb[x] * dpb[e];
            b2 %= mod;
            dpr[x] *= dp0[e];
            dpr[x] %= mod;
            dpr[x] += v * dpr[e];
            dpr[x] %= mod;
            dpb[x] *= dp0[e];
            dpb[x] %= mod;
            dpb[x] += v * dpb[e];
            dpb[x] %= mod;
            done = true;
        }
    }
    lli v = dp0[x];
    dp0[x] = dpr[x] + dpb[x];
    dp0[x] %= mod;
    dpr[x] = v + r2;
    dpr[x] %= mod;
    dpb[x] = v + b2;
    dpb[x] %= mod;
    
}

int main() {
    usaco();
    int t;
    scd(t);
    frange(_, t) {int n;
        scd(n);
    
        graph = vvi(n+1);
    
        frange(i, n-1) {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }
    
        dp0 = dpb = dpr = vll(n+1);
    
        dfs(1, 0);
        printf("%lld\n", (dp0[1] + dpr[1] + dpb[1])%mod);}
} 