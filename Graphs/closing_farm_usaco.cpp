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
vi sze;
int root;
int c = 1;

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
        swap(x, y);
    disset[y] = x;
    sze[x] += sze[y];
    c = max(c, sze[x]);
    // if (x == root || y == root)
    //     c = max(sze[x], sze[y]);
}

int main()
{
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int n, m;
    scd(n);
    scd(m);
    vvi graph(n + 1);
    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vi quer(n);
    frange(i, n)
    {
        scd(quer[i]);
    }
    // reverse(all(quer));
    root = quer[0];
    disset = vi(n + 1);
    forr(i, 1, n + 1) disset[i] = i;
    sze = vi(n + 1, 1);
    vb vis(n + 1);
    vb out(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int e = quer[i];
        vis[e] = true;
        for (auto p : graph[e])
        {
            if (vis[p])
            {
                unionf(e, p);
            }
        }
        // c = *max_element(all(sze));
        // printf("%d %d\n", n - i, c);
        if (c == n - i)
            out[i] = true;
    }
    frange(i, n)
    {
        if (out[i])
            printf("YES\n");
        else
            printf("NO\n");
    }
}