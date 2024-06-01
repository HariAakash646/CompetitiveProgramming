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
vvi dp1, dp2;

void dfs(int x, int p) {
    dp1[x] = vi(1);
    dp2[x] = vi(1);
    for(auto e : graph[x]) {
        if(e == p) continue;
        dfs(e, x);
        vi tmp(dp1[x].size() + dp1[e].size());
        forr(i, 0, dp1[x].size()) {
            forr(j, 0, dp1[e].size()) {
                tmp[i+j] = max(tmp[i+j], dp1[x][i] + dp1[e][j]);
                tmp[i+j] = max(tmp[i+j], dp1[x][i] + dp2[e][j] + 1);
            }
        }
        dp1[x] = tmp;
        tmp = vi(dp2[x].size() + dp1[e].size());
        forr(i, 0, dp2[x].size()) {
            forr(j, 0, dp1[e].size()) {
                tmp[i+j] = max(tmp[i+j], dp2[x][i] + dp1[e][j]);
                tmp[i+j] = max(tmp[i+j], dp2[x][i] + dp2[e][j]);
            }
        }
        dp2[x] = tmp;
    }
    dp1[x].pb(0);
    dp2[x].pb(0);

    for(int i=dp2[x].size()-2; i>=0; i--) {
        dp2[x][i+1] = dp2[x][i] + (int)graph[x].size() - (p!=0);
    }
    dp2[x][0] = -1e9;
}

int main() {
    // usaco();
    int n, k;
    scd(n);
    scd(k);

    graph = vvi(n+1);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dp1 = dp2 = vvi(n+1);
    dfs(1, 0);

    frange(i, dp1[1].size()) {
        // printf("%d %d\n", dp1[1][i], dp2[1][i]);
        if(dp1[1][i] >= k) {
            printf("%d", i);
            return 0;
        }
        if(dp2[1][i] >= k) {
            printf("%d", i);
            return 0;
        }
    }
}