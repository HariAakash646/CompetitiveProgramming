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
vi col;
vi mid;
mpii mc;
vvi dp;

void dfs(int x, int p) {
    int k = mc.size();
    dp[x] = vi(k, 1e9);
    if(col[x]) {
        dp[x][mc[col[x]]] = 1;
        mid[x] = 1;
        return;
    }
    else {
        dp[x] = vi(k, 0);
    }
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
        }
    }

    for(auto pi : mc) {
        if(pi.f == 0) continue;
        for(auto e : graph[x]) {
            if(e != p) {
                dp[x][pi.s] += min(max(0, dp[e][pi.s]-1), mid[e]);
            }
        }
        dp[x][pi.s]++;
    }
    for(auto e : graph[x]) {
        if(e != p) {
            dp[x][0] += mid[e];
        }
    }
    mid[x] = *min_element(all(dp[x]));
    // printf("%d %d\n", x, mid[x]);
}

int main() {
    // usaco();
    scd(n);

    // graph = vvi(n+1);

    // seti val;

    forr(i, 2, n+1) {
        int a;
        scd(a);
        // graph[i].pb(a);
        // graph[a].pb(i);
    }
    // val.insert(0);
    // col = vi(n+1);
    // forr(i, 1, n+1) {scd(col[i]); val.insert(col[i]);};

    // int id = 0;
    // for(auto e : val) {
    //     mc[e] = id++;
    // }

    // dp = vvi(n+1);
    // mid = vi(n+1);
    // dfs(1, 0);

    // printf("%d", mid[1]);

    vi cnt(n+1);

    int c = n-1;
    forr(i, 1, n+1) {
        int a;
        scd(a);
        cnt[a]++;
    }
    int ma = 0;
    forr(i, 1, n+1) ma = max(ma, cnt[i]);
    c -= ma - 1;
    printf("%d", c);

}