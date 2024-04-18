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
        map<lli, lli> cnt;
        frange(i, n)
        {
            lli a;
            sclld(a);
            cnt[a]++;
        }
        int q;
        scd(q);
        frange(_, q)
        {
            lli x, y;
            sclld(x);
            sclld(y);

            if (x > 0 && y > 0)
            {
                lli lo = 1;
                lli hi = x / 2;
                while (lo < hi)
                {
                    lli mid = (lo + hi) / 2;
                    if (mid * (x - mid) < y)
                    {
                        lo = mid + 1;
                    }
                    else
                    {
                        hi = mid;
                    }
                }
                if (lo * (x - lo) == y)
                {
                    if (lo != x - lo)
                        printf("%lld ", cnt[lo] * cnt[x - lo]);
                    else
                        printf("%lld ", cnt[lo] * (cnt[lo] - 1) / 2);
                }
                else
                    printf("0 ");
            }
            else if (x > 0 && y < 0)
            {
                lli lo = x + 1;
                lli hi = x + 1e9;
                while (lo != hi)
                {
                    lli mid = (lo + hi) / 2;
                    if (mid * (x - mid) > y)
                    {
                        lo = mid + 1;
                    }
                    else
                        hi = mid;
                }
                // printf("\n%lld\n", lo);
                if (lo * (x - lo) == y)
                {
                    if (lo != x - lo)
                        printf("%lld ", cnt[lo] * cnt[x - lo]);
                    else
                        printf("%lld ", cnt[lo] * (cnt[lo] - 1) / 2);
                }
                else
                    printf("0 ");
            }
            else if (x < 0 && y > 0)
            {
                x = -x;
                lli lo = 1;
                lli hi = x / 2;
                while (lo < hi)
                {
                    lli mid = (lo + hi) / 2;
                    if (mid * (x - mid) < y)
                    {
                        lo = mid + 1;
                    }
                    else
                    {
                        hi = mid;
                    }
                }
                x = -x;
                lo = -lo;
                if (lo * (x - lo) == y)
                {
                    if (lo != x - lo)
                        printf("%lld ", cnt[lo] * cnt[x - lo]);
                    else
                        printf("%lld ", cnt[lo] * (cnt[lo] - 1) / 2);
                }
                else
                    printf("0 ");
            }
            else
            {
                x = -x;
                lli lo = x + 1;
                lli hi = x + 1e9;
                while (lo != hi)
                {
                    lli mid = (lo + hi) / 2;
                    if (mid * (x - mid) > y)
                    {
                        lo = mid + 1;
                    }
                    else
                        hi = mid;
                }
                // printf("\n%lld\n", lo);
                x = -x;
                lo = -lo;
                if (lo * (x - lo) == y)
                {
                    if (lo != x - lo)
                        printf("%lld ", cnt[lo] * cnt[x - lo]);
                    else
                        printf("%lld ", cnt[lo] * (cnt[lo] - 1) / 2);
                }
                else
                    printf("0 ");
                        }
        }
        printf("\n");
    }
}