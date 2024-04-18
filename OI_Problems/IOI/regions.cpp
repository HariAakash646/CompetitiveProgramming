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

vvi reg, graph;
vi regi;
vi st, en;
int timer = 0;

void dfs(int x, int par, vll &vec)
{
    vec[regi[x]]++;
    for (auto e : graph[x])
    {
        if (e != par)
        {
            dfs(e, x, vec);
        }
    }
}

void euler(int x, int par)
{
    st[x] = ++timer;
    for (auto e : graph[x])
    {
        if (e != par)
        {
            euler(e, x);
        }
    }
    en[x] = timer;
}

int main()
{
    int n, r, q;
    scd(n);
    scd(r);
    scd(q);
    int x = 1000;
    reg = vvi(r + 1);
    regi = vi(n + 1);
    int h;
    scd(h);
    reg[h].pb(1);
    regi[1] = h;
    graph = vvi(n + 1);
    vi par(n + 1);

    forr(i, 2, n + 1)
    {
        int p, h;
        scd(p);
        scd(h);
        reg[h].pb(i);
        graph[i].pb(p);
        graph[p].pb(i);
        regi[i] = h;
        par[i] = p;
    }

    vector<vll> prec(r + 1);

    forr(i, 1, r + 1)
    {
        if (reg[i].size() < x)
        {
            vll out(n + 1);
            for (auto e : reg[i])
                dfs(e, par[e], out);
            prec[i] = out;
        }
    }
    st = en = vi(n + 1);
    vvi pos(r + 1);
    euler(1, 0);
    forr(i, 1, r + 1)
    {
        for (auto e : reg[i])
        {
            pos[i].pb(st[e]);
        }
        sort(all(pos[i]));
        // printf("%d\n", i);
        // for(auto e : pos[i]) printf("%d  ", e);
        // printf("\n");
    }

    frange(_, q)
    {
        int a, b;
        scd(a);
        scd(b);
        if (reg[a].size() < x)
        {
            printf("%lld\n", prec[a][b]);
            fflush(stdout);
        }
        else
        {
            lli tot = 0;
            for (auto e : reg[a])
            {
                tot += upper_bound(all(pos[b]), en[e]) - lower_bound(all(pos[b]), st[e]);
                // printf("%d %d %lld\n", st[e], en[e], tot);
            }
            printf("%lld\n", tot);
            fflush(stdout);
        }
    }
}