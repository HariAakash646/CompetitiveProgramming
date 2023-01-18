// Not solved
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

int mod = 1e9 + 7;

int main()
{
    int n, x;
    scd(n);
    scd(x);
    vi vec(n);
    frange(i, n) scd(vec[i]);
    sort(all(vec));
    vi diff;
    frange(i, n)
    {
        frange(j, i + 1)
        {
            diff.pb(vec[i] - vec[j]);
        }
    }
    for (int e : diff)
    {
        printf("%d ", e);
    }

    int k = diff.size();
    vvi dp(x + 1, vi(k, 0));
    frange(i, k)
    {
        if (diff[i] == 0)
            dp[0][i] = 1;
    }
    frange(i, x + 1)
    {
        dp[i][0] = 1;
    }
    forr(i, 1, x + 1)
    {
        forr(j, 1, k)
        {
            int tmp = 0;
            if (i - diff[j] >= 0 && diff[j] > 0)
            {
                tmp = dp[i - diff[j]][j - 1];
            }
            dp[i][j] = (dp[i - 1][j] + tmp) % mod;
        }
    }
    printf("%d", dp[x][k - 1]);
}