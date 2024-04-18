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
    int t;
    cin >> t;
    vi dp(1e5 + 1);
    dp[0] = 0;
    dp[1] = 1;
    forr(i, 2, 1e5 + 1)
    {
        dp[i] = dp[i / 2] + 1;
    }
    frange(_, t)
    {
        string str;
        cin >> str;
        int mi = 1e9;
        frange(i, 26)
        {
            int ma = 0;
            int curr = 0;
            frange(j, str.size())
            {
                if (str[j] == 'a' + i)
                {
                    ma = max(ma, curr);
                    curr = 0;
                }
                else
                    curr++;
            }
            ma = max(ma, curr);
            mi = min(mi, ma);
        }
        printf("%d\n", dp[mi]);
    }
}