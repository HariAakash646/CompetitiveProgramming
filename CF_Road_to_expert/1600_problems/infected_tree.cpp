// Not working
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
typedef vector<char> vc;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

vvi graph;
vi subsz;

int rec(int x, int prev)
{
    int ma = 0;
    if (graph[x].size() == 1 && x == 1)
    {
        return subsz[graph[x][0]];
    }
    else if (graph[x].size() == 1)
    {
        return 0;
    }
    else if (graph[x].size() == 2 && x != 1)
    {
        for (auto e : graph[x])
        {
            if (e != prev)
            {
                return subsz[e];
            }
        }
    }
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            for (auto p : graph[x])
            {
                if (p != e && p != prev)
                    ma = max(ma, rec(e, x) + subsz[p]);
            }
        }
    }
    return ma;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        graph = vvi(n + 1);
        frange(i, n - 1)
        {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }
        subsz = vi(n + 1);
        queue<pii> q;
        forr(i, 2, n + 1)
        {
            if (graph[i].size() == 1)
                q.push({i, -1});
        }
        while (q.size())
        {
            pii p = q.front();
            q.pop();
            for (auto e : graph[p.f])
            {
                if (e != p.s)
                {
                    subsz[e] += 1 + subsz[p.f];
                    q.push({e, p.f});
                }
            }
        }
        // int prev = -1;
        // int x = 1;
        // int tot = 0;
        // int i = 0;
        // while (true)
        // {
        //     if ((graph[x].size() == 1 && i == 0) || (graph[x].size() == 2 && i != 0))
        //     {
        //         for (auto e : graph[x])
        //         {
        //             if (x != prev)
        //             {
        //                 tot += subsz[e];
        //                 break;
        //             }
        //         }
        //     }
        //     else if (graph[x].size() == 1)
        //     {
        //         break;
        //     }
        //     else
        //     {
        //         int ma = 0;
        //         int id = -1;
        //         for (auto e : graph[x])
        //         {
        //             if (e != prev)
        //             {
        //                 if (subsz[e] >= ma)
        //                 {
        //                     ma = subsz[e];
        //                     id = e;
        //                 }
        //             }
        //         }
        //         int v;
        //         for (auto e : graph[x])
        //         {
        //             if (e != prev && e != id)
        //             {
        //                 v = e;
        //             }
        //         }
        //         prev = x;
        //         x = v;
        //         tot += ma;
        //     }
        //     i++;
        // }
        int tot = rec(1, -1);
        printf("%d\n", tot);
    }
}