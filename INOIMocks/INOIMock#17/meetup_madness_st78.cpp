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
typedef vector<bool> vb;
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
    frange(i, n - 1)
    {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        graph[a].pb({b, c});
        graph[b].pb({a, c});
    }
    queue<pii> qp;
    qp.push({1, 1});
    vvi depth;
    vi depv(n + 1, -1);
    vb vis(n + 1, false);
    while (qp.size())
    {
        pii p = qp.front();
        qp.pop();
        vis[p.f] = true;
        depv[p.f] = p.s;
        for (auto e : graph[p.f])
        {
            if (!vis[e.f])
            {
                qp.push(pii{e.f, p.s + 1});
            }
        }
    }
    frange(_, q)
    {
        int x, y;
        scd(x);
        scd(y);
        if (depv[y] > depv[x])
            swap(x, y);
        lli xtot = 0, ytot = 0;
        lli tot = 0;
        vi xpath, ypath;
        while (depv[x] > depv[y])
        {
            for (auto e : graph[x])
            {
                if (depv[e.f] < depv[x])
                {
                    x = e.f;
                    tot += e.s;
                    xtot += e.s;
                    xpath.pb(e.s);
                    break;
                }
            }
        }
        while (x != y)
        {
            for (auto e : graph[x])
            {
                if (depv[e.f] < depv[x])
                {
                    x = e.f;
                    tot += e.s;
                    xtot += e.s;
                    xpath.pb(e.s);
                    break;
                }
            }
            for (auto e : graph[y])
            {
                if (depv[e.f] < depv[y])
                {
                    y = e.f;
                    tot += e.s;
                    ytot += e.s;
                    ypath.pb(e.s);
                    break;
                }
            }
        }
        // reverse(all(xpath)); reverse(all(ypath));
        if (xtot > ytot)
        {
            swap(xtot, ytot);
            swap(xpath, ypath);
        }
        ypath.pb(0);
        int idx = ypath.size() - 2;
        while (xtot < ytot)
        {
            xtot += ypath[idx];
            ytot -= ypath[idx];
            idx--;
        }
        printf("%lld\n", min(xtot, ytot + ypath[idx + 1]));
        // sort(all(path), greater<int>());
        // lli mid = tot / 2 + (tot % 2);
        // lli c = 0;
        // for (auto e : path)
        // {
        //     // printf("%d ", e);
        //     if (c < mid)
        //         c += e;
        //     // else
        //     //     break;
        // }
    }
}