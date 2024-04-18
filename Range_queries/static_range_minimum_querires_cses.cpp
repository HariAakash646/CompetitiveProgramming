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

struct query
{
    int l, r, id;
};

int n, q;
vi vec;
vi ans;
vi lef, rig;

void rec(int l, int r, vector<query> quer)
{
    if (l > r)
        return;
    if (l == r)
    {
        for (auto q : quer)
        {
            ans[q.id] = vec[l];
        }
        return;
    }
    int m = (l + r + 1) / 2;

    lef[m - 1] = vec[m - 1];
    for (int i = m - 2; i >= l; i--)
    {
        lef[i] = min(lef[i + 1], vec[i]);
    }
    rig[m] = vec[m];
    forr(i, m + 1, r + 1)
    {
        rig[i] = min(rig[i - 1], vec[i]);
    }
    vector<query> lefvec, rigvec;
    for (auto q : quer)
    {
        if (q.l < m && q.r >= m)
        {
            ans[q.id] = min(lef[q.l], rig[q.r]);
            continue;
        }
        if (q.l >= m)
        {
            rigvec.pb(q);
        }
        else
        {
            lefvec.pb(q);
        }
    }
    rec(l, m - 1, lefvec);
    rec(m, r, rigvec);
}

int main()
{

    scd(n);
    scd(q);
    vec = vi(n);
    lef = rig = vi(n);
    frange(i, n)
    {
        scd(vec[i]);
    }
    vector<query> queries(q);
    ans = vi(q);
    frange(i, q)
    {
        scd(queries[i].l);
        scd(queries[i].r);
        queries[i].l--;
        queries[i].r--;
        queries[i].id = i;
    }
    rec(0, n - 1, queries);
    for (auto e : ans)
    {
        printf("%d\n", e);
    }
}