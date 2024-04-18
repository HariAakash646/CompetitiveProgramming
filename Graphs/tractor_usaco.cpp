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
typedef vector<vii> vvii;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

int n;
vvi grid;
int c = 1;

pii findf(pii x, vvii &disset)
{
    while (x != disset[x.f][x.s])
    {
        x = disset[x.f][x.s];
    }
    return x;
}

void unionf(pii x, pii y, vvii &disset, vvi &sze)
{
    x = findf(x, disset);
    y = findf(y, disset);
    if (x == y)
        return;
    if (sze[x.f][x.s] < sze[y.f][y.s])
        swap(x, y);
    disset[y.f][y.s] = x;
    sze[x.f][x.s] += sze[y.f][y.s];
    c = max(c, sze[x.f][x.s]);
}

// void dfs(pii x, int d, vvii &disset) {

// }

bool check(int d, vvi &grid)
{
    c = 1;
    vvii disset(n, vii(n));
    vvi sze(n, vi(n, 1));
    frange(i, n)
    {
        frange(j, n)
        {
            disset[i][j] = mp(i, j);
        }
    }
    frange(i, n)
    {
        frange(j, n)
        {
            if (i > 0 && abs(grid[i][j] - grid[i - 1][j]) <= d)
            {
                unionf(mp(i - 1, j), mp(i, j), disset, sze);
            }
            if (j > 0 && abs(grid[i][j] - grid[i][j - 1]) <= d)
            {
                unionf(mp(i, j - 1), mp(i, j), disset, sze);
            }
            if (i < n - 1 && abs(grid[i][j] - grid[i + 1][j]) <= d)
            {
                unionf(mp(i + 1, j), mp(i, j), disset, sze);
            }
            if (j < n - 1 && abs(grid[i][j] - grid[i][j + 1]) <= d)
            {
                unionf(mp(i, j + 1), mp(i, j), disset, sze);
            }
        }
    }
    if (c >= (n * n + 1) / 2)
        return true;
    else
        return false;
}

int main()
{
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);
    scd(n);
    grid = vvi(n, vi(n));
    frange(i, n)
    {
        frange(j, n)
        {
            scd(grid[i][j]);
        }
    }
    int hi = 1e6;
    int lo = 0;
    while (hi != lo)
    {
        int mid = (hi + lo) / 2;
        if (check(mid, grid))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    printf("%d", lo);
}