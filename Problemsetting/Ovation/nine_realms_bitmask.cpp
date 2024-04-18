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
    int n = 9;
    scd(n);
    vvi vec(n, vi(n));
    frange(i, n)
    {
        frange(j, n) scd(vec[i][j]);
    }
    int m;
    scd(m);
    vector<vii> graph(n);
    frange(i, m)
    {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        a--;
        b--;
        graph[a].pb({b, c});
    }
    vi dp(1 << n);
    forr(i, 1, 1 << n)
    {
        frange(j, n)
        {
            if (i & (1 << j))
            {
                int v = dp[i ^ (1 << j)] + vec[j][__builtin_popcount(i) - 1];
                for (auto e : graph[j])
                {
                    if (!(i & (1 << e.f)))
                        v += e.s;
                }
                dp[i] = max(dp[i], v);
            }
        }
    }
    printf("%d", dp[(1 << n) - 1]);
}