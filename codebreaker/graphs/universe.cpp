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
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int n, k;
vvi tree;
vi cats;
int c = 0;

void dfs(int x, int prev, int curr, int ma)
{
    if (cats[x])
    {
        curr++;
        ma = max(ma, curr);
    }
    else
    {
        curr = 0;
    }
    int ch = 0;
    for (auto e : tree[x])
    {
        if (e != prev)
        {
            dfs(e, x, curr, ma);
            ch++;
        }
    }
    if (!ch)
    {
        if (ma <= k)
            c++;
    }
}

int main()
{

    scd(n);
    scd(k);
    tree = vvi(n + 1);
    cats = vi(n + 1);
    forr(i, 1, n + 1) scd(cats[i]);

    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        tree[a].pb(b);
        tree[b].pb(a);
    }

    dfs(1, 0, 0, 0);
    printf("%d", c);
}