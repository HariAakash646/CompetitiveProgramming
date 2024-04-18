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
vi cnt;
vll dp;
vi vec;

void dfs(int x, int p) {
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
            dp[x] += dp[e] + abs(cnt[e]);
            cnt[x] += cnt[e];
        }
    }
    cnt[x] += vec[x] - 1;
}

int main() {
    // usaco();
    int n;
    scd(n);

    vec = vi(n);
    graph = vvi(n);
    int root;
    frange(i, n) {
        int p;
        scd(p);
        scd(vec[i]);
        if(p == -1) root = i;
        else {
            graph[i].pb(p);
            graph[p].pb(i);
        }
    }


    dp = vll(n);
    cnt= vi(n);

    dfs(root, -1);

    printf("%lld", dp[root]);


}