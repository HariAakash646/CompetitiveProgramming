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
    int mv = 1 << 22;
    vi vec(n);
    frange(i, n) scd(vec[i]);
    vi dp(1 << 22, -1);
    frange(i, n)
    {
        dp[vec[i]] = vec[i];
    }
    frange(i, mv)
    {
        frange(j, 22)
        {
            if (dp[i] != -1)
                break;
            if ((1 << j) & i)
            {
                dp[i] = dp[i ^ (1 << j)];
            }
        }
    }
    frange(i, n)
    {
        printf("%d ", dp[(mv - 1) ^ vec[i]]);
    }
}