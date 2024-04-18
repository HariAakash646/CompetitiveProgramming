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
    int t;
    scd(t);
    frange(_, t)
    {
        int n, m, k;
        scd(n);
        scd(m);
        scd(k);
        vvi vec(n, vi(m));
        frange(i, n)
        {
            frange(j, m)
            {
                scd(vec[i][j]);
            }
        }
        vector<vvi> dp1(n, vvi(m, vi(k + 1, -2e9))), dp2(n, vvi(m, vi(k + 1, 2e9)));
        dp2[n - 1][0][0] = dp1[n - 1][0][0] = vec[n - 1][0];

        forr(i, 1, m) dp2[n - 1][i][0] = dp1[n - 1][i][0] = dp1[n - 1][i - 1][0] + vec[i];

        for (int i = n - 2; i >= 0; i--)
        {
            frange(j, m)
            {
                frange(l, k + 1)
                {
                }
            }
        }
    }
}