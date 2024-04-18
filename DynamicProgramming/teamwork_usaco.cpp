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
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    int n, k;
    scd(n);
    scd(k);

    vi vec(n + 1);
    frange(i, n) scd(vec[i + 1]);

    vvi dp(n + 1, vi(k + 1));

    vvi ma(n + 1, vi(k + 1));
    vi mv(n + 1);

    forr(i, 1, n + 1)
    {
        forr(j, 1, k + 1)
        {
            if (i >= j)
            {
                ma[i][j] = max(vec[i], ma[i - 1][j - 1]);
                dp[i][j] = mv[i - j] + ma[i][j] * j;
                mv[i] = max(mv[i], dp[i][j]);
            }
        }
    }
    printf("%d", mv[n]);
}