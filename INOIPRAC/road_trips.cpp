#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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
vll vec;
vb vis;
lli v = 0;

void dfs(int x)
{
    v += vec[x];
    vis[x] = true;
    for (auto e : graph[x])
    {
        if (!vis[e])
        {
            dfs(e);
        }
    }
}

int main()
{
    int t;
    scd(t);

    frange(_, t)
    {
        int n, m, k;
        scd(n);
        scd(m);
        scd(k);

        graph = vvi(n + 1);
        frange(i, m)
        {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }

        vec = vll(n + 1);
        forr(i, 1, n + 1) sclld(vec[i]);
        vll val;
        vis = vb(n + 1);

        forr(i, 1, n + 1)
        {
            if (!vis[i])
            {
                v = 0;
                dfs(i);
                val.pb(v);
            }
        }
        sort(all(val));
        int i1 = 0;
        int i2 = val.size() - 1;
        if (val.size() < k)
        {
            printf("-1\n");
        }
        else
        {
            lli tot = 0;
            frange(i, k)
            {
                if (i % 2)
                {
                    tot += val[i1];
                    i1++;
                }
                else
                {
                    tot += val[i2];
                    i2--;
                }
            }
            printf("%lld\n", tot);
        }
    }
}