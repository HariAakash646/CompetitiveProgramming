// Not working
#include <bits/stdc++.h>
#include <iostream>

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
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);
    vi vec(n + 1);
    forr(i, 1, n + 1)
    {
        scd(vec[i]);
    }
    vector<vector<pii>> satis(n + 1);
    frange(i, k)
    {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        satis[a].pb({b, c});
    }
    vector<vector<lli>> dp(n + 1, vector<lli>(1 << n));
    lli ma = 0;
    forr(i, 0, n + 1)
    {
        frange(j, (1 << n))
        {
            if (i > 0)
                dp[i][j] = dp[i - 1][j];
            // if (!(j & (1 << i)))
            //     continue;
            for (auto e : satis[i])
            {
                if (e.f == i)
                    continue;
                if (j & (1 << e.f))
                    dp[i][j] = max(dp[i][j], dp[i][j ^ (1 << e.f)] + e.s + vec[e.f]);
            }
            forr(k, 0, n + 1)
            {
                if (k == i)
                    continue;
                if (j & (1 << k))
                    dp[i][j] = max(dp[i][j], dp[i][j ^ (1 << k)] + vec[k + 1]);
            }
            int c = 0;

            frange(k, n)
            {
                if (j & (1 << k))
                    c++;
            }
            if (c == m)
            {
                ma = max(ma, dp[i][j]);
            }
        }
    }
    printf("%lld", ma);
}