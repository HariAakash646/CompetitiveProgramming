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

int inf = 1e9;

int main()
{
    int n, k;
    scd(n);
    scd(k);
    vii vec(n + 1);
    lli a;
    int d3 = 0;
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
        vec[i + 1] = {m2, m5};
        d3 += m5;
    }
    vvi dp(k + 1, vi(d3 + 1, -inf)), prev(k + 1, vi(d3 + 1, -inf));

    prev[0][0] = 0;
    forr(i, 1, n + 1)
    {
        forr(j, 0, k + 1)
        {
            forr(l, 0, d3 + 1)
            {
                dp[j][l] = prev[j][l];
                if (l - vec[i].s >= 0 && j > 0)
                {
                    dp[j][l] = max(dp[j][l], prev[j - 1][l - vec[i].s] + vec[i].f);
                }
                        }
        }
        prev = dp;
    }
    int ma = 0;
    forr(l, 0, d3 + 1)
    {
        ma = max(ma, min(l, dp[k][l]));
    }
    printf("%d", ma);
}