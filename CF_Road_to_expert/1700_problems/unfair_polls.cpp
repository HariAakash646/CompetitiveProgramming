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
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    lli n, m, k, x, y;
    sclld(n);
    sclld(m);
    sclld(k);
    sclld(x);
    sclld(y);
    lli cnt;
    if (n == 1)
        cnt = m;
    else
        cnt = (n - 2) * m * 2 + 2 * m;
    lli rnd = k / cnt;
    lli rem = k % cnt;
    vvll grid(n, vll(m));
    frange(i, m)
    {
        grid[0][i] = rnd;
        grid[n - 1][i] = rnd;
    }

    forr(i, 1, n - 1)
    {
        frange(j, m)
        {
            grid[i][j] = 2 * rnd;
        }
    }

    frange(i, n)
    {
        if (!rem)
            break;
        frange(j, m)
        {
            if (rem)
            {
                grid[i][j]++;
                rem--;
            }
            else
            {
                break;
            }
        }
    }
    for (int i = n - 2; i >= 1; i--)
    {
        if (!rem)
            break;
        frange(j, m)
        {
            if (rem)
            {
                grid[i][j]++;
                rem--;
            }
            else
            {
                break;
            }
        }
    }
    lli ma = 0;
    lli mi = 1e18;

    frange(i, n)
    {
        frange(j, m)
        {
            ma = max(ma, grid[i][j]);
            mi = min(mi, grid[i][j]);
        }
    }

    printf("%lld %lld %lld", ma, mi, grid[x - 1][y - 1]);
}