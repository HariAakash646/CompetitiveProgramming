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

vvi grid;
vector<vb> vis;
vector<vb> reach;

int n, m;

bool check(int x, int y)
{
    int c = 0;
    if (grid[x][y])
        return false;
    if (x + 1 <= n && !(reach[x + 1][y] || grid[x + 1][y]))
        c++;
    if (x - 1 >= 1 && !(reach[x - 1][y] || grid[x - 1][y]))
        c++;
    if (y + 1 <= m && !(reach[x][y + 1] || grid[x][y + 1]))
        c++;
    if (y - 1 >= 1 && !(reach[x][y - 1] || grid[x][y - 1]))
        c++;
    if (c <= 1)
        return true;
    else
        return false;
}

void dfs(int x, int y)
{
    if (vis[x][y])
        return;
    vis[x][y] = true;
    if (check(x + 1, y))
    {
        reach[x + 1][y] = true;
        dfs(x + 1, y);
    }
    if (check(x - 1, y))
    {
        reach[x - 1][y] = true;
        dfs(x - 1, y);
    }
    if (check(x, y + 1))
    {
        reach[x][y + 1] = true;
        dfs(x, y + 1);
    }
    if (check(x, y - 1))
    {
        reach[x][y - 1] = true;
        dfs(x, y - 1);
    }
}

int main()
{
    int t;
    cin >> t;
    frange(_, t)
    {

        cin >> n >> m;
        grid = vvi(n + 2, vi(m + 2, 1));
        pii lab;
        forr(i, 1, n + 1)
        {
            string row;
            cin >> row;
            forr(j, 1, m + 1)
            {
                if (row[j - 1] == 'L')
                {
                    grid[i][j] = 1;
                    lab = {i, j};
                }
                else if (row[j - 1] == '.')
                    grid[i][j] = 0;
            }
        }
        reach = vis = vector<vb>(n + 2, vb(m + 2));
        dfs(lab.f, lab.s);
        forr(i, 1, n + 1)
        {
            forr(j, 1, m + 1)
            {
                if (lab == mp(i, j))
                    cout << "L";
                else if (grid[i][j])
                    cout << "#";
                else
                {

                    if (reach[i][j])
                        cout << '+';
                    else
                        cout << '.';
                }
            }
            cout << "\n";
        }
    }
}