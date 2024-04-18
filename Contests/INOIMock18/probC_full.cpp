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
vi dp;

mpii dfs(int x, int p) {
    dp[x] = 1e9;
    if(col[x]) {
        dp[x] = 1;
        mpii tmp;
        tmp[col[x]] = 1;        
        return tmp;
    }
    else {
        dp[x] = 0;
    }
    mpii val;
    for(auto e : graph[x]) {
        if(e != p) {
            mpii st = dfs(e, x);
            dp[x] += dp[e];

            if(val.size() < st.size()) swap(val, st);
            for(auto p : st) val[p.f] += p.s;
        }
    }

    int ma = 1;
    for(auto p : val) ma = max(ma, p.s);

    mpii val2;
    for(auto p : val) {
        if(p.s == ma) val2[p.f] = 1;
    }
    dp[x] += 1 - ma;

    return val2;
}

int main() {
    // usaco();
    scd(n);

    graph = vvi(n+1);

    forr(i, 2, n+1) {
        int a;
        scd(a);
        graph[i].pb(a);
        graph[a].pb(i);
    }

    col = vi(n+1);
    forr(i, 1, n+1) scd(col[i]);

    dp = vi(n+1);
    dfs(1, 0);

    printf("%d", dp[1]);

}