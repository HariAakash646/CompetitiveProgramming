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
    }
    disset = sze = vi(n + 1, 1);
    frange(i, n + 1) disset[i] = i;
    forr(i, 1, n + 1)
    {
        forr(j, 1, graph[i].size())
        {
            unionf(graph[i][j], graph[i][j - 1]);
        }
    }
    vi out(n + 1);
    int c = 1;
    forr(i, 1, n + 1)
    {
        int x = findf(i);
        if (out[x])
        {
            out[i] = out[x];
            // if (graph[i].size() && graph[x].size())
            // {
            //     unionf(graph[i][0], graph[x][0]);
            // }
        }
        else
        {
            out[i] = c;
            out[x] = c;
            c++;
        }
    }
    forr(i, 1, n + 1) printf("%d\n", out[i]);
}