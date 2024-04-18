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
    int t;
    scd(t);

    frange(_, t)
    {
        int n, k;
        scd(n);
        scd(k);
        string str;
        cin >> str;

        vi vec(n + 1);
        vi pref(n + 1);

        forr(i, 1, n + 1)
        {
            vec[i] = str[i - 1] - '0';
            pref[i] = pref[i - 1] + vec[i];
        }

        vi dp(n + 1);
        forr(i, 1, n + 1)
        {
            dp[i] = min(dp[max(0, i - k)] + pref[i - 1] - pref[max(0, i - k)] + !vec[i], pref[i - 1] + !vec[i]);
        }
        int mi = 1e9;
        forr(i, 0, n + 1)
        {
            mi = min(mi, dp[i] + pref[n] - pref[i]);
        }
        printf("%d\n", mi);
    }
}