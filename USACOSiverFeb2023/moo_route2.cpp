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

int inf = 1e9 + 10;

vector<set<pair<pii, pii>>> graph;
set<pair<pii, pii>> routes;
vb visrou;
vi vec, wait;

void dfs(int x, int t)
{
    for (auto e : graph[x])
    {
        if (e.s.f >= t && !visrou[e.f.s])
        {
            visrou[e.f.s] = true;
            graph[x].erase(e);
            vec[e.f.f] = min(vec[e.f.f], e.s.s);
            dfs(e.f.f, e.s.s + wait[e.f.f]);
        }
    }
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    graph = vector<set<pair<pii, pii>>>(n + 1);
    vec = vi(n + 1, inf);
    vec[1] = 0;
    wait = vi(n + 1);
    visrou = vb(m + 1, false);
    frange(i, m)
    {
        int c, r, d, j;
        scd(c);
        scd(r);
        scd(d);
        scd(j);
        graph[c].insert(mp(mp(d, i + 1), mp(r, j)));
    }
    frange(i, n)
    {
        scd(wait[i + 1]);
    }
    dfs(1, 0);
    forr(i, 1, n + 1)
    {
        if (vec[i] == inf)
            printf("-1\n");
        else
            printf("%d\n", vec[i]);
    }
}