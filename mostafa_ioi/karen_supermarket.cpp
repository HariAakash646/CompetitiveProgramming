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

vector<pair<lli, lli>> cost;
vvi graph;

vll combine(vll v1, vll v2) {
    vll out = vll(v1.size() + v2.size(), 1e17);
    frange(i, v1.size()) {
        frange(j, v2.size()) {
            out[i+j] = min(out[i+j], v1[i] + v2[j]);
        }
    }
    return out;
}

pair<vll, vll> dfs(int x) {
    vll dp0 = {0LL, cost[x].f};
    vll dp1 = {lli(1e17), cost[x].s};

    for(auto e : graph[x]) {
        pair<vll, vll> out = dfs(e);
        vll v0 = out.f;
        vll v1 = out.s;
        dp0 = combine(dp0, v0);
        dp1 = combine(dp1, v1);
    }

    frange(i, dp1.size()) {
        dp1[i] = min(dp1[i], dp0[i]);
    }
    return mp(dp0, dp1);
}

int main() {
    // usaco();
    int n; lli b;
    scd(n);
    sclld(b);

    graph = vvi(n+1);
    cost = vector<pair<lli, lli>>(n+1);

    sclld(cost[1].f);
    sclld(cost[1].s);
    cost[1].s = cost[1].f - cost[1].s;

    forr(i, 2, n+1) {
        sclld(cost[i].f);
        sclld(cost[i].s);
        cost[i].s = cost[i].f - cost[i].s;
        int p;
        scd(p);
        graph[p].pb(i);
    }

    vll out = dfs(1).s;

    int ma = 0;
    frange(i, out.size()) {
        if(out[i] <= b) ma = i;
    }
    printf("%d", ma);
}