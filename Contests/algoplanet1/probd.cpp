#include <bits/stdc++.h>
#include <iostream>

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
#define MP make_pair
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
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);
    vi spec(k);
    frange(i, k)
    {
        scd(spec[i]);
    }
    vvi graph(n + 1);
    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    queue<pii> q;
    q.push({1, 0});
    vb proc(n + 1, false);
    vi dist1(n + 1, 0);
    while (q.size())
    {
        pii p = q.front();
        q.pop();
        if (proc[p.f])
            continue;
        proc[p.f] = true;
        dist1[p.f] = p.s;
        for (auto e : graph[p.f])
        {
            q.push({e, p.s + 1});
        }
    }
    q = {};
    q.push({n, 0});
    proc = vb(n + 1, false);
    vi distn(n + 1, 0);
    while (q.size())
    {
        pii p = q.front();
        q.pop();
        if (proc[p.f])
            continue;
        proc[p.f] = true;
        distn[p.f] = p.s;
        for (auto e : graph[p.f])
        {
            q.push({e, p.s + 1});
        }
    }
    int ma1 = 0, ma2 = 0;
    int secm1 = 0, secm2 = 0;
    int id1 = -1, id2 = -1;
    vector<pair<int, pii>> vec;
    for (auto e : spec)
    {
        int d1 = dist1[e];
        int dn = distn[e];
        vec.pb({d1 - dn, {d1, dn}});
    }
    sort(all(vec));
    vi sufmax(vec.size(), 0);
    sufmax[vec.size() - 1] = vec[vec.size() - 1].s.s;
    for (int i = vec.size() - 2; i >= 0; i--)
    {
        sufmax[i] = max(vec[i].s.s, sufmax[i + 1]);
    }
    int ma = 0;
    frange(i, vec.size())
    {
        ma = max(ma, vec[i].s.f + sufmax[i + 1]);
    }
    printf("%d", min(distn[1], ma));
    // printf("%d %d\n", dist1[2], distn[4]);
    // printf("%d %d\n", ma1, id1);
    // printf("%d %d\n", ma2, id2);
}