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

lli mod = 998244353;

vector<vii> graph;
vll dp0, dp1, inv;

int co = 0;
lli tot = 0;

void dfs(int x, int v)
{
    if (v)
        dp1[x]++;
    else
        dp0[x]++;
    for (auto e : graph[x])
    {
        dfs(e.f, e.s);
        inv[x] += inv[e.f];
        if (v)
        {
            inv[x] += dp0[e.f];
        }
        dp0[x] += dp0[e.f];
        dp1[x] += dp1[e.f];
        inv[x] %= mod;
        dp0[x] %= mod;
        dp1[x] %= mod;
    }
    // if (v)
    //     dp1[x]--;
    // else
    //     dp0[x]--;
}

int main()
{
    int n;
    scd(n);
    graph = vector<vii>(n + 1);

    forr(i, 1, n + 1)
    {
        int c;
        scd(c);
        frange(j, c)
        {
            int v, w;
            scd(v);
            scd(w);
            graph[i].pb(mp(v, w));
        }
    }
    dp0 = dp1 = inv = vll(n + 1);
    dfs(1, 0);

    printf("%lld", inv[1]);
}