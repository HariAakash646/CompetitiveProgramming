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

int inf = 1e9 + 10;

int main()
{
    int n, q;
    scd(n);
    scd(q);
    seti vec;
    int a;
    frange(i, n)
    {
        scd(a);
        vec.insert(a);
    }
    n = vec.size();

    vvi dp(n + 1, vi(2));

    forr(i, 2, n + 1)
    {
        dp[i][0] = inf;
        dp[i][1] = inf;
        forr(j, 1, i)
        {
            dp[i][0] = min(dp[i][0], 1 + max(dp[j][0], dp[i - j][0]));
            dp[i][1] = min(dp[i][1], max({1 + dp[j][1], 1 + dp[i - j][1], 1 + dp[j][0] + dp[i - j][0]}));
        }
    }
    if (dp[n][1] <= q)
        printf("YES");
    else
        printf("NO");
    // printf("\n%d", out);
}