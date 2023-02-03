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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    int n, q;
    scd(n);
    scd(q);
    vector<vii> graph(n + 1);
    vector<lli> vec(n + 1);
    int w;
    frange(i, n - 1)
    {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        graph[a].pb({b, c});
        graph[b].pb({a, c});
        vec[i + 2] = c;
        w = c;
    }
    vector<lli> pref(n + 1);
    forr(i, 1, n + 1)
    {
        pref[i] = pref[i - 1] + vec[i];
    }

    frange(_, q)
    {
        int x, y;
        scd(x);
        scd(y);
        // if (x == y)
        // {
        //     printf("0\n");
        //     continue;
        // }
        // if (y == 1)
        //     swap(x, y);
        // if (x == 1)
        // {
        //     printf("%d\n", graph[y][0].s);
        // }
        // else
        // {
        //     printf("%d\n", max(graph[y][0].s, graph[x][0].s));
        // }

        if (y > x)
            swap(y, x);
        if (x - y < 2)
            printf("%lld\n", pref[x] - pref[y]);
        else
        {
            if ((x - y) % 2 == 0)
            {
                printf("%lld\n", (pref[x] - pref[y]) / 2);
            }
            else
            {
                lli mul = (x - y) / 2 + 1;
                printf("%lld\n", mul * w);
            }
        }
    }
}