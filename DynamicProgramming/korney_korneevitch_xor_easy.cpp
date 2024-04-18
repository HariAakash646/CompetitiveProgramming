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
    int m = (1 << 9);
    vi vec(n);
    frange(i, n)
    {
        scd(vec[i]);
    }

    vector<vb> dp(501, vb(m));
    dp[0][0] = true;
    for (auto e : vec)
    {
        forr(i, 0, m)
        {
            dp[e][e] = true;
            if (e > 0)
            {
                dp[e][i] = dp[e - 1][i];
                dp[e][i] = dp[e][i] || dp[e - 1][i ^ e];
            }
        }
    }
    seti out;
    forr(i, 0, 501)
    {
        forr(j, 0, m)
        {
            if (dp[i][j])
                out.insert(j);
        }
    }
    printf("%d\n", out.size());
    for (auto e : out)
        printf("%d ", e);
}