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

void usaco()
{
    freopen("movie.in", "r", stdin);
    freopen("movie.out", "w", stdout);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    usaco();
    int n, l;
    scd(n);
    scd(l);

    vector<pair<lli, lli>> vec(n);
    vector<vll> show(n);

    frange(i, n)
    {
        sclld(vec[i].f);
        sclld(vec[i].s);
        frange(j, vec[i].s)
        {
            lli a;
            sclld(a);
            show[i].pb(a);
        }
    }

    vector<vll> dp(1 << n, vll(n));
    vll ma(1 << n);

    forr(i, 1, 1 << n)
    {
        frange(j, n)
        {
            if (i & (1 << j))
            {

                auto itr = upper_bound(all(show[j]), ma[i ^ (1 << j)]);
                if (itr != show[j].begin())
                {
                    dp[i][j] = max(dp[i][j], *prev(itr) + vec[j].f);
                }
            }
            else
                dp[i][j] = -1e9;
            ma[i] = max(ma[i], dp[i][j]);
        }
    }

    int mi = 1e9;
    forr(i, 1, 1 << n)
    {
        frange(j, n)
        {
            if (dp[i][j] >= l)
            {
                mi = min(mi, __builtin_popcount(i));
            }
        }
    }
    if (mi == 1e9)
        printf("-1");
    else
        printf("%d", mi);
}