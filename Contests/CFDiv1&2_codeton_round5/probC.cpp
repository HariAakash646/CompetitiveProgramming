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
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vector<vi> pos(n + 1);
        vi vec(n + 1);
        frange(i, n)
        {
            scd(vec[i]);
            pos[vec[i]].pb(i);
        }
        vector<set<int>> dp(n + 1);
        vi d(n + 1);
        for (int i = n - 1; i >= 0; i--)
        {
            if (dp[vec[i]].size())
            {
                if (d[i + 1] > *prev(dp[vec[i]].end()) - i + 1)
                    d[i] = d[i + 1];
                else
                    d[i] = *prev(dp[vec[i]].end()) - i + 1;
            }
            else
                d[i] = d[i + 1];
            dp[vec[i]].insert(d[i + 1] + i);
        }
        printf("%d\n", d[0]);
    }
}