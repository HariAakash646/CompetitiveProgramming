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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vs grid;
vector<vb> vis;

void floodfill(int x, int y, char curr, int l, int r, int t, int b)
{
    if (x < l || x > r)
        return;
    if (y < t || y > b)
        return;
    if (vis[x][y])
        return;

    if (grid[x][y] != curr)
        return;
    vis[x][y] = true;
    floodfill(x - 1, y, curr, l, r, t, b);
    floodfill(x + 1, y, curr, l, r, t, b);
    floodfill(x, y - 1, curr, l, r, t, b);
    floodfill(x, y + 1, curr, l, r, t, b);
}

int main()
{
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    int n;
    cin >> n;
    grid = vs(n);
    frange(i, n)
    {
        cin >> grid[i];
    }
    vector<pair<pii, pii>> val;
    frange(i, n)
    {
        frange(j, n)
        {
            forr(k, i, n)
            {
                forr(l, j, n)
                {
                    if (i == k && j == l)
                        continue;
                    vis = vector<vb>(n, vb(n, false));
                    vi vec(26);
                    forr(i1, i, k + 1)
                    {
                        forr(j1, j, l + 1)
                        {
                            if (!vis[i1][j1])
                            {
                                floodfill(i1, j1, grid[i1][j1], i, k, j, l);
                                vec[grid[i1][j1] - 'A']++;
                            }
                        }
                    }
                    sort(all(vec));
                    if (vec[25] >= 2 && vec[24] == 1 && vec[23] == 0)
                    {
                        val.pb({{i, j}, {k, l}});
                    }
                }
            }
        }
    }
    int cn = 0;
    frange(i, val.size())
    {
        auto p1 = val[i];
        bool sep = true;
        frange(j, val.size())
        {
            auto p2 = val[j];
            if (i == j)
                continue;
            if ((p1.f.f >= p2.f.f) && (p1.f.s >= p2.f.s) && (p1.s.f <= p2.s.f) && (p1.s.s <= p2.s.s))
            {
                sep = false;
                break;
            }
        }
        if (sep)
        {
            cn++;
            // printf("%d %d %d %d\n", p1.f.f, p1.f.s, p1.s.f, p1.s.s);
        }
    }
    printf("%d", cn);
}