#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

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

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vi vec(n);
    frange(i, n)
    {
        scd(vec[i]);
    }
    int sq = sqrt(n);
    vii dist(n);

    for (int i = 0; i < n; i += sq)
    {
        for (int j = min(n - 1, i + sq - 1); j >= i; --j)
        {
            if (j + vec[j] <= min(n - 1, i + sq - 1))
            {
                dist[j].f = dist[j + vec[j]].f + 1;
                dist[j].s = dist[j + vec[j]].s;
            }
            else
            {
                dist[j].f = 1;
                dist[j].s = j;
            }
        }
    }

    frange(i, m)
    {
        int t;
        scd(t);
        if (t)
        {
            int a;
            scd(a);
            --a;

            int tot = 0;
            int l = a;
            for (int p = a; p < n; p = dist[p].s + vec[dist[p].s])
            {
                tot += dist[p].f;
                l = dist[p].s;
            }
            printf("%d %d\n", l + 1, tot);
        }
        else
        {
            int a, b;
            scd(a);
            --a;
            scd(b);
            vec[a] = b;
            int v = a / sq;
            // if (a + vec[a] < n && (a + vec[a]) / sq == v)
            // {
            //     dist[a].f = dist[a + vec[a]].f + 1;
            //     dist[a].s = dist[a + vec[a]].s;
            // }
            // else
            // {
            //     dist[a].f = 1;
            //     dist[a].s = a + vec[a];
            // }
            for (int j = min(n - 1, a); j >= v * sq; --j)
            {
                if (j + vec[j] <= min(n - 1, v * sq + sq - 1))
                {
                    dist[j].f = dist[j + vec[j]].f + 1;
                    dist[j].s = dist[j + vec[j]].s;
                }
                else
                {
                    dist[j].f = 1;
                    dist[j].s = j;
                }
            }
        }
    }
}