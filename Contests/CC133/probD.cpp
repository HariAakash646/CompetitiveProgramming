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
vi dep1, dep2, dep3, dp;

void dfs(int x, int p) {
    dep1[x] = 1;
    dep2[x] = 1;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
            if(dep1[e]+1>dep1[x]) {
                dep2[x] = dep1[x];
                dep1[x] = dep1[e]+1;
            }
            else {
                dep2[x] = max(dep2[x], dep1[e]+1);
            }
        }
    }
}

void dfs2(int x, int p) {
    
    dep3[x] = dep3[p] + 1;
    if(dep1[p] == dep1[x]+1) {
        dep3[x] = max(dep3[x], dep2[p]+1);
    }
    else {
        dep3[x] = max(dep3[x], dep1[p]+1);
    }

    
    dp[x] = 1;
    for(auto e : graph[x]) {
        if(e != p) dp[x] += dep1[e];
        else dp[x] += dep3[e];
    }
    
    for(auto e : graph[x]) {
        if(e != p) dfs2(e, x);
    }
    
}

int main() {
    usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        graph = vvi(n+1);
        dep1 = dep3 = dep2 = dp = vi(n+1);

        frange(i, n-1) {
            int u, v;
            scd(u);
            scd(v);
            graph[u].pb(v);
            graph[v].pb(u);
        }

        dfs(1, 0);
        dfs2(1, 0);

        forr(i, 1, n+1) {
            printf("%d ", dp[i]);
        }
        printf("\n");
    }
}