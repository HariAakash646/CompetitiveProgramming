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

int n, m;
lli k;
vector<vector<pair<int, lli>>> graph;
vll cost, tax;
vll out;

void dfs(int x, lli tot, lli len, lli pre) {
    lli val = tot + (k-len) * cost[x];
    out[x] = val;
    for(auto e : graph[x]) {
        dfs(e.f, tot+tax[x], len+pre, e.s);
    }
}

int main() {
    // usaco();
    scd(n);
    scd(m);
    sclld(k);

    cost = tax = vll(n);

    frange(i, n) sclld(cost[i]);

    frange(i, n) sclld(tax[i]);

    graph = vector<vector<pair<int, lli>>>(n);

    frange(i, m) {
        int u, v;
        lli w;
        scd(u);
        scd(v);
        sclld(w);
        graph[v].pb(mp(u, w));
    }

    out = vll(n);
    dfs(0, 0, 0, 0);

    forr(i, 1, n) printf("%lld ", out[i]);
}