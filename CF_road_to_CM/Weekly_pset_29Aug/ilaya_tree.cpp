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

vvi graph;
vi vec;
vi val;
vi out;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void dfs(int x, int par, seti st)
{
    seti tmp;
    val[x] = gcd(vec[x], val[par]);
    out[x] = val[x];

    for (auto e : st)
    {
        int v = gcd(vec[x], e);
        tmp.insert(v);
        out[x] = max(out[x], v);
    }
    tmp.insert(val[par]);
    out[x] = max(out[x], val[par]);

    for (auto e : graph[x])
    {
        if (e != par)
            dfs(e, x, tmp);
    }
}

int main()
{
    int n;
    scd(n);

    graph = vvi(n + 1);
    vec = vi(n + 1);

    forr(i, 1, n + 1) scd(vec[i]);

    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    out = val = vi(n + 1);
    seti st;
    dfs(1, 0, st);

    forr(i, 1, n + 1) printf("%d ", out[i]);
}