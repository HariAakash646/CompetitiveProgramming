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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a;
    cin >> b;
    int as = a.size() + 1;
    int bs = b.size() + 1;
    vvi dp(as, vi(bs, 0));
    forr(i, 1, as, 1)
    {
        dp[i][0] = dp[i - 1][0] + 1;
    }
    forr(j, 1, bs, 1)
    {
        dp[0][j] = dp[0][j - 1] + 1;
    }
    forr(i, 1, as, 1)
    {
        forr(j, 1, bs, 1)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }
    cout << dp[as - 1][bs - 1];
}