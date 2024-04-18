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
vi dp1, dp2, ma2, mv1, mv2;

void dfs1(int x, int p) {
    for(auto e : graph[x]) {
        if(e != p) {
            dfs1(e, x);
            if(dp1[e] + 1 > dp1[x]) {
                ma2[x] = dp1[x];
                mv2[x] = mv1[x];
                dp1[x] = dp1[e] + 1;
                mv1[x] = e;
            }
            else if(dp1[e] + 1 > ma2[x]) {
                ma2[x] = dp1[e] + 1;
                mv2[x] = e;
            }
        } 
    }
}

void dfs2(int x, int p) {
    if(p) {
        if(x != mv1[p])
            dp2[x] = max(dp2[p] + 1, dp1[p] + 1);
        else
            dp2[x] = max(dp2[p] + 1, ma2[p] + 1);
    }
    for(auto e : graph[x]) {
        if(e != p) dfs2(e, x);
    }
}

int main() {
    // usaco();
    int n;
    scd(n);

    graph = vvi(n+1);
    mv1 = mv2 = ma2 = dp1 = dp2 = vi(n+1);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dfs1(1, 0);
    dfs2(1, 0);

    forr(i, 1, n+1) printf("%d ", max(dp1[i], dp2[i]));

}