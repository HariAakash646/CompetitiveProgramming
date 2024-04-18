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

int n;
vvi graph;
vll dp1, dp2, subsze;

void dfs1(int x, int p) {
    subsze[x] = 1;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs1(e, x);
            subsze[x] += subsze[e];
            dp1[x] += dp1[e] + subsze[e];
        } 
    }
}

void dfs2(int x, int p) {
    if(p) {
        dp2[x] = dp2[p] + (dp1[p] - (dp1[x] + subsze[x])) + (n - subsze[x]);
    }
    for(auto e : graph[x]) {
        if(e != p) dfs2(e, x);
    }
}

int main() {
    // usaco();
    
    scd(n);

    graph = vvi(n+1);
    subsze = dp1 = dp2 = vll(n+1);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dfs1(1, 0);
    dfs2(1, 0);

    forr(i, 1, n+1) printf("%lld ", dp1[i] + dp2[i]);

}