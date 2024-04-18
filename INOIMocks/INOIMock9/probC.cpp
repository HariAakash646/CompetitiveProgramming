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

int n, k;
vvi graph;
vb vis;
vi dist;

bool dfs(int x, int prev, int l, int r)
{
    bool out = (l <= x && x <= r);
    // printf("%d: ", x);
    // if (x > 1)
    //     printf("%d\n", x);
    for (auto e : graph[x])
    {

        if (e != prev)
        {
            // printf("%d ", e);
            bool v = dfs(e, x, l, r);
            out = out || v;
        }
    }
    // printf("\n");
    vis[x] = out;
    // if (out)
    //     printf("%d\n", x);
    return out;
}

int cnt(int l, int r)
{
    vis = vb(n + 1);
    dfs(l, -1, l, r);
    int c = 0;
    forr(i, 1, n + 1)
    {
        if (vis[i])
            c++;
    }
    return c;
}

bool check(int x)
{
    for (int i = 1; i + x - 1 <= n; i++)
    {
        int c = cnt(i, x + i - 1);
        // printf("%d %d %d\n", i, x + i - 1, c);
        if (c <= k)
            return true;
    }
    return false;
}

void dfs2(int x, int prev)
{
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dist[e] = 1 + dist[x];
            dfs2(e, x);
        }
    }
}

bool check2(int x)
{
    seti st;
    forr(i, 1, x + 1) st.insert(dist[i]);
    int mi = (*prev(st.end()) - *st.begin() + 1);
    for (int i = 2; i + x - 1 <= n; i++)
    {
        st.erase(dist[i - 1]);
        st.insert(dist[i + x - 1]);
        mi = min(mi, *prev(st.end()) - *st.begin() + 1);
    }
    return mi <= k;
}

int main()
{

    scd(n);
    scd(k);

    graph = vvi(n + 1);

    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        a++;
        b++;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    if (k == 1)
        printf("1");
    else if (k == 2)
    {
        forr(i, 1, n + 1)
        {
            for (auto e : graph[i])
            {
                if (e == i + 1)
                {
                    printf("2");
                    return 0;
                }
            }
        }
        printf("1");
    }
    else if (n > 2000)
    {
        dist = vi(n + 1);
        forr(i, 1, n + 1)
        {
            if (graph[i].size() == 1)
            {
                dfs2(i, 0);
                break;
            }
        }
        int lo = 1;
        int hi = k;

        while (lo != hi)
        {
            int mid = (lo + hi + 1) / 2;
            if (check2(mid))
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }
        printf("%d", lo);
    }
    else
    {
        int lo = 1;
        int hi = k;

        while (lo != hi)
        {
            int mid = (lo + hi + 1) / 2;
            if (check(mid))
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }
        printf("%d", lo);
    }
}