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
vi dp, dp2, diam1, diam2;

void dfs(int x, int p) {
    int mi1 = -1e9;
    int mi2 = -1e9;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
            if(dp[e] + 1 > mi1) {
                mi2 = mi1;
                mi1 = dp[e];
            }
            else mi2 = max(mi2, dp[e]);
            dp[x] = max(dp[x], dp[e]+1);
            diam1[x] = max(diam1[x], diam1[e]);
        }
    }
    diam1[x] = max(diam1[x], mi1 + mi2 + 2);
    diam1[x] = max(diam1[x], mi1 + 1);
}

void dfs2(int x, int p) {
    int v1 = -1e9;
    int i1 = -1;
    int v2 = -1e9;
    int i2 = -1;
    int v3 = -1e9;
    int i3 = -1;
    int md1 = -1e9;
    int id1;
    int md2 = -1e9;
    for(auto e : graph[x]) {
        if(e != p) {
            if(dp[e] + 1 > v1) {
                v3 = v2;
                v2 = v1;
                i2 = i1;
                v1 = dp[e]+1;
                i1 = e;
            }
            else if(dp[e] + 1 > v2) {
                v3 = v2;
                v2 = dp[e]+1;
                i2 = e;
            }
            else if(dp[e] + 1 > v3) {
                v3 = dp[e] + 1;
            }
            if(diam1[e] > md1) {
                md2 = md1;
                md1 = diam1[e];
                id1 = e;
            }
            else md2 = max(md2, diam1[e]);
        }
    }    
    if(dp2[x] + 1 > v1) {
        v3 = v2;
        v2 = v1;
        i2 = i1;
        v1 = dp2[x]+1;
        i1 = x;
    }
    else if(dp2[x] + 1 > v2) {
        v3 = v2;
        v2 = dp2[x]+1;
        i2 = x;
    }
    else if(dp2[x] + 1 > v3) {
        v3 = dp2[x] + 1;
    }
    if(diam2[x] > md1) {
        md2 = md1;
        md1 = diam2[x];
        id1 = x;
    }
    else md2 = max(md2, diam2[x]);

    for(auto e : graph[x]) {
        if(e != p) {
            if(e != i1 && e != i2) {
                dp2[e] = v1;
                diam2[e] = max(v1, v1 + v2);
            }
            else if(e == i1) {
                dp2[e] = v2;
                diam2[e] = max(v2, v2 + v3);
            }
            else if(e == i2) {
                dp2[e] = v1;
                diam2[e] = max(v1, v1 + v3);
            }
            if(e == id1) {
                diam2[e] = max(diam2[e], md2);
            }
            else diam2[e] = max(diam2[e], md1);

            dfs2(e, x);
        }
    }
}

int main() {
    // usaco();
    int n;
    scd(n);
    graph = vvi(n+1);

    frange(i, n-1) {
        int u, v;
        scd(u);
        scd(v);
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dp = vi(n+1);
    dp2 = vi(n+1, -1);

    diam1 = vi(n+1);
    diam2 = vi(n+1, -1);

    dfs(1, 0);
    dfs2(1, 0);
    int ma = 0;
    forr(i, 1, n+1) {
        // printf("%d %d\n", diam1[i], diam2[i]);
        ma = max(ma, diam1[i] + diam2[i] + 1);
    }
    printf("%d", ma);

}