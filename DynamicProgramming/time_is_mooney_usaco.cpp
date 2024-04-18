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
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    int n, m, c;
    scd(n);
    scd(m);
    scd(c);

    vi vec(n + 1);
    frange(i, n) scd(vec[i + 1]);
    vvi graph(n + 1);

    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[b].pb(a);
    }

    vvi dp(n + 1, vi(1001, -1e8));
    dp[1][0] = 0;

    forr(i, 1, 1001)
    {
        forr(j, 1, n + 1)
        {
            for (auto e : graph[j])
            {
                dp[j][i] = max(dp[j][i], dp[e][i - 1] + vec[j]);
            }
        }
    }

    int ma = 0;

    forr(i, 0, 1001)
    {
        ma = max(ma, dp[1][i] - c * i * i);
    }
    printf("%d", ma);
}