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
    int q;
    scd(q);
    frange(_, q)
    {
        int n;
        scd(n);
        vi vec(n + 1);
        frange(i, n) scd(vec[i + 1]);

        sort(all(vec));
        vvi dp(n + 1, vi(2 * n + 1, 1e9));

        forr(i, 1, 2 * n + 1) dp[1][i] = abs(i - vec[1]);

        forr(i, 2, n + 1)
        {
            forr(k, 1, 2 * n + 1)
            {
                forr(j, 1, k)
                {
                    dp[i][k] = min(dp[i][k], dp[i - 1][j] + abs(k - vec[i]));
                }
            }
        }
        printf("%d\n", *min_element(all(dp[n])));
    }
}