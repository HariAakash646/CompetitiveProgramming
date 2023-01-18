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
typedef long long int lli;
typedef unsigned long long int ulli;

int inf = 1e9 + 5;

int main()
{
    int n, k;
    scd(n);
    scd(k);
    k--;
    vi vec(n);
    frange(i, n) scd(vec[i]);
    vi dp(n, -inf);
    dp[k] = 0;
    forr(i, k + 1, n)
    {
        int a, b;
        if (i == 1)
        {
            b = -inf;
        }
        else
            b = dp[i - 2];
        a = dp[i - 1];
        dp[i] = max(a, b) + vec[i];
    }
    // auto itr = max_element(all(dp));
    // int idx = itr - dp.begin();
    // int ele = *itr;
    vi dpb = dp;
    // dpb[idx] = ele;
    for (int i = n - 2; i >= 0; i--)
    {
        int a, b, c;
        if (i == n - 2)
        {
            b = -inf;
        }
        else
            b = dpb[i + 2] + vec[i];
        a = dpb[i + 1] + vec[i];
        dpb[i] = max({a, b, dpb[i]});
    }
    printf("%d", dpb[0]);
}