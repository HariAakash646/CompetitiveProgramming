#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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

vector<set<pii>> tree;
vvi treedf;
vll imp;
vi par;
vi subsz;
vll subimp;

void dfs(int x, int pre)
{
    subimp[x] = imp[x];
    for (auto e : treedf[x])
    {
        if (e != pre)
        {
            dfs(e, x);
            subsz[x] += subsz[e];
            subimp[x] += subimp[e];
        }
        else
        {
            par[x] = e;
            continue;
        }
    }
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    imp = vll(n + 1);
    tree = vector<set<pii>>(n + 1);
    treedf = vvi(n + 1);
    forr(i, 1, n + 1)
    {
        sclld(imp[i]);
    }
    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        treedf[a].pb(b);
        treedf[b].pb(a);
    }
    par = vi(n + 1);
    subsz = vi(n + 1, 1);
    subimp = vll(n + 1);
    dfs(1, 0);
    forr(i, 1, n + 1)
    {
        for (auto e : treedf[i])
        {
            if (par[i] == e)
                tree[i].insert(mp(0, e));
            else
                tree[i].insert(mp(-subsz[e], e));
        }
    }
    frange(i, m)
    {
        int typ, x;
        scd(typ);
        scd(x);
        if (typ == 1)
        {
            printf("%lld\n", subimp[x]);
        }
        else
        {
            if (tree[x].size() <= 1)
                continue;
            auto itr = tree[x].begin();
            int sz = -((*itr).f);
            int c = (*itr).s;
            tree[par[x]].erase(mp(-subsz[x], x));
            subsz[x] -= subsz[c];
            subimp[x] -= subimp[c];
            tree[x].erase(itr);
            tree[x].erase(mp(0, par[x]));
            tree[x].insert(mp(0, c));
            subsz[c] += subsz[x];
            subimp[c] += subimp[x];
            tree[par[x]].insert(mp(-subsz[c], c));
            tree[c].insert(mp(0, par[x]));
        }
    }
}