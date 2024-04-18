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

lli intersect(pair<pii, pair<lli, int>> x, pair<pii, pair<lli, int>> y)
{
    return min(x.f.s, y.f.s) - y.f.f + 1;
}

lli inf = 1e18;

int main()
{
    int n, m;
    scd(n);
    scd(m);
    lli w;
    sclld(w);

    vector<pair<pii, pair<lli, int>>> vec(m);
    multiset<pair<pii, pair<lli, int>>> st;

    frange(i, m)
    {
        scd(vec[i].f.f);
        scd(vec[i].f.s);
        sclld(vec[i].s.f);
        vec[i].s.s = i;
        st.insert(vec[i]);
    }
    sort(all(vec));
    vll dist(m, inf);
    priority_queue<pair<lli, int>> pq;

    frange(i, m)
    {
        if (vec[i].f.f == 0)
        {
            dist[vec[i].s.s] = vec[i].s.f;
            pq.push({-dist[vec[i].s.s], vec[i].s.s});
        }
    }
    vb vis(m);

    while (pq.size())
    {
        auto p = pq.top();
        pq.pop();
        if (vis[p.s])
            continue;
        vis[p.s] = true;
        auto it1 = next(st.find(vec[p.s]));
        auto it = prev(it1);
        auto it2 = st.lower_bound(mp(mp(vec[p.s].f.s + 1, 0), mp(0, 0)));
        while (it1 != it2)
        {
            lli v = dist[p.s] + intersect(vec[p.s], *it1) * w + (*it1).s.f;
            if (v < dist[(*it1).s.s])
            {
                dist[(*it1).s.s] = v;
                pq.push({-dist[(*it1).s.s], (*it1).s.s});
            }
            it1++;
        }
        st.erase(it);
    }
    lli mi = inf;
    frange(i, m)
    {
        if (vec[i].f.s == n - 1)
            mi = min(mi, dist[vec[i].s.s]);
    }
    if (mi != inf)
        printf("%lld", mi);
    else
        printf("-1");
}