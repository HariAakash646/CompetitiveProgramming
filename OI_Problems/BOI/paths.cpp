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

int n, m, k;
vvi graph;
vi col;
vector<vll> dp;
vector<vb> vis;
lli tot = 0;

lli dfs(int x, int v) {
    if(vis[v][x]) return dp[v][x];
    vis[v][x] = true;
    if(!(v&(1<<col[x]))) {
        dp[v][x] = 0;
        return 0;
    }
    int v1 = v ^ (1<<col[x]);
    if(v1 == 0) {
        dp[v][x] = 1;
        return 1;
    }
    for(auto e : graph[x]) {
        dp[v][x] += dfs(e, v1);
    }
    return dp[v][x];
}

int main() {
    // usaco();
    scd(n);
    scd(m);
    scd(k);

    graph = vvi(n+1);
    col = vi(n+1);
    forr(i, 1, n+1) {
        scd(col[i]);
        col[i]--;
    }

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dp = vector<vll>(1<<k, vll(n+1));
    vis = vector<vb>(1<<k, vb(n+1));

    frange(i, 1<<k) {
        forr(j, 1, n+1) {
            tot += dfs(j, i);
        }
    }
    printf("%lld", tot-n);
}