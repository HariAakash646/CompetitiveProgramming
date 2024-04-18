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
        int n;
        scd(n);
        vii vec(n + 1);
        forr(i, 1, n + 1) scd(vec[i].f);
        forr(i, 1, n + 1) scd(vec[i].s);

        vii dp(n + 1);
        vi pre(n + 1);
        vb en(n + 1);
        forr(i, 1, n + 1)
        {
            if (!pre[vec[i].f])
            {
                dp[i].f = 1;
            }
            else
            {
                if (vec[pre[vec[i].f]].f != vec[i].f)
                {
                    dp[i].f += dp[pre[vec[i].f]].f;
                }
                if (vec[pre[vec[i].f]].s != vec[i].f)
                {
                    dp[i].f += dp[pre[vec[i].f]].s;
                }
            }
            if (!pre[vec[i].s])
            {
                dp[i].s = 1;
            }
            else
            {
                if (vec[pre[vec[i].s]].f != vec[i].s)
                {
                    dp[i].s += dp[pre[vec[i].s]].f;
                }
                if (vec[pre[vec[i].s]].s != vec[i].s)
                {
                    dp[i].s += dp[pre[vec[i].s]].s;
                }
            }
            en[pre[vec[i].f]] = false;
            en[pre[vec[i].s]] = false;
            pre[vec[i].f] = i;
            pre[vec[i].s] = i;
            en[i] = true;
            if (vec[i].f == vec[i].s)
            {
                if (dp[i].f != 0)
                    dp[i].f = n;
            }
        }
        lli tot = 1;
        forr(i, 1, n + 1) if (en[i]) { tot *= (dp[i].f + dp[i].s); }
        printf("%lld\n", tot);
    }
}