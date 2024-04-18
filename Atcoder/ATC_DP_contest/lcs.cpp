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
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size();
    int n2 = s2.size();
    vvi dp(n1 + 1, vi(n2 + 1));

    forr(i, 1, n1 + 1)
    {
        forr(j, 1, n2 + 1)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    int m1 = n1;
    int m2 = n2;
    string out;
    while (m1 > 0 && m2 > 0)
    {

        if (dp[m1][m2] == dp[m1 - 1][m2])
            --m1;
        else if (dp[m1][m2] == dp[m1][m2 - 1])
            --m2;
        else
        {
            --m1;
            --m2;
            out += s1[m1];
        }
    }
    reverse(all(out));
    cout << out;
}