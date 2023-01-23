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
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    frange(i, q)
    {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        vvi dp(n + 1, vi(3, 0));
        // dp[1][0] = str[0] != 'R';
        // dp[1][1] = str[0] != 'G';
        // dp[1][2] = str[0] != 'B';
        forr(i, 1, n + 1)
        {
            dp[i][0] = dp[i - 1][2] + (str[i - 1] != 'R');
            dp[i][1] = dp[i - 1][0] + (str[i - 1] != 'G');
            dp[i][2] = dp[i - 1][1] + (str[i - 1] != 'B');
            // printf("%d %d %d\n", dp[i][0], dp[i][1], dp[i][2]);
        }
        int mi = 1e9 + 5;
        forr(i, k, n + 1)
        {
            int a = 3e5;
            mi = min({mi, dp[i][0] - dp[i - k][(0 - k + a) % 3], dp[i][1] - dp[i - k][(1 - k + a) % 3], dp[i][2] - dp[i - k][(2 - k + a) % 3]});
        }
        printf("\n%d\n\n", mi);
    }
}