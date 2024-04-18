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

lli inf = 1e18 + 10;

vector<vii> graph;
vll vec;
vector<map<lli, lli>> major;
lli tot = 0;
int c = 0;
vll tim;
vll pref;

void dfs(int x, int v, lli t)
{
    tim[x] = t;
    if (c != 0 && x == v)
    {
        return;
    }
    if (c == 0)
        pref[c] = vec[x];
    else
        pref[c] = pref[c - 1] + vec[x];
    c++;
    for (auto e : graph[x])
    {
        dfs(e.f, v, t + e.s);
    }
}

int main()
{
    int n, m, k;
    lli l;
    scd(n);
    scd(m);
    sclld(l);
    scd(k);
    if (l <= 5)
    {

        vll vec(n + 1);
        forr(i, 1, n + 1) sclld(vec[i]);

        vector<vii> graph(n + 1);
        frange(i, m)
        {
            int a, b, t;
            scd(a);
            scd(b);
            scd(t);
            graph[a].pb({b, t});
        }

        vector<vll> major(n + 1, vll(l + 1));

        frange(i, k)
        {
            int t, x;
            lli v;
            scd(t);
            scd(x);
            sclld(v);
            major[x][t] = v;
        }
        vector<vll> dist(n + 1, vll(l + 1, -1));
        priority_queue<pair<lli, pair<lli, lli>>> pq;

        vector<vb> vis(n + 1, vb(l + 1));

        pq.push(mp(vec[1], mp(1, 0)));
        dist[1][0] = vec[1];

        while (pq.size())
        {
            auto p = pq.top();
            pq.pop();
            if (vis[p.s.f][p.s.s])
                continue;
            vis[p.s.f][p.s.s] = true;
            for (auto e : graph[p.s.f])
            {
                if (p.s.s + e.s <= l)
                {
                    lli v = vec[e.f];
                    v += major[e.f][p.s.s + e.s];
                    if (p.f + v > dist[e.f][p.s.s + e.s])
                    {
                        dist[e.f][p.s.s + e.s] = p.f + v;
                        pq.push(mp(dist[e.f][p.s.s + e.s], mp(e.f, p.s.s + e.s)));
                    }
                }
            }
        }
        // if (dist[1][l] >= 0)
        // {
        printf("%lld", dist[1][l]);
    }
    else
    {
        vec = vll(n + 1);
        forr(i, 1, n + 1) sclld(vec[i]);

        graph = vector<vii>(n + 1);
        frange(i, m)
        {
            int a, b, t;
            scd(a);
            scd(b);
            scd(t);
            graph[a].pb({b, t});
        }

        major = vector<map<lli, lli>>(n + 1);

        frange(i, k)
        {
            int x;
            lli t, v;
            sclld(t);
            scd(x);
            sclld(v);
            major[x][t] = v;
        }
        tim = pref = vll(n + 1);
        dfs(1, 1, 0);
        // printf("%d\n", l / tim[1]);
        tot += (l / tim[1]) * pref[n - 1] + pref[l % tim[1]];
        if (l % tim[1] != 0)
        {
            printf("-1");
        }
        else
        {
            forr(i, 1, n + 1)
            {
                for (auto p : major[i])
                {
                    if (p.f % tim[1] == tim[i] % tim[1])
                        tot += p.s;
                }
            }
            printf("%lld", tot);
        }
    }
}