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

vll vec;
vvi graph;
vll dp;
vi st, en, depth;
vvi lift;
int timer=-1;

void dfs(int x, int p) {
    st[x] = ++timer;
    dp[x] = vec[x];
    depth[x] = depth[p] + 1;
    lift[0][x] = p;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
            dp[x] += dp[e];
        }
    } 
    en[x] = timer;
}

int binlift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) x = lift[i][x];
    }
    return x;
}

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);

    vec = vll(n+1);
    graph =vvi(n+1);

    forr(i, 1, n+1) sclld(vec[i]);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dp = vll(n+1);
    st = en = vi(n+1);
    lift = vvi(20, vi(n+1));
    depth = vi(n+1);
    dfs(1, 0);

    forr(i, 1, 20) {
        forr(j, 1, n+1) lift[i][j] = lift[i-1][lift[i-1][j]];
    }

    frange(_, q) {
        int p, x;
        scd(p);
        scd(x);
        if(p == x) printf("%lld\n", dp[1]);
        else {
            if(st[x] <= st[p] && st[p] <= en[x]) printf("%lld\n", dp[1] - dp[binlift(p, depth[p] - depth[x] - 1)]);
            else printf("%lld\n", dp[x]);
        }

    }
}