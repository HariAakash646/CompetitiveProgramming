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
    int n, m, d;
    scd(n);
    scd(m);
    scd(d);
    vector<vector<bitset<5001>>> grid(2 * d, vector<bitset<5001>>(2 * d));

    forr(i, 1, n + 1)
    {
        int p, q;
        scd(p);
        scd(q);
        grid[p][q][i] = 1;
        grid[p + d][q + d][i] = 1;
        grid[p + d][q][i] = 1;
        grid[p][q + d][i] = 1;
    }

    forr(i, 1, m + 1)
    {
        int r, q;
        scd(r);
        scd(q);
        forr(j, 0, 2 * d)
        {
            grid[r][j][i + n] = 1;
            grid[r + d][j][i + n] = 1;
        }
        forr(j, 0, 2 * d)
        {
            grid[j][q][i + n] = 1;
            grid[j][q + d][i + n] = 1;
        }
    }
    vector<vector<vector<bitset<5001>>>> optim(2 * d, vector<vector<bitset<5001>>>(2 * d, vector<bitset<5001>>(2 * d)));

    forr(y, 0, 2 * d)
    {
        forr(x1, 0, 2 * d)
        {
            optim[y][x1][x1] = grid[x1][y];
            forr(x2, x1 + 1, 2 * d)
            {
                optim[y][x1][x2] = optim[y][x1][x2 - 1] | grid[x2][y];
            }
        }
    }

    int ma = 1e9;
    forr(x1, 0, 2 * d)
    {
        forr(y1, 0, 2 * d)
        {
            forr(x2, x1, 2 * d)
            {
                bitset<5001> cnt;
                forr(y2, y1, 2 * d)
                {
                    int c = 0;
                    // forr(i, x1, x2 + 1)
                    // {
                    //     cnt |= grid[i][y2];
                    // }
                    cnt |= optim[y2][x1][x2];
                    c = cnt.count();
                    if (c == n + m)
                    {
                        ma = min(ma, (x2 - x1 + 1) * (y2 - y1 + 1));
                        break;
                    }
                    if (c > n + m)
                        break;
                }
            }
        }
    }
    printf("%d", ma);
}