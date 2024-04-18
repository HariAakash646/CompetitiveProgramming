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

int powf(int x, int p)
{
    int o = 1;
    frange(i, p) o *= x;
    return o;
}

int calc(int i, int j, vvi &grid)
{
    int v = 0;
    int p = 0;
    frange(k, 2)
    {
        frange(l, 2)
        {
            v += powf(26, p) * grid[i + k][j + l];
            p++;
        }
    }
    return v;
}

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    vvi grid(n, vi(m));

    frange(i, n)
    {
        frange(j, m)
        {
            char c;
            cin >> c;
            grid[i][j] = c - 'a';
        }
    }

    vi cnt(26 * 26 * 26 * 26);
    frange(i, n - 1)
    {
        frange(j, m - 1)
        {
            int v = calc(i, j, grid);
            cnt[v]++;
        }
    }
    vvi wind(2, vi(2));
    frange(i, 2)
    {
        frange(j, 2)
        {
            char c;
            cin >> c;
            wind[i][j] = c - 'a';
        }
    }
    int val = calc(0, 0, wind);
    // frange(i, 2) {
    //     frange(j, 2) {
    //         char c;
    //         cin >> c;
    //         win[i][j] = c - 'a';
    //         v += win[i][j] * powf(26, i+j);
    //     }
    // }
    cout << cnt[val] << "\n";
    frange(_, q)
    {
        int t, i, j;
        char c;
        cin >> t >> i >> j >> c;
        int x = c - 'a';
        i--;
        j--;
        if (t == 1)
        {
            int v;

            if (i < n - 1 && j < m - 1)
            {
                v = calc(i, j, grid);
                cnt[v]--;
            }
            if (i >= 1 && j < m - 1)
            {
                v = calc(i - 1, j, grid);
                cnt[v]--;
            }
            if (j >= 1 && i < n - 1)
            {
                v = calc(i, j - 1, grid);
                cnt[v]--;
            }
            if (i >= 1 && j >= 1)
            {
                v = calc(i - 1, j - 1, grid);
                cnt[v]--;
            }
            grid[i][j] = x;
            if (i < n - 1 && j < m - 1)
            {
                v = calc(i, j, grid);
                cnt[v]++;
            }
            if (i >= 1 && j < m - 1)
            {
                v = calc(i - 1, j, grid);
                cnt[v]++;
            }
            if (j >= 1 && i < n - 1)
            {
                v = calc(i, j - 1, grid);
                cnt[v]++;
            }
            if (i >= 1 && j >= 1)
            {
                v = calc(i - 1, j - 1, grid);
                cnt[v]++;
            }
        }
        else
        {
            wind[i][j] = x;
            val = calc(0, 0, wind);
        }
        cout << cnt[val] << "\n";
    }
}