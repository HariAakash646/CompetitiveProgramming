#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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
    vi str(n + 1), wgt(n + 1), wt(n + 1);
    vii st;
    forr(i, 1, n + 1)
    {
        scd(str[i]);
        st.pb(mp(str[i], i));
    }
    sort(all(st));
    forr(i, 1, n + 1) scd(wt[i]);
    vi perm(n + 1);
    forr(i, 1, n + 1) scd(perm[i]);
    vi pos(n + 1);
    forr(i, 1, n + 1) pos[perm[i]] = i;
    forr(i, 1, n + 1)
    {
        wgt[i] = wt[perm[i]];
    }
    forr(i, 1, n + 1)
    {
        if (wgt[i] >= str[i] && i != perm[i])
        {
            printf("-1");
            return 0;
        }
    }
    vii out;
    for (auto p : st)
    {
        if (p.s != perm[p.s])
        {
            out.pb(mp(p.s, pos[p.s]));
            pos[perm[p.s]] = pos[p.s];
            perm[pos[p.s]] = perm[p.s];
        }
    }
    printf("%d\n", out.size());
    for (auto p : out)
        printf("%d %d\n", p.f, p.s);
}