#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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

int main()
{
    int n;
    string dig;
    cin >> n >> dig;
    vi vec;
    for (auto e : dig)
        vec.pb(e - '0');
    vector<map<int, lli>> dp(n + 1);
    dp[0][1] = 1;
    frange(i, n)
    {
        for (auto p : dp[i])
        {
            for (auto e : vec)
            {
                dp[i + 1][p.f * e] += p.s;
            }
        }
    }
    lli ans = 0;
    for (auto p : dp[n])
        ans += p.s * p.s;
    printf("%lld", ans);
}