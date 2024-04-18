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
vll dp1, dp2;
int n;
lli mod;

void dfs1(int x, int p) {
    for(auto e : graph[x]) {
        if(e != p) {
            dfs1(e, x);
            dp1[x] *= (dp1[e] + 1);
            dp1[x] %= mod;
        }
    }
}

void dfs2(int x, int p) {
    vll pref(graph[x].size()+2, 1);
    vll suff(graph[x].size()+2, 1);
    mpii id;
    mpii pos;
    int c = 1;
    for(auto e : graph[x]) {
        if(e != p) {
            id[c] = e;
            pos[e] = c;
            c++;
        }
    }
    // printf("%d %d\n", c, (int)graph[x].size());
    for(int i=c-1; i>=1; i--) {
        suff[i] = suff[i+1] * (dp1[id[i]] + 1);
        suff[i] %= mod;
    }
    forr(i, 1, graph[x].size()) {
        pref[i] = pref[i-1] * (dp1[id[i]]+1);
        pref[i] %= mod;
    }

    for(auto e : graph[x]) {
        if(e != p) {
            // printf("%d %lld\n", e, pref[pos[e]-1] * suff[pos[e]+1]);
            dp2[e] = ((pref[pos[e]-1] * suff[pos[e]+1]) % mod * dp2[x] + 1) % mod;
            // dp2[e] *= (dp2[x] + 1);
            dfs2(e, x);
        }
    }
}

int main() {
    // usaco();
    scd(n);
    sclld(mod);
    graph = vvi(n+1);
    frange(i, n-1) {
        int a, b;
        scd(a);scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dp1 = dp2 = vll(n+1, 1);
    dfs1(1, 0);
    dfs2(1, 0);

    forr(i, 1, n+1) {
        printf("%lld\n", dp1[i]* dp2[i]%mod);
    }

}