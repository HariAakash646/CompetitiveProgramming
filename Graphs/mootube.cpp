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

int findf(int x, vi &vec)
{
    while (x != vec[x])
    {
        x = vec[x];
    }
    return x;
}

void unionf(int x, int y, vi &vec, vi &ht, vi &siz)
{
    x = findf(x, vec);
    y = findf(y, vec);
    if (x == y)
        return;
    if (ht[x] < ht[y])
        swap(x, y);
    vec[y] = x;
    ht[x] = max(ht[x], ht[y] + 1);
    siz[x] += siz[y];
}

int main()
{
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n, q;
    scd(n);
    scd(q);
    set<pair<int, pii>> edges;
    frange(i, n - 1)
    {
        int a, b, r;
        scd(a);
        scd(b);
        scd(r);
        edges.insert(mp(-r, mp(a, b)));
    }
    set<pair<pii, int>> quer;
    frange(i, q)
    {
        int k, v;
        scd(k);
        scd(v);
        // printf("%d %d\n", k, v);
        quer.insert(mp(mp(-k, v), i));
    }
    vi disset(n + 1);
    vi ht(n + 1, 1);
    vi sz(n + 1, 1);
    vi out(q);
    forr(i, 1, n + 1)
    {
        disset[i] = i;
    }
    for (auto p : quer)
    {
        int k = -p.f.f;
        int v = p.f.s;
        int idx = p.s;
        vector<pair<int, pii>> er;
        for (auto e : edges)
        {
            if (-e.f >= k)
            {
                // printf("%d %d %d %d %d\n", -e.f, k, e.s.f, e.s.s, idx);
                unionf(e.s.f, e.s.s, disset, ht, sz);
                er.pb(e);
            }
            else
            {
                break;
            }
        }
        for (auto e : er)
        {
            edges.erase(e);
        }
        out[idx] = sz[findf(v, disset)] - 1;
    }
    for (auto e : out)
    {
        printf("%d\n", e);
    }
}