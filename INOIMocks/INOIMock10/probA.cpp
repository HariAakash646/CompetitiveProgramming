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

vi disset;
vi depth;
vll sze;
lli inc = 0;

int findf(int x)
{
    while (x != disset[x])
    {
        x = disset[x];
    }
    return x;
}

void unionf(int u, int v)
{
    u = findf(u);
    v = findf(v);
    if (depth[u] < depth[v])
        swap(u, v);
    depth[u] = max(depth[u], 1 + depth[v]);
    inc += sze[u] * sze[v] - 1;
    sze[u] += sze[v];
    disset[v] = u;
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    disset = depth = vi(n + 1, 1);
    sze = vll(n + 1, 1);
    forr(i, 0, n + 1) disset[i] = i;
    set<pii> edges;
    frange(i, m)
    {
        int u, v;
        scd(u);
        scd(v);
        if (edges.count({u, v}) || edges.count({v, u}))
        {
        }
        else if (findf(u) == findf(v))
        {
            inc--;
        }
        else
        {
            unionf(u, v);
        }
        edges.insert({u, v});
        printf("%lld\n", inc);
    }
}