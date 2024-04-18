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

vvi tree;
vi vec;
int n, m;
int tot = 0;
vb vis;
void dfs(int node, int prev, int c)
{
    if (c > m)
    {
        return;
    }
    if (tree[node].size() == 1 && prev != -1)
    {
        tot++;
    }
    for (auto e : tree[node])
    {
        if (e == prev)
            continue;
        if (vec[e] == 1)
        {
            dfs(e, node, c + 1);
        }
        else
        {
            dfs(e, node, 0);
        }
    }
}

int main()
{

    scd(n);
    scd(m);
    vec = vi(n + 1);
    frange(i, n)
    {
        scd(vec[i + 1]);
    }
    tree = vvi(n + 1);
    vis = vb(n + 1);
    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        tree[a].pb(b);
        tree[b].pb(a);
    }
    dfs(1, -1, vec[1]);
    printf("%d", tot);
}