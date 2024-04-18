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

vll val;
lli w, fv;
lli tot;

bool check(lli x)
{
    lli v1 = w * x;
    lli v2 = fv * x;
    auto it = upper_bound(all(val), v1);
    it--;
    return v2 >= tot - *it;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        sclld(w);
        sclld(fv);
        int n;
        scd(n);

        vi vec(n);
        tot = 0;
        frange(i, n)
        {
            scd(vec[i]);
            tot += vec[i];
        }

        vb dp(1e6 + 1);
        vb pre(1e6 + 1);
        pre[0] = true;

        for (auto e : vec)
        {
            frange(i, 1e6 + 1)
            {
                dp[i] = pre[i];
                if (i - e >= 0)
                {
                    dp[i] = dp[i] || pre[i - e];
                }
            }
            pre = dp;
        }
        val = {};
        frange(i, 1e6 + 1)
        {
            if (dp[i])
                val.pb(i);
        }

        lli l = 1;
        lli h = 1e9;

        while (l != h)
        {
            lli mid = (l + h) / 2;
            if (check(mid))
            {
                h = mid;
            }
            else
                l = mid + 1;
        }
        printf("%lld\n", l);
    }
}