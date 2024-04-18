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

lli mod = 1e9 + 7;

int main()
{
    int n, k, d;
    scd(n);
    scd(k);
    scd(d);
    vll dp(n + 1);
    vll ddp(n + 1);
    dp[0] = 1;
    forr(i, 1, n + 1)
    {
        forr(j, 1, min(i, k) + 1)
        {
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }
    forr(i, 1, n + 1)
    {
        forr(j, 1, min(i, k) + 1)
        {
            if (j >= d)
                ddp[i] = (ddp[i] + dp[i - j]) % mod;
            else
                ddp[i] = (ddp[i] + ddp[i - j]) % mod;
        }
    }
    printf("%d", ddp[n]);
}