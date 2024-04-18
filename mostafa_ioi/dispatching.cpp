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

lli m;
vvi graph;
vll lead, cost;
lli ma = 0;
vector<multiset<lli>> val;

lli dfs(int x) {
    lli tot = 0;
    val[x].insert(cost[x]);
    tot += cost[x];
    for(auto e : graph[x]) {
        tot += dfs(e);
        if(val[e].size() > val[x].size()) swap(val[x], val[e]);
        for(auto v : val[e]) val[x].insert(v);
    }
    while(tot > m) {
        tot -= *prev(val[x].end());
        val[x].erase(prev(val[x].end()));
    }
    // printf("%d %d %lld\n", x, (int)val[x].size(), tot);
    // for(auto e : val[x]) printf("%d\n", e);
    ma = max(ma, lead[x] * (lli)val[x].size());
    return tot;
} 


int main() {
    // usaco();
    int n;
    scd(n);
    sclld(m);

    graph = vvi(n+1);

    lead = cost = vll(n+1);

    forr(i, 1, n+1) {
        int p;
        scd(p);
        sclld(cost[i]);
        sclld(lead[i]);
        if(p != 0) graph[p].pb(i);
    }

    val = vector<multiset<lli>>(n+1);

    dfs(1);
    printf("%lld", ma);
}