// Unsolved. Small bugs.
#include <bits/stdc++.h>
#include <iostream>

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
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vvi tree;
vi wealth;

pii dfs(int node)
{
    int ma = wealth[node];
    int mi = wealth[node];
    int mga = ma;
    int mgi = mi;
    for (auto e : tree[node])
    {
        int a, b;
        tie(a, b) = dfs(e);
        if (a - b > ma - mi)
        {
            ma = max(mga, a);
            mi = b;
        }
        else if (mga - b > ma - mi)
        {
            ma = mga;
            mi = b;
        }
    }
    return {ma, mi};
}

int main()
{
    int n;
    scd(n);
    tree = vvi(n + 1);
    wealth = vi(n + 1);
    forr(i, 1, n + 1) scd(wealth[i]);
    int a;
    int boss;
    forr(i, 1, n + 1)
    {
        scd(a);
        if (a == -1)
        {
            boss = i;
            continue;
        }
        tree[a].pb(i);
    }
    pii out = dfs(boss);
    printf("%d", out.f - out.s);
}