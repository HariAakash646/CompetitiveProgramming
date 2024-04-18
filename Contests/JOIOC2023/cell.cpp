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

int main()
{
    int n, q;
    scd(n);
    scd(q);

    vvi grid(4001, vi(4001));

    vii black, grey;

    frange(i, n)
    {
        int x, y;
        scd(x);
        scd(y);
        x += 2000;
        y += 2000;
        grid[x][y] = 2;
        black.pb({x, y});
    }

    vi val(1001);
    val[0] = n;

    forr(i, 1, 1000 + 1)
    {
        vii nb;
        for (auto p : black)
        {
            if (p.f + 1 <= 4000 && !grid[p.f + 1][p.s])
            {
                grid[p.f + 1][p.s] = 2;
                nb.pb({p.f + 1, p.s});
            }
            if (p.f - 1 >= 0 && !grid[p.f - 1][p.s])
            {
                grid[p.f - 1][p.s] = 2;
                nb.pb({p.f - 1, p.s});
            }
            if (p.s + 1 <= 4000 && !grid[p.f][p.s + 1])
            {
                grid[p.f][p.s + 1] = 2;
                nb.pb({p.f, p.s + 1});
            }
            if (p.s - 1 >= 0 && !grid[p.f][p.s - 1])
            {
                grid[p.f][p.s - 1] = 2;
                nb.pb({p.f, p.s - 1});
            }
        }
        for (auto p : black)
            grid[p.f][p.s] = 1;
        for (auto p : grey)
            grid[p.f][p.s] = 0;
        swap(grey, black);
        swap(black, nb);
        val[i] = black.size();
    }
    frange(i, q)
    {
        int t;
        scd(t);
        printf("%d\n", val[t]);
    }
}