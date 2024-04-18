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

    vii vec(n + 1);
    int tot = 0;
    forr(i, 1, n + 1)
    {
        scd(vec[i].s);
        tot += vec[i].s;
    }

    forr(i, 1, n + 1)
    {
        scd(vec[i].f);
    }

    sort(vec.begin() + 1, vec.end(), greater<>());

    int k = n;

    int v = 0;
    forr(i, 1, n + 1)
    {
        k = i;
        v += vec[i].f;
        if (v >= tot)
            break;
    }

    printf("%d ", k);

    vvi prev(k + 1, vi(1e4 + 1, 1e9)), dp(k + 1, vi(1e4 + 1, 1e9));
    prev[0][0] = 0;

    forr(i, 1, n + 1)
    {
        dp[0][0] = 0;
        forr(j, 1, k + 1)
        {
            forr(k, 0, 1e4 + 1)
            {
                dp[j][k] = min(prev[j][k], prev[j - 1][max(0, k - vec[i].f)] + min(k, vec[i].f) - vec[i].s);
            }
        }
        prev = dp;
    }

    printf("%d", dp[k][tot]);
}