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

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vi vec(n);
        frange(i, n)
        {
            scd(vec[i]);
        }
        vb dp(n);
        frange(i, n)
        {
            if (i == 0 || dp[i - 1])
            {
                if (i + vec[i] < n)
                {
                    dp[i + vec[i]] = true;
                }
            }
            if (!dp[i])
            {
                if (i - vec[i] - 1 >= 0)
                {
                    dp[i] = dp[i - vec[i] - 1];
                }
                else if (i - vec[i] == 0)
                {
                    dp[i] = true;
                }
            }
        }
        if (dp[n - 1])
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}