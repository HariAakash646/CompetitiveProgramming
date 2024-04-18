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
    int n, m;
    scd(n);
    vi v1(n);
    frange(i, n)
    {
        scd(v1[i]);
    }
    scd(m);
    vi v2(m);
    frange(i, m)
    {
        scd(v2[i]);
    }
    vector<vector<pair<int, pii>>> dp(n, vector<pair<int, pii>>(m));
    vector<pair<int, pii>> cnt(n);
    frange(j, m)
    {
        frange(i, n)
        {
            if (v1[i] == v2[j])
            {
                int v = 0;
                pii pos = {-1, -1};
                frange(k, i)
                {
                    if (v1[k] < v1[i])
                    {
                        if (cnt[k].f > v)
                        {
                            v = cnt[k].f;
                            pos = cnt[k].s;
                        }
                    }
                }
                dp[i][j] = {v + 1, pos};
                cnt[i] = {v + 1, mp(i, j)};
            }
        }
    }
    vi out;
    int ma = 0;
    pii pos;
    frange(i, n)
    {
        frange(j, m)
        {
            if (dp[i][j].f > ma)
            {
                ma = dp[i][j].f;
                pos = {i, j};
            }
        }
    }
    frange(i, ma)
    {
        out.pb(v1[pos.f]);
        pos = dp[pos.f][pos.s].s;
    }
    reverse(all(out));
    printf("%d\n", ma);
    for (auto e : out)
        printf("%d ", e);
}