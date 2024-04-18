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

int n, m;

vector<vii> grid;
vector<vb> vis;
vii dir = {mp(0, -1), mp(0, 1), mp(-1, 0), mp(1, 0)};

void dfs(int x, int y)
{
    if (x >= n || y >= m || x < 0 || y < 0)
    {
        printf("OUT");
        return;
    }
    if (grid[x][y].f == 0)
    {
        printf("HALT");
        return;
    }
    if (vis[x][y])
    {
        printf("LOOP");
        return;
    }
    vis[x][y] = true;
    dfs(x + grid[x][y].f * dir[grid[x][y].s].f, y + grid[x][y].f * dir[grid[x][y].s].s);
}

int main()
{

    cin >> n >> m;
    grid = vector<vii>(n, vii(m));
    vis = vector<vb>(n, vb(m));

    frange(i, n)
    {
        frange(j, m)
        {
            cin >> grid[i][j].f;
        }
    }

    frange(i, n)
    {
        string row;
        cin >> row;
        frange(j, m)
        {
            if (row[j] == 'L')
                grid[i][j].s = 0;
            if (row[j] == 'R')
                grid[i][j].s = 1;
            if (row[j] == 'U')
                grid[i][j].s = 2;
            if (row[j] == 'D')
                grid[i][j].s = 3;
        }
    }
    dfs(0, 0);
}
