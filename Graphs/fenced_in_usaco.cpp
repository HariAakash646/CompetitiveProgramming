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

int n, m;

int coord(int x, int y)
{
    return y * (n + 1) + x;
}

vi disset, sze;

int findf(int x)
{
    while (x != disset[x])
    {
        x = disset[x];
    }
    return x;
}

void unionf(int x, int y)
{
    x = findf(x);
    y = findf(y);
    if (x == y)
        return;
    if (sze[x] < sze[y])
    {
        swap(x, y);
    }
    disset[y] = x;
    sze[x] = max(sze[x], sze[y] + 1);
}

struct farm
{
    int stx, sty, enx, eny;
};

int main()
{
    // freopen("fencedin.in", "r", stdin);
    // freopen("fencedin.out", "w", stdout);
    int a, b;
    scd(a);
    scd(b);
    scd(n);
    scd(m);

    vi vert(n + 2), hori(m + 2);
    vert[n + 1] = a;
    hori[m + 1] = b;
    frange(i, n) scd(vert[i + 1]);
    frange(i, m) scd(hori[i + 1]);

    sort(all(vert));
    sort(all(hori));

    vector<vector<farm>> grid(n + 1, vector<farm>(m + 1));

    frange(i, n + 1)
    {
        frange(j, m + 1)
        {
            grid[i][j].stx = vert[i];
            grid[i][j].sty = hori[j];
            grid[i][j].enx = vert[i + 1];
            grid[i][j].eny = hori[j + 1];
        }
    }

    disset = sze = vi((n + 1) * (m + 1));
    frange(i, (n + 1) * (m + 1)) disset[i] = i;

    vector<pair<lli, pii>> edges;

    frange(i, n + 1)
    {
        frange(j, m + 1)
        {
            if (i + 1 <= n)
            {
                edges.pb(mp(lli(grid[i][j].eny - grid[i][j].sty), mp(coord(i, j), coord(i + 1, j))));
            }
            if (j + 1 <= m)
            {
                edges.pb(mp(lli(grid[i][j].enx - grid[i][j].stx), mp(coord(i, j), coord(i, j + 1))));
            }
            if (i - 1 >= 0)
            {
                edges.pb(mp(lli(grid[i][j].eny - grid[i][j].sty), mp(coord(i, j), coord(i - 1, j))));
            }
            if (j - 1 >= 0)
            {
                edges.pb(mp(lli(grid[i][j].enx - grid[i][j].stx), mp(coord(i, j), coord(i, j - 1))));
            }
        }
    }
    sort(all(edges));

    lli tot = 0;

    for (auto p : edges)
    {
        if (findf(p.s.f) != findf(p.s.s))
        {
            unionf(p.s.f, p.s.s);
            tot += p.f;
        }
    }
    printf("%lld", tot);
}