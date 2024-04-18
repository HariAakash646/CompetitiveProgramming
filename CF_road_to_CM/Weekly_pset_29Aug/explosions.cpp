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
        vll vec(n + 1);
        lli tot = 0;
        forr(i, 1, n + 1)
        {
            sclld(vec[i]);
            tot += vec[i];
        }

        vll dp1(n + 1), dp2(n + 2);

        stack<pair<lli, lli>> stk;

        for (lli i = 1; i <= n; i++)
        {
            // lli j = min(i - 1, vec[i] - 1);
            bool done = true;
            while (stk.size())
            {
                auto p = stk.top();
                if (p.f < vec[i] - (i - p.s))
                {
                    dp1[i] = dp1[p.s] + vec[i] * (vec[i] - 1) / 2 - (vec[i] - (i - p.s)) * (vec[i] - (i - p.s) + 1) / 2 + p.f;
                    // printf("%lld %lld %lld\n", dp1[i], dp1[p.s], vec[i] * (vec[i] - 1) / 2 - (vec[i] - (i - p.s)) * (vec[i] - (i - p.s) + 1) / 2);
                    done = false;
                    break;
                }
                else
                    stk.pop();
            }
            if (done)
            {
                if (vec[i] >= i)
                    dp1[i] = vec[i] * (vec[i] - 1) / 2 - (vec[i] - i) * (vec[i] - i + 1) / 2;
                else
                    dp1[i] = vec[i] * (vec[i] - 1) / 2;
            }
            stk.push(mp(vec[i], i));
        }
        stk = {};
        for (lli i = n; i >= 1; i--)
        {
            lli j = min(n - i, vec[i] - 1);
            bool done = true;
            while (stk.size())
            {
                auto p = stk.top();
                if (p.f < vec[i] - (p.s - i))
                {
                    dp2[i] = dp2[p.s] + vec[i] * (vec[i] - 1) / 2 - (vec[i] - (p.s - i)) * (vec[i] - (p.s - i) + 1) / 2 + p.f;
                    done = false;
                    break;
                }
                else
                    stk.pop();
            }
            if (done)
            {
                if (vec[i] >= n - i + 1)
                    dp2[i] = vec[i] * (vec[i] - 1) / 2 - (vec[i] - (n - i + 1)) * (vec[i] - (n - i + 1) + 1) / 2;

                else
                    dp2[i] = vec[i] * (vec[i] - 1) / 2;
            }
            stk.push(mp(vec[i], i));
        }
        lli ma = 0;
        forr(i, 1, n + 1)
        {
            // printf("%lld %lld\n", dp1[i], dp2[i]);
            ma = max(ma, dp1[i] + dp2[i]);
        }
        printf("%lld\n", tot - ma);
    }
}