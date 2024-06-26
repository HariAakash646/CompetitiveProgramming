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

int main()
{
    string num;
    cin >> num;
    int n = num.size();
    vector<vll> dp(n + 1, vll(10));
    // frange(i, 10)
    // {
    //     dp[0][i] = 1;
    // }
    forr(i, 1, n + 1)
    {
        frange(j, 10)
        {
            if (i == 1)
                dp[i][j] = 1;
            int k = num[i - 1] - '0';
            int x = 2 * j - k;
            if (x >= 0 && x <= 9)
            {
                dp[i][j] += dp[i - 1][x];
            }
            if (x + 1 >= 0 && x + 1 <= 9)
            {
                dp[i][j] += dp[i - 1][x + 1];
            }
            if (x - 1 >= 0 && x - 1 <= 9)
            {
                dp[i][j] += dp[i - 1][x - 1];
            }
        }
    }
    lli sum = 0;
    frange(i, 10)
    {
        sum += dp[n][i];
    }
    lli minus = 1;
    frange(i, n - 1)
    {
        if (abs((2 * (num[i + 1] - '0') - (num[i] - '0')) - (num[i + 1] - '0')) > 1)
        {
            minus = 0;
            break;
        }
    }
    printf("%lld", sum - minus);
}