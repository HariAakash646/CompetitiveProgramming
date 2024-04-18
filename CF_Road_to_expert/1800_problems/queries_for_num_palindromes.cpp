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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    int n = str.size();
    str = " " + str;
    int q;
    vector<vi> dp(n + 1, vi(n + 1));
    forr(l, 0, n)
    {
        for (int i = 1; i + l <= n; i++)
        {
            if (l == 0)
            {
                dp[i][i] = 1;
            }
            else if (l == 1)
            {
                if (str[i] == str[i + 1])
                {
                    dp[i][i + 1] = 1;
                }
            }
            else
            {
                if (str[i] == str[i + l])
                {
                    dp[i][i + l] = dp[i + 1][i + l - 1];
                }
            }
        }
    }
    vvi pref(n + 1, vi(n + 1));
    forr(i, 1, n + 1)
    {
        forr(j, 1, n + 1)
        {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + dp[i][j];
        }
    }
    cin >> q;
    frange(_, q)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        // int c = 0;
        // forr(i, a, b + 1)
        // {
        //     forr(j, i, b + 1)
        //     {
        //         if (dp[i][j])
        //         {
        //             c++;
        //         }
        //     }
        // }
        printf("%d\n", pref[b][b] - pref[a - 1][b] - pref[b][a - 1] + pref[a - 1][a - 1]);
    }
}