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

lli mod = 1e9 + 7;

int main()
{
    int t;
    scd(t);
    int n = 2e6;
    vll dp1(n + 1), dp2(n + 1);
    forr(i, 3, n + 1)
    {
        dp1[i] = dp2[i - 1] + 2 * dp2[i - 2] + 1;
        dp2[i] = max(dp2[i - 1], dp1[i - 1]) + 2 * max(dp2[i - 2], dp1[i - 2]);
        dp1[i] %= mod;
        dp2[i] %= mod;
    }

    frange(_, t)
    {
        int n;
        scd(n);
        printf("%lld\n", max(dp1[n], dp2[n]) * 4 % mod);
    }
}