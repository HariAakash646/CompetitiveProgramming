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
    int n;
    scd(n);
    vi v1(1 << n);
    forr(i, 1, 1 << n) scd(v1[i]);
    int x = v1[(1 << n) - 1];
    vi v2(1 << n);
    forr(i, 1, 1 << n)
    {
        v2[i] = x - v1[i];
    }
    vi dp(1 << n);
    forr(i, 1, 1 << n) dp[i] = v2[i];
    frange(i, n)
    {
        for (int mask = (1 << n) - 1; mask >= 1; mask--)
        {
            if ((mask & (1 << i)) == 0)
            {
                dp[mask] -= dp[mask ^ (1 << i)];
            }
        }
    }
    vector<seti> vec(n);
    frange(i, n)
    {
        forr(j, 1, x + 1) vec[i].insert(j);
    }
    int c = 1;

    forr(mask, 1, 1 << n)
    {
        if (dp[mask] < 0)
        {
            printf("NO");
            return 0;
        }
        // printf("%d ", dp[mask]);

        if (c + dp[mask] - 1 > x)
        {
            printf("NO");
            return 0;
        }
        frange(j, n)
        {
            if (mask & (1 << j))
            {
                frange(i, dp[mask])
                    vec[j]
                        .erase(c + i);
            }
        }
        c += dp[mask];
    }
    // printf("\n");
    // vector<seti> cnt(1 << n);
    // // frange(i, n) {
    // //     cnt[1<<i] = vec[i];
    // // }

    // forr(i, 1, 1 << n)
    // {
    //     frange(j, n)
    //     {
    //         if (i & (1 << j))
    //         {
    //             cnt[i] = cnt[i ^ (1 << j)];
    //             for (auto e : vec[j])
    //                 cnt[i].insert(e);
    //             break;
    //         }
    //     }
    // }
    // forr(i, 1, 1 << n)
    // {
    //     if (cnt[i].size() != v1[i])
    //     {
    //         printf("NO");
    //         return 0;
    //     }
    // }
    printf("YES\n");
    frange(i, n)
    {
        printf("%d ", vec[i].size());
        for (auto e : vec[i])
            printf("%d ", e);
        printf("\n");
    }
}