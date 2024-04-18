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

vi par;
vvi tree;

void dfs(int x, int pre)
{
    par[x] = pre;
    for (auto e : tree[x])
    {
        if (e != pre)
        {
            dfs(e, x);
        }
    }
}

int main()
{
    int n, q;
    scd(n);
    tree = vvi(n + 1);
    par = vi(n + 1);
    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        a++;
        b++;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    scd(q);
    int po = 0;
    while (1 << po <= n)
        po++;
    vvi vec(po, vi(n + 1, 0));
    dfs(1, 0);
    forr(i, 1, n + 1)
    {
        vec[0][i] = par[i];
    }
    forr(i, 1, po)
    {
        forr(j, 1, n + 1)
        {
            vec[i][j] = vec[i - 1][vec[i - 1][j]];
        }
    }
    frange(_, q)
    {
        int x, k;
        scd(x);
        scd(k);
        x++;
        int i = 0;
        while (k)
        {
            if (k % 2)
            {
                x = vec[i][x];
            }
            k /= 2;
            i++;
        }
        printf("%d\n", x - 1);
    }
}