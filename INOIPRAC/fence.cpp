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
typedef vector<bool> vb;
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

int rm, cm, n;
vvi grid;
vector<vb> vis;
vector<vb> sub;
int tot;

void floodfill(int r, int c)
{
    if (vis[r][c])
        return;
    vis[r][c] = true;
    if (!grid[r][c])
        return;
    tot += 4;
    if (r - 1 >= 0)
    {
        floodfill(r - 1, c);
        if (grid[r - 1][c])
            --tot;
    }
    if (c - 1 >= 0)
    {

        floodfill(r, c - 1);
        if (grid[r][c - 1])
            --tot;
    }
    if (c + 1 < cm)
    {
        floodfill(r, c + 1);
        if (grid[r][c + 1])
            --tot;
    }
    if (r + 1 < rm)
    {
        floodfill(r + 1, c);
        if (grid[r + 1][c])
            --tot;
    }
}

int main()
{
    scd(rm);
    scd(cm);
    scd(n);
    grid = vvi(rm, vi(cm, 0));
    vis = vector<vb>(rm, vb(cm, false));
    sub = vector<vb>(rm, vb(cm, false));
    int a, b;
    frange(i, n)
    {
        scd(a);
        scd(b);
        grid[a - 1][b - 1] = 1;
    }
    int mt = 0;
    frange(i, rm)
    {
        frange(j, cm)
        {
            if (!vis[i][j] && grid[i][j])
            {
                tot = 0;
                floodfill(i, j);
                mt = max(tot, mt);
            }
        }
    }
    printf("%d", mt);
}