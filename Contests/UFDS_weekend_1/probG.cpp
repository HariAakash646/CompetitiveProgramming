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

vi disset, sze, cnt;

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
    cnt[x] = cnt[x] + cnt[y];
}

int main()
{
    int n, m, q;
    scd(n);
    scd(m);
    scd(q);
    vii edges(m + 1);
    vector<vii> graph(n + 1);

    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        edges[i + 1] = {min(a, b), max(a, b)};
        graph[a].pb({b, i + 1});
        graph[b].pb({a, i + 1});
    }

    vi dist(n + 1, 1e9);
    queue<pair<pii, pii>> qu;
    vi used(m + 1);
    qu.push(mp(mp(1, 0), mp(0, 0)));

    while (qu.size())
    {
        auto p = qu.front();
        qu.pop();
        if (dist[p.f.f] < p.f.s)
        {
            continue;
        }
        if (dist[p.f.f] == p.f.s)
        {
            used[p.s.f] = p.s.s;
            continue;
        }

        dist[p.f.f] = p.f.s;
        used[p.s.f] = p.s.s;

        for (auto e : graph[p.f.f])
        {
            if (e.f < p.f.f)
                qu.push(mp(mp(e.f, p.f.s + 1), mp(e.s, 2)));
            else
                qu.push(mp(mp(e.f, p.f.s + 1), mp(e.s, 1)));
        }
    }

    vi quer(q);
    vb qvis(m + 1);
    frange(i, q)
    {
        scd(quer[i]);
        qvis[quer[i]] = true;
    }

    vb con(n + 1);
    int c = 0;
    vvi dirg(n + 1);
    queue<int> q2;
    forr(i, 1, m + 1)
    {
        if (used[i] && !qvis[i])
        {
            if (used[i] == 1)
            {
                dirg[edges[i].f].pb(edges[i].s);
            }
            else
            {
                dirg[edges[i].s].pb(edges[i].f);
            }
        }
    }
    q2.push(1);
    while (q2.size())
    {
        auto x = q2.front();
        q2.pop();
        if (con[x])
            continue;
        con[x] = true;
        c++;
        for (auto e : dirg[x])
        {
            q2.push(e);
        }
    }
    vi out(q);
    forr(i, 1, q + 1)
    {
        int v = quer[q - i];

        out[q - i] = n - c;
        if (used[v])
        {
            int a = edges[v].f;
            int b = edges[v].s;

            if (used[v] == 1)
            {
                dirg[a].pb(b);
                if (con[a])
                {
                    q2.push(b);
                    while (q2.size())
                    {
                        auto x = q2.front();
                        q2.pop();
                        if (con[x])
                            continue;
                        con[x] = true;
                        c++;
                        for (auto e : dirg[x])
                        {
                            q2.push(e);
                        }
                    }
                }
            }
            else
            {
                dirg[b].pb(a);
                if (con[b])
                {
                    q2.push(a);
                    while (q2.size())
                    {
                        auto x = q2.front();
                        q2.pop();
                        if (con[x])
                            continue;
                        con[x] = true;
                        c++;
                        for (auto e : dirg[x])
                        {
                            q2.push(e);
                        }
                    }
                }
            }
        }
    }
    for (auto e : out)
        printf("%d\n", e);
}