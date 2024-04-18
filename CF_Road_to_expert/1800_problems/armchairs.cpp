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

int main()
{
    int n;
    scd(n);
    vi vec(n + 1);
    int cnt = 0;
    forr(i, 1, n + 1)
    {
        scd(vec[i]);
        if (vec[i])
            cnt++;
    }
    vi idx(cnt + 1);
    int curr = 1;
    forr(i, 1, n + 1)
    {
        if (vec[i])
        {
            idx[curr] = i;
            curr++;
        }
    }
    vvi dp(n + 1, vi(cnt + 1, 1e9));
    forr(i, 0, n + 1)
        dp[i][0] = 0;
    forr(i, 1, n + 1)
    {
        forr(j, 1, cnt + 1)
        {
            dp[i][j] = dp[i - 1][j];
            if (!vec[i])
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(i - idx[j]));
            }
        }
    }
    printf("%d", dp[n][cnt]);
}