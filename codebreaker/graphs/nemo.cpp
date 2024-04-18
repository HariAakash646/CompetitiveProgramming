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

int inf = 2e9;

vi disset, sze;

int findf(int x)
{
    while (x != disset[x])
    {
        x = disset[x];
    }
    return x;
}

void unionf(int x, int y)
{
    x = findf(x);
    y = findf(y);
    if (x == y)
        return;
    if (sze[x] < sze[y])
    {
        swap(x, y);
    }
    disset[y] = x;
    sze[x] = max(sze[x], sze[y] + 1);
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int n, e;
    scd(n);
    scd(e);
    vector<pair<int, pii>> enter(e), exit(e);
    int maent = 0;
    int miex = inf;
    frange(i, e)
    {
        int a, b, o, c;
        scd(a);
        scd(b);
        scd(o);
        scd(c);
        enter[i] = mp(o, mp(a, b));
        exit[i] = mp(-c, mp(a, b));
        maent = max(maent, o);
        miex = max(miex, c);
    }
    int tc;
    scd(tc);
    vector<pair<pii, pii>> ent, ex;

    frange(i, tc)
    {
        int x, y, t;
        scd(x);
        scd(y);
        scd(t);
        if (t <= maent)
        {
            ent.pb(mp(mp(t, i), mp(x, y)));
        }
        else
        {
            ex.pb(mp(mp(-t, i), mp(x, y)));
        }
    }

    disset = sze = vi(n);
    forr(i, 0, n)
    {
        disset[i] = i;
    }
    sort(all(ent));
    sort(all(enter));
    int vis = -1;
    vb out(tc);
    for (auto p : ent)
    {
        int id = upper_bound(all(enter), mp(p.f.f, mp(inf, inf))) - enter.begin() - 1;
        forr(i, vis + 1, min(int(enter.size()), id + 1))
        {
            unionf(enter[i].s.f, enter[i].s.s);
        }
        vis = id;
        if (findf(p.s.f) == findf(p.s.s))
        {
            out[p.f.s] = true;
        }
    }
    sort(all(exit));
    sort(all(ex));
    disset = sze = vi(n);
    forr(i, 0, n)
    {
        disset[i] = i;
    }
    vis = -1;
    for (auto p : ex)
    {
        int id = upper_bound(all(exit), mp(p.f.f, mp(inf, inf))) - exit.begin() - 1;
        forr(i, vis + 1, min(int(exit.size()), id + 1))
        {
            unionf(exit[i].s.f, exit[i].s.s);
        }
        vis = id;
        if (findf(p.s.f) == findf(p.s.s))
        {
            out[p.f.s] = true;
        }
    }
    for (auto e : out)
    {
        if (e)
        {
            printf("Y\n");
        }
        else
        {
            printf("N\n");
        }
    }
}