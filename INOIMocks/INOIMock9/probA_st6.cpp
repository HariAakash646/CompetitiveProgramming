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

vvi graph;
vi indeg;
vb vis;
vb curr;

bool cycle(int x)
{
    if (curr[x])
        return true;
    if (vis[x])
        return false;
    vis[x] = true;
    curr[x] = true;
    for (auto e : graph[x])
    {
        bool out = cycle(e);
        if (out)
            return true;
    }
    curr[x] = false;
    return false;
}

int main()
{
    int n, quer;
    scd(n);
    scd(quer);
    vector<pair<pii, int>> query(quer);
    graph = vvi(n + 1);
    indeg = vi(n + 1);
    bool st2 = true;
    vi val(quer);
    frange(i, quer)
    {
        int l, r, c;
        scd(l);
        scd(r);
        scd(c);
        query[i] = mp(mp(l, r), c);

        val[i] = c;
        if (c != r)
            st2 = false;
    }
    vi vec(n + 1);
    if (st2)
    {
        sort(all(val), greater<int>());
        int v = 1;
        for (auto e : val)
        {
            if (!vec[e])
            {
                vec[e] = v;
                v++;
            }
        }
        forr(i, 1, n + 1)
        {
            if (!vec[i])
            {
                vec[i] = v;
                v++;
            }
        }
    }
    else
    {
        for (auto p : query)
        {
            int l = p.f.f;
            int r = p.f.s;
            int c = p.s;
            forr(k, l, r + 1)
            {
                if (k != c)
                {
                    indeg[k]++;
                    graph[c].pb(k);
                }
            }
        }
        vis = curr = vb(n + 1);
        forr(i, 1, n + 1)
        {
            bool out = cycle(i);
            if (out)
            {
                printf("-1");
                return 0;
            }
        }

        queue<int> q;
        forr(i, 1, n + 1)
        {
            if (indeg[i] == 0)
                q.push(i);
        }
        int v = 1;
        while (q.size())
        {
            auto p = q.front();
            q.pop();
            vec[p] = v;
            ++v;
            for (auto e : graph[p])
            {
                indeg[e]--;
                if (indeg[e] == 0)
                    q.push(e);
            }
        }
    }
    forr(i, 1, n + 1) printf("%d ", vec[i]);
}