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
    int t;
    scd(t);
    frange(_, t)
    {
        int n, m;
        scd(n);
        scd(m);
        vi vec(n + 1);
        vii hgt(n);
        forr(i, 1, n + 1)
        {
            scd(vec[i]);
            hgt[i - 1] = {vec[i], i};
        };
        sort(all(hgt));

        vvi graph(n + 1);

        frange(i, m)
        {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }

        int q;
        scd(q);

        vector<pair<pii, pii>> quer(q);

        frange(i, q)
        {
            int u, v, e;
            scd(u);
            scd(v);
            scd(e);
            quer[i] = mp(mp(vec[u] + e, i), mp(u, v));
        }

        disset = sze = vi(n + 1, 1);
        frange(i, n + 1) disset[i] = i;

        sort(all(quer));

        vb out(q);
        auto it = hgt.begin();
        for (auto p : quer)
        {
            int h = p.f.f;
            auto it1 = upper_bound(all(hgt), mp(h, int(1e9)));
            for (; it != it1; it++)
            {
                for (auto e : graph[(*it).s])
                {
                    if (vec[e] <= h)
                    {
                        unionf((*it).s, e);
                    }
                }
            }
            if (findf(p.s.f) == findf(p.s.s))
                out[p.f.s] = true;
        }

        frange(i, q)
        {
            if (out[i])
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}