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
    vi vec(n + 1);
    lli tot = 0;
    frange(i, n)
    {
        scd(vec[i + 1]);
        tot += vec[i + 1];
    }
    vector<vll> dp(n + 1, vll(n + 1));
    forr(l, 0, n)
    {
        for (int i = 1; i + l <= n; i++)
        {
            if (l == 0)
            {
                dp[i][i] = vec[i];
            }
            else
            {
                dp[i][i + l] = max(vec[i] - dp[i + 1][i + l], vec[i + l] - dp[i][i + l - 1]);
            }
        }
    }
    printf("%lld", (tot + dp[1][n]) / 2);
}