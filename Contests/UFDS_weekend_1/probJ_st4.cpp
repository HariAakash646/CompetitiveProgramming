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

lli mod = 1e9 + 7;

lli inv(lli i)
{
    return i <= 1 ? i : mod - (long long)(mod / i) * inv(mod % i) % mod;
}

lli dpg[101][101][101];
lli dph[101][101][101];
lli dpr[101][101][101];
lli dpv[101][101][101];

int main()
{
    vll fact(1e5 + 1);
    fact[0] = 1;
    forr(i, 1, 1e5 + 1) fact[i] = (fact[i - 1] * i) % mod;
    int t;
    scd(t);
    frange(_, t)
    {
        int r, g, h;
        scd(g);
        scd(h);
        scd(r);
        if (r == 0)
        {
            if (g > h)
                swap(g, h);
            if (g == h)
                printf("2\n");
            else if (g == h - 1)
                printf("1\n");
            else
                printf("0\n");
            continue;
        }
        else if (g > h + r)
        {
            if (g == h + r + 1)
            {
                lli v = fact[h + r] * (inv(fact[h]) * inv(fact[r]) % mod) % mod;
                printf("%lld\n", v);
            }
            else
                printf("0\n");
            continue;
        }
        else if (r == 1)
        {
            if (g > h)
                swap(g, h);
            if (h == g + 2)
            {
                printf("%d\n", g + 1);
            }
            else if (h == g + 1)
            {
                lli v = 2 * h;
                v += h + g - 1;
                printf("%lld\n", v % mod);
            }
            else if (h == g)
            {
                lli v = 2 * (h + g + 1);
                v += 2 * ((h - 1) - 1 + 1);
                printf("%lld\n", v % mod);
            }
            else
                printf("0\n");
            continue;
        }
        dpv[0][0][0] = 1LL;
        frange(i, g + 1)
        {
            frange(j, h + 1)
            {
                frange(k, r + 1)
                {
                    if (i == 0 && j == 0 && k == 0)
                        continue;
                    dpg[i][j][k] = 0;
                    dph[i][j][k] = 0;
                    dpr[i][j][k] = 0;
                    dpv[i][j][k] = 0;
                    if (i >= 1)
                    {
                        dpg[i][j][k] = dpv[i - 1][j][k] - dpg[i - 1][j][k] + mod;
                        dpg[i][j][k] %= mod;
                    }
                    if (j >= 1)
                    {
                        dph[i][j][k] = dpv[i][j - 1][k] - dph[i][j - 1][k] + mod;
                        dph[i][j][k] %= mod;
                    }
                    if (k >= 1)
                    {
                        dpr[i][j][k] = dpv[i][j][k - 1] - dpr[i][j][k - 1] + mod;
                        dpr[i][j][k] %= mod;
                    }
                    dpv[i][j][k] = (dpr[i][j][k] + dph[i][j][k] + dpg[i][j][k]) % mod;
                    // printf("%lld ", dp[i][j][k].v);
                }
                // printf("\n");
            }
            // printf("**********************\n");
        }
        printf("%lld\n", dpv[g][h][r]);
    }
}