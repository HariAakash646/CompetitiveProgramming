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
vll dp, dp2, dp3;

void dfs(int x, int p) {
    vll st;

    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
            st.pb(dp[e]);
        }
    }

    sort(all(st), greater<>());

    dp[x] = dp2[x] = vec[x];
    lli v = 0;
    frange(i, st.size()) {
        v += st[i];
        dp[x] = max(dp[x], v + vec[x] * ((i+2) != 2));
        dp2[x] = max(dp2[x], v + vec[x] *((i+1) != 2));
    }
}


int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);

        vec = vll(n+1);

        forr(i, 1, n+1) sclld(vec[i]);

        graph = vvi(n+1);

        frange(i, n-1) {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }
        dp = dp2 = vll(n+1, -1e18);
        dfs(1, 0);
        lli ans = max(0LL, *max_element(all(dp2)));

        printf("%lld\n", ans);
    }
}