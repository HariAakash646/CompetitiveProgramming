// Not wokring
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

int main()
{
    // freopen("lightson.in", "r", stdin);
    // freopen("lightson.out", "w", stdout);
    int n, m;
    scd(n);
    scd(m);
    vector<vector<pair<int, vii>>> grid(n, vector<pair<int, vii>>(n));
    vector<vb> vis(n, vb(n));
    frange(i, m)
    {
        int x, y, a, b;
        scd(x);
        scd(y);
        scd(a);
        scd(b);
        x--;
        y--;
        a--;
        b--;
        grid[x][y].s.pb({a, b});
    }
    queue<pii> q;
    grid[0][0].f = 1;
    q.push({0, 0});
    int c = 0;
    while (q.size())
    {

        auto p = q.front();
        q.pop();
        if (vis[p.f][p.s])
            continue;
        vis[p.f][p.s] = true;
        printf("%d %d\n", p.f, p.s);
        c++;
        for (auto coor : grid[p.f][p.s].s)
        {
            // pii coor = grid[p.f][p.s].s;
            // if (grid[coor.f][coor.s].f)
            //     continue;
            grid[coor.f][coor.s].f = 1;
            if ((coor.f > 0 && vis[coor.f - 1][coor.s]) || (coor.s > 0 && vis[coor.f][coor.s - 1]) || (coor.f < n - 1 && vis[coor.f + 1][coor.s]) || (coor.s < n - 1 && vis[coor.f][coor.s + 1]))
            {
                q.push(coor);
            }
        }
        if (p.f > 0 && grid[p.f - 1][p.s].f)
        {
            q.push({p.f - 1, p.s});
        }
        if (p.s > 0 && grid[p.f][p.s - 1].f)
        {
            q.push({p.f, p.s - 1});
        }
        if (p.f < n - 1 && grid[p.f + 1][p.s].f)
        {
            q.push({p.f + 1, p.s});
        }
        if (p.s < n - 1 && grid[p.f][p.s + 1].f)
        {
            q.push({p.f, p.s + 1});
        }
    }
    printf("%d", c);
}