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

set<pii> field;
map<pii, bool> vis;
int v = 0;

void dfs(pii p)
{
    if (!field.count({p.f + 1, p.s}))
        v++;
    if (!field.count({p.f - 1, p.s}))
        v++;
    if (!field.count({p.f, p.s + 1}))
        v++;
    if (!field.count({p.f, p.s - 1}))
        v++;
    vis[p] = true;
    if (field.count({p.f + 1, p.s}) && !vis[{p.f + 1, p.s}])
        dfs({p.f + 1, p.s});
    if (field.count({p.f - 1, p.s}) && !vis[{p.f - 1, p.s}])
        dfs({p.f - 1, p.s});
    if (field.count({p.f, p.s + 1}) && !vis[{p.f, p.s + 1}])
        dfs({p.f, p.s + 1});
    if (field.count({p.f, p.s - 1}) && !vis[{p.f, p.s - 1}])
        dfs({p.f, p.s - 1});
}

int main()
{
    int r, c, n;
    scd(r);
    scd(c);
    scd(n);

    frange(i, n)
    {
        int a, b;
        scd(a);
        scd(b);
        field.insert({a, b});
    }
    int ma = 0;
    for (auto p : field)
    {
        if (!vis[p])
        {
            v = 0;
            dfs(p);
            ma = max(ma, v);
        }
    }
    printf("%d", ma);
}