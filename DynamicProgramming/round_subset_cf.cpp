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
    int n, k;
    scd(n);
    scd(k);
    vii vec(n);
    lli a;
    frange(i, n)
    {
        sclld(a);
        int m2 = 0;
        while (a % 2 == 0)
        {
            m2++;
            a /= 2;
        }
        int m5 = 0;
        while (a % 5 == 0)
        {
            m5++;
            a /= 5;
        }
        vec[i] = {m2, m5};
    }
    vector<vii> dp(k + 1, vii(n, {0, 0}));
    forr(i, 1, k + 1)
    {
        dp[i][0] = vec[0];
    }
    forr(i, 1, k + 1)
    {
        forr(j, 1, n)
        {
            pii p = vec[j];
            pii bp = {0, 0};
            int mv = 0;
            frange(k, j)
            {
                if (min(p.f + dp[i - 1][k].f, p.s + dp[i - 1][k].s) > mv)
                {
                    mv = min(p.f + dp[i - 1][k].f, p.s + dp[i - 1][k].s);
                    bp = {p.f + dp[i - 1][k].f, p.s + dp[i - 1][k].s};
                }
            }

            if (min(dp[i][j - 1].f, dp[i][j - 1].s) > mv)
            {
                dp[i][j] = dp[i][j - 1];
            }
            else
            {
                dp[i][j] = bp;
            }
        }
    }
    printf("%d", min(dp[k][n - 1].f, dp[k][n - 1].s));
}