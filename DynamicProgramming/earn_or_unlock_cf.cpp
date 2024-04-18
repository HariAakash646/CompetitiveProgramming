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
    scd(n);
    vi vec(2 * n);

    frange(i, n) scd(vec[i]);

    bitset<200001> dp;
    bitset<200001> full;
    frange(i, 200001) full[i] = 1;
    dp[0] = 1;
    lli c = 0;
    frange(i, n)
    {
        if (c >= i)
        {
            dp |= ((dp & (full << i)) << vec[i]);
            c += vec[i];
        }
    }
    lli ma = 0;
    lli tot = 0;
    frange(i, 2 * n)
    {
        tot += vec[i];
        if (dp[i])
            ma = max(ma, tot - i);
    }
    printf("%lld", ma);
}