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
vi dp1, dp2, diam1, diam2;

int ma = 0;

void dfs(int x, int p) {
    int v1 = -1e9;
    int v2 = -1e9;

    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
            if(dp1[e] + 1 > v1) {
                v2 = v1;
                v1 = dp1[e]+1;
            }
            else {
                v2 = max(v2, dp1[e]+1);
            }
            dp1[x] = max(dp1[x], dp1[e]+1);
            diam1[x] = max(diam1[x], diam1[e]);
        }
    }

    diam1[x] = max(diam1[x], v1 + v2);
    diam1[x] = max(diam1[x], v1);
}

void dfs2(int x, int p) {
    int v1 = -1e9;
    int i1 = -1;
    int v2 = -1e9;
    int i2 = -1;
    int v3 = -1e9;
    int md1 = -1e9;
    int mi = -1;
    int md2 = -1e9;

    for(auto e : graph[x]) {
        if(e != p) {
            if(dp1[e]+1 > v1) {
                v3 = v2;
                v2 = v1;
                i2 = i1;
                v1 = dp1[e]+1;
                i1 = e;
            }
            else if(dp1[e] + 1 > v2) {
                v3 = v2;
                v2 = dp1[e]+1;
                i2 = e;
            }
            else {
                v3 = max(v3, dp1[e]+1);
            }
            if(diam1[e] > md1) {
                md2 = md1;
                md1 = diam1[e];
                mi = e;
            }
            else {
                md2 = max(md2, diam1[e]);
            }
        }
    }
    if(dp2[x] + 1 > v1) {
        v3 = v2;
        v2 = v1;
        i2 = i1;
        v1 = dp2[x]+1;
        i1 = p;
    }
    else if(dp2[x] + 1 > v2) {
        v3 = v2;
        v2 = dp2[x]+1;
        i2 = p;
    }
    else v3 = max(v3, dp2[x]+1);

    if(diam2[x] > md1) {
        md2 = md1;
        md1 = diam2[x];
        mi = x;
    }
    else md2 = max(md2, diam2[x]);

    for(auto e : graph[x]) {
        if(e != p) {
            if(e != i1) {
                dp2[e] = v1;
                if(e != i2) diam2[e] = v1 + v2;
                else diam2[e] = v1 + v3;
            }
            else {
                dp2[e] = v2;
                diam2[e] = v2 + v3;
            }
            if(e != mi) {
                diam2[e] = max(md1, diam2[e]);
            }
            else diam2[e] = max(md2, diam2[e]);
            dfs2(e, x);
        }
    }
}

// vi dist;

// void dfs2(int x, int p) {
//     dist[x] = dist[p] + 1;
//     for(auto e : graph[x]) {
//         if(e != p) dfs2(e, x);
//     }
// }

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

    diam1 = dp1 = vi(n+1);
    diam2 = dp2 = vi(n+1, -1);

    dfs(1, 0);
    dfs2(1, 0);

    forr(i, 1, n+1) {
        ma = max(ma, diam1[i] + diam2[i] + 1);
    }
    printf("%d", ma);
}
