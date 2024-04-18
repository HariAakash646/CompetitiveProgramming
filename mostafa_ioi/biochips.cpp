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
vi val;
vvi dp;
vi st, en;
vi order;
int timer = 1;

void dfs(int x, int p) {
    if(graph[x].size() == 0) timer++;
    st[x] = timer;
    for(auto e : graph[x]) {
            dfs(e, x);
        
    }
    en[x] = timer;
    order.pb(x);
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);
    graph = vvi(n+1);
    st = en = val = vi(n+1);
    
    int r = 0;

    forr(i, 1, n+1) {
        int p, v;
        scd(p);
        scd(v);
        val[i] = v;
        if(p == 0) {r = i; continue;}
        graph[p].pb(i);
    }

    dfs(r, 0);

    dp = vvi(timer+1, vi(m+1));

    

    for(auto e : order) {
        int l = st[e];
        int r = en[e];
        dp[r][0] = 0;
        frange(j, m+1) {
            dp[r][j] = max(dp[r][j], dp[r-1][j]); 
        }
        forr(j, 1, min(l,m)+1) {
            dp[r][j] = max(dp[r][j], dp[l - (l==r)][j-1] + val[e]);
        }
        // printf("%d %d %d %d\n", l, r, e, dp[r][m]);
    }
    int ma = 0;
    frange(i, timer+1) ma = max(ma, dp[i][m]);
    printf("%d", ma);
}