#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long long int lli;

vi rightv;
vi down;
vs grid;
vector<vb> vis;
vector<vii> vispair;
vi rval, lval;
int n, q;

pair<bool, pii> dfs(int x, int y)
{
    if (x == n)
        return {true, {0, y}};
    if (y == n)
        return {false, {0, x}};
    vis[y][x] = true;
    if (grid[y][x] == 'R')
    {
        if (vis[y][x + 1])
        {
            vispair[y][x] = vispair[y][x + 1];
            if (vispair[y][x].s)
            {
                rval[vispair[y][x].f]++;
            }
            else
            {
                lval[vispair[y][x].f]++;
            }
        }
        auto out = dfs(x + 1, y);
        vispair[y][x] = {out.s.s, out.f};
        if (out.f)
        {
            rval[out.s.s] += out.s.f + 1;
        }
        else
        {
            lval[out.s.s] += out.s.f + 1;
        }
        return {out.f, {out.s.f + 1, out.s.s}};
    }
    if (grid[y][x] == 'D')
    {
        if (vis[y + 1][x])
        {
            vispair[y][x] = vispair[y + 1][x];
            if (vispair[y][x].s)
            {
                rval[vispair[y][x].f]++;
            }
            else
            {
                lval[vispair[y][x].f]++;
            }
        }
        auto out = dfs(x, y + 1);
        vispair[y][x] = {out.s.s, out.f};
        if (out.f)
        {
            rval[out.s.s] += out.s.f + 1;
        }
        else
        {
            lval[out.s.s] += out.s.f + 1;
        }
        return {out.f, {out.s.f + 1, out.s.s}};
    }
    return {false, {0, 0}};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    rightv = vi(n);
    down = vi(n);
    rval = vi(n);
    lval = vi(n);
    grid = vs(n);
    frange(i, n)
    {
        string str;
        int c;
        cin >> grid[i] >> rightv[i];
    }
    frange(i, n)
    {
        cin >> down[i];
    }
    vis = vector<vb>(n + 1, vb(n + 1, false));
    vispair = vector<vii>(n + 1, vii(n + 1));
    int tot = 0;
    frange(i, n)
    {
        frange(j, n)
        {
            if (!vis[i][j])
            {
                auto p = dfs(i, j);
            }
            printf("%d ", vispair[i][j].f);
        }
        printf("\n");
    }
    frange(i, n)
    {
        tot += rightv[i] * rval[i];
        tot += down[i] * lval[i];
    }
    printf("%d\n", tot);
    cin >> q;
    frange(_, q)
    {
        vis = vector<vb>(n + 1, vb(n + 1, false));
        vispair = vector<vii>(n + 1, vii(n + 1));
        int tot = 0;
        int x, y;
        cin >> y >> x;
        grid[y - 1][x - 1] = (grid[y - 1][x - 1] == 'R') ? 'D' : 'R';
        frange(i, n)
        {
            frange(j, n)
            {
                if (!vis[i][j])
                {
                    auto p = dfs(i, j);
                }
            }
        }
        printf("%d\n", tot);
    }
}