#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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

int n;

vvi graph;
vll val;
vll dp1, dp2;
vll sub;

void dfs(int x, int p) {
    sub[x] = 1;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
            sub[x] += sub[e];
            dp1[x] += dp1[e];
            dp1[x] += sub[e] * (val[x] ^ val[e]);
        }
    }
}

void dfs2(int x, int p) {
    if(p != 0) {   
        dp2[x] += (dp1[p] - (dp1[x] + sub[x] * (val[p] ^ val[x])));
        // dp2[x] += (sub[p] - sub[x]) * (val[x] ^ val[p]);
        dp2[x] += dp2[p];
        dp2[x] += (n - sub[x]) * (val[p] ^ val[x]);
    }
    for(auto e : graph[x]) {
        if(e != p) {
            dfs2(e, x);
        }
    }
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        scd(n);
        graph = vvi(n+1);

        sub = val = dp1 = dp2 = vll(n+1);

        forr(i, 1, n+1) sclld(val[i]);

        frange(i, n-1) {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }
        dfs(1, 0);
        dfs2(1, 0);

        forr(i, 1, n+1) {
            printf("%lld ", dp1[i] + dp2[i]);
        }
        printf("\n");

    }
}