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
    int t;
    scd(t);
    frange(_, t)
    {
        int n, m;
        scd(n);
        scd(m);
        map<pii, int> route;
        vvi graph(n + 1);
        frange(i, m)
        {
            int a, b;
            scd(a);
            scd(b);
            if (a > b)
                swap(a, b);
            route[{a, b}] = i;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        int k = 2;
        if (m == n * (n - 1) / 2)
        {
            k = 3;
        }
        vi vec(m, 1);
        if (k == 2)
        {
            forr(i, 1, n + 1)
            {
                if (graph[i].size() < n - 1)
                {
                    for (auto e : graph[i])
                    {
                        vec[route[{min(e, i), max(e, i)}]] = 2;
                    }
                    break;
                }
            }
        }
        else
        {
            for (auto e : graph[1])
            {
                vec[route[{1, e}]] = 2;
            }
            vec[route[{1, 2}]] = 3;
        }
        printf("%d\n", k);
        for (auto e : vec)
        {
            printf("%d ", e);
        }
        printf("\n");
    }
}