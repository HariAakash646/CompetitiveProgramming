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

vi disset, sze;
vector<vii> graph;

int findf(int x)
{
    while (x != disset[x])
    {
        x = disset[x];
    }
    return x;
}

bool unionf(int x, int y, int v)
{
    x = findf(x);
    y = findf(y);
    if (x == y)
        return false;
    if (sze[x] < sze[y])
    {
        swap(x, y);
    }

    disset[y] = x;
    sze[x] = max(sze[x], sze[y] + 1);
    return true;
}

void dfs(int x, int pre, vll &dist)
{
    for (auto e : graph[x])
    {
        if (e.f != pre)
        {
            dist[e.f] = dist[x] + e.s;
            dfs(e.f, x, dist);
        }
    }
}

int main()
{
    int n;
    scd(n);
    vvi mat(n, vi(n));
    vector<pair<int, pii>> vec;
    frange(i, n)
    {
        frange(j, n)
        {
            scd(mat[i][j]);
            if (i != j)
            {
                vec.pb(mp(mat[i][j], mp(i, j)));
            }
        }
    }

    sort(all(vec));

    disset = sze = vi(n);
    graph = vector<vii>(n);

    frange(i, n) disset[i] = i;

    for (auto p : vec)
    {
        if (p.f <= 0)
        {
            printf("NO");
            return 0;
        }
        bool out = unionf(p.s.f, p.s.s, p.f);
        if (out)
        {
            graph[p.s.f].pb({p.s.s, p.f});
            graph[p.s.s].pb({p.s.f, p.f});
        }
    }

    frange(i, n)
    {
        vll dist(n);
        dfs(i, -1, dist);
        frange(j, n)
        {
            if (dist[j] != mat[i][j])
            {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
}