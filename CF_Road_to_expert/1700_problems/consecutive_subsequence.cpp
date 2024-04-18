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

int main()
{
    int n;
    scd(n);
    vi vec(n + 1);
    frange(i, n)
    {
        scd(vec[i + 1]);
    }
    vii dp(n + 1);
    mpii pos;
    forr(i, 1, n + 1)
    {

        dp[i].f = dp[pos[vec[i] - 1]].f + 1;
        dp[i].s = pos[vec[i] - 1];

        pos[vec[i]] = i;
    }
    int ma = 0;
    int v = -1;
    forr(i, 1, n + 1)
    {
        auto p = dp[i];
        if (p.f > ma)
        {
            ma = p.f;
            v = i;
        }
    }
    printf("%d\n", ma);
    vi out = {v};
    forr(i, 1, ma)
    {
        out.pb(dp[*prev(out.end())].s);
    }
    reverse(all(out));
    for (auto e : out)
    {
        printf("%d ", e);
    }
}