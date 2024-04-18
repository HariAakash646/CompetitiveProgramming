// Incorrect
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
    forr(i, 1, n + 1)
    {
        scd(vec[i]);
    }
    if (n % 2 == 0)
    {
        lli v1 = 0;
        lli v2 = 0;
        forr(i, 1, n + 1)
        {
            if (i % 2)
            {
                v1 += vec[i];
            }
            else
            {
                v2 += vec[i];
            }
        }
        printf("%lld", max(v1, v2));
    }
    else
    {
        vll dp1(n + 1);
        vll dp2(n + 1);
        dp1[1] = vec[1];
        forr(i, 2, n + 1)
        {
            dp1[i] = dp1[i - 2] + vec[i];
            if (i > 2)
            {
                dp2[i] = max(dp2[i - 2] + vec[i], dp1[i - 3] + vec[i]);
                if (i > 3)
                {
                    dp2[i] = max(dp2[i], dp1[i - 4] + vec[i]);
                }
            }
        }
        printf("%lld", max(max(dp1[n - 1], dp2[n]), max(dp1[n - 2], dp2[n - 1])));
    }
}