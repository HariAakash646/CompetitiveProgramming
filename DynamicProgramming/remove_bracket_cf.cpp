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
    int t;
    scd(t);
    frange(_, t)
    {
        int n, sz;
        vi vec(n);
        frange(i, n)
        {
            scd(vec[i]);
        }
        vvi dp(2, n);
        bool less;
        if (vec[0] <= sz)
        {
            dp[0][0] = 0;
            dp[1][0] = vec[0] * vec[0];
            less = true;
        }
        else
        {
            dp[0][0] = vec[0] * sz;
            dp[1][0] = vec[0] * (vec[0] - sz);
            less = false;
        }
        forr(i, 1, n)
        {
            if (vec[i] <= sz)
            {
                if (less)
                {
                    dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]);
                    dp[1][i] = min(dp[0][i - 1] + vec[i - 1] * vec[i], dp[1][i - 1]);
                }
                else
                {
                    dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]);
                    dp[1][i] = min(dp[0][i - 1] + vec[i] * (vec[i - 1] - sz), dp[1][i - 1] + vec[i] * sz);
                }

                less = true;
            }
            else
            {
                if (less)
                {
                    dp[0][i] = min(dp[0][i - 1] + vec[i - 1] * sz, dp[1][i - 1]);
                    dp[1][i] = min(dp[0][i - 1] + vec[i - 1] * (vec[i] - sz), dp[1][i - 1]);
                }
                else
                {
                    dp[0][i] = min(dp[0][i - 1] + vec[i - 1] * (vec[i - 1] - sz), dp[1][i - 1] + (vec[i] - sz) * (vec[i - 1] - sz));
                    dp[1][i] = min(dp[0][i - 1] + vec[i - 1] * (vec[i] - sz), dp[1][i - 1]);
                }

                less = true;
            }
        }
    }
}