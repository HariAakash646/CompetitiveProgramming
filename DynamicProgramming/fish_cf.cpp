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
    int n;
    scd(n);
    vector<vector<ld>> vec(n, vector<ld>(n));

    frange(i, n)
    {
        frange(j, n)
        {
            cin >> vec[i][j];
        }
    }

    vector<ld> dp(1 << n, 0);
    frange(i, n)
    {
        dp[(1 << n) - 1] = 1;
    }
    for (int i = (1 << n) - 2; i >= 1; i--)
    {

        int k = __builtin_popcount(i) + 1;
        ld c = ld(k * ld(k - 1)) / 2;
        frange(j, n)
        {
            if (i & (1 << j))
            {
                frange(l, n)
                {
                    if ((i & (1 << l)) == 0)
                    {
                        dp[i] += dp[i ^ (1 << l)] * vec[j][l] / c;
                    }
                }
            }
        }
    }
    // frange(i, (1 << n))
    // {
    //     frange(j, n)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << setprecision(6);
    frange(i, n)
    {
        cout << dp[1 << i] << " ";
    }
}