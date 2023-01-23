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

lli mod = 1e9 + 7;

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    vector<lli> dp(n, 1);
    lli prod = str[0] != 'm' && str[0] != 'w';
    forr(i, 1, n)
    {
        if (str[i] == 'n' || str[i] == 'u')
        {
            if (str[i] == str[i - 1])
            {
                if (i == 1)
                    dp[i] = 2;
                else
                {
                    dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
                }
                continue;
            }
        }
        dp[i] = dp[i - 1];
        if (str[i] == 'm')
            prod = 0;
    }

    printf("%lld", prod * dp[n - 1]);
}