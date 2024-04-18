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

vvi pref;

int pref2d(int i1, int j1, int i2, int j2)
{
    return pref[i2][j2] - pref[i1 - 1][j2] - pref[i2][j1 - 1] + pref[i1 - 1][j1 - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    pref = vvi(n + 1, vi(m + 1));

    forr(i, 1, n + 1)
    {
        string row;
        cin >> row;
        forr(j, 1, m + 1)
        {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            if (row[j - 1] == '#')
                pref[i][j]++;
        }
    }

    forr(i, 1, (n + 1) - 8)
    {
        forr(j, 1, (m + 1) - 8)
        {
            if (i == 1 && j == 1)
            {
                // cout << pref[i + 8][j + 8] - pref[i + 8 - 3][j] - pref[i][j + 8 - 3] + pref[i + 8 - 3][j + 8 - 3] << " " << pref[i + 8][j + 8] - pref[i + 8 - 3 - 1][j + 8] - pref[i + 8][j + 8 - 3 - 1] + pref[i + 8 - 3 - 1][j + 8 - 3 - 1];
            }
            if (pref2d(i, j, i + 2, j + 2) == 9 && pref2d(i, j, i + 3, j + 3) == 9)
            {
                if (pref2d(i + 6, j + 6, i + 8, j + 8) == 9 && pref2d(i + 5, j + 5, i + 8, j + 8) == 9)
                {
                    cout << i << " " << j << "\n";
                }
            }
        }
    }
}