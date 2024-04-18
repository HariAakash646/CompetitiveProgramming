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

lli mod = 998244353;

vvi graph;
vll dp1, dp2;

void dfs(int x, int p) {
    lli v = 0;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
            dp2[x] += dp2[e];
            dp2[x] %= mod;
            dp1[x] = dp1[x] * (dp1[e]+1) + dp1[e];
            v += dp1[e];
            v %= mod;
            dp1[x] %= mod;
        }
    }
    dp2[x] += v;
    dp1[x]++;
    dp2[x] %= mod;
    dp1[x] %= mod;
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        graph = vvi(n+1);
        dp1 = dp2 = vll(n+1);

        frange(i, n-1) {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }
        dfs(1, 0);
        printf("%lld\n", (dp1[1] + dp2[1] + 1)%mod);

    }
}