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
    int n, m;
    lli k;
    scd(n);
    scd(m);
    sclld(k);
    vector<vll> grid(n, vll(m));
    frange(i, n)
    {
        frange(j, m)
        {
            sclld(grid[i][j]);
        }
    }
    vector<vector<map<lli, lli>>> s1(n, vector<map<lli, lli>>(m)), s2(n, vector<map<lli, lli>>(m));
    int d1 = (n - 1 + m - 1 + 1) / 2;
    int d2 = (n - 1 + m - 1) / 2;

    frange(i, 1 << d1)
    {
        int y = 0;
        int x = 0;
        lli v = grid[y][x];
        bool done = true;
        frange(j, d1)
        {
            if (i & (1 << j))
                y++;
            else
                x++;
            if (y >= n || x >= m)
            {
                done = false;
                break;
            }
            v = (v ^ grid[y][x]);
        }
        if (done)
        {
            s1[y][x][v]++;
        }
    }
    frange(i, 1 << d2)
    {
        int y = n - 1;
        int x = m - 1;
        lli v = grid[y][x];
        bool done = true;
        frange(j, d2)
        {
            if (i & (1 << j))
                y--;
            else
                x--;
            if (y < 0 || x < 0)
            {
                done = false;
                break;
            }
            v = (v ^ grid[y][x]);
        }
        if (done)
        {
            s2[y][x][v]++;
        }
    }
    lli c = 0;
    frange(i, n)
    {
        frange(j, m)
        {
            for (auto e : s1[i][j])
            {
                c += lli(e.s) * s2[i][j][k ^ e.f ^ grid[i][j]];
            }
        }
    }
    printf("%lld", c);
}