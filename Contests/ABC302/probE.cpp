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
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

int main()
{
    int n, q;
    scd(n);
    scd(q);
    vi deg(n + 1);
    vector<seti> graph(n + 1);
    int c = n;
    frange(_, q)
    {
        int t;
        scd(t);
        if (t == 1)
        {
            int u, v;
            scd(u);
            scd(v);
            graph[u].insert(v);
            graph[v].insert(u);
            // for (auto e : deg)
            // {
            //     printf("%d ", e);
            // }
            // printf("\n");
            if (deg[u] == 0)
                c--;
            if (deg[v] == 0)
                c--;
            deg[u]++;
            deg[v]++;
            printf("%d\n", c);
        }
        else
        {
            int v;
            scd(v);
            for (auto e : graph[v])
            {
                graph[e].erase(v);
                deg[e]--;
                if (deg[e] == 0)
                    c++;
            }
            if (graph[v].size() > 0)
                c++;
            graph[v] = {};
            deg[v] = 0;
            printf("%d\n", c);
        }
    }
}