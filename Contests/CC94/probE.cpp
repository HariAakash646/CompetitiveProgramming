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
    int t;
    scd(t);
    frange(_, t)
    {
        int n, m;
        scd(n);
        scd(m);
        vector<vll> grid(n + 1, vll(m + 1));

        forr(i, 1, n + 1)
        {
            forr(j, 1, m + 1)
            {
                sclld(grid[i][j]);
            }
        }

        vector<vector<vll>> pref(n + 1, vector<vll>(m + 1, vll(30)));
        forr(i, 1, n + 1)
        {
            forr(j, 1, m + 1)
            {
                frange(k, 30)
                {
                    pref[i][j][k] = pref[i - 1][j][k] + pref[i][j - 1][k] - pref[i - 1][j - 1][k];
                    if (grid[i][j] & (1 << k))
                        pref[i][j][k]++;
                }
            }
        }
        lli ma = 0;
        forr(i, 1, n + 1)
        {
            forr(j, 1, m + 1)
            {
                lli v = 0;
                frange(k, 30)
                {
                    if ((grid[i][j] & (1 << k)) == 0)
                    {
                        v += (1 << k) * pref[i - 1][j - 1][k];
                        if (j != m && i != n)
                            v += (1 << k) * (pref[n][m][k] - pref[n][j][k] - pref[i][m][k] + pref[i][j][k]);
                        if (i != n)
                            v += (1 << k) * (pref[n][j - 1][k] - pref[i][j - 1][k]);
                        if (j != m)
                            v += (1 << k) * (pref[i - 1][m][k] - pref[i - 1][j][k]);
                    }
                }
                printf("%lld\n", v);
                ma = max(ma, v);
            }
        }
        printf("%lld\n", ma);
    }
}