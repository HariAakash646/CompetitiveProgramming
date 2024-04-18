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
    scd(m);
    vector<pair<int, pii>> edges(m);

    frange(i, m)
    {
        scd(edges[i].s.f);
        scd(edges[i].s.s);
        scd(edges[i].f);
    }
    sort(all(edges));

    vi dp(n + 1);
    mpii tmp;
    int prev = -1;
    for (auto p : edges)
    {
        if (p.f != prev)
        {
            for (auto e : tmp)
            {
                dp[e.f] = e.s;
            }
            tmp = {};
            tmp[p.s.s] = max(tmp[p.s.s], max(dp[p.s.s], dp[p.s.f] + 1));
            prev = p.f;
        }
        else
        {
            tmp[p.s.s] = max(tmp[p.s.s], max(dp[p.s.s], dp[p.s.f] + 1));
        }
    }
    for (auto e : tmp)
        dp[e.f] = e.s;
    printf("%d", *max_element(all(dp)));
}