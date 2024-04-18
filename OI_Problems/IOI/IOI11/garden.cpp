#include <bits/stdc++.h>
#include <gardenlib.h>

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

vi graph;
vvi invg;
vi cnt1, cnt2;
vb vis;

void dfs(int x, int c, vi &cnt)
{
    if (vis[x])
        return;
    vis[x] = true;
    cnt[x] = c;
    for (auto e : invg[x])
    {
        dfs(e, c + 1, cnt);
    }
}

int cyc(int x, int v, int c)
{
    if (x == v && vis[x])
    {
        return c;
    }
    if (vis[x])
        return 0;
    vis[x] = true;
    for (auto e : invg[x])
    {
        int out = cyc(e, v, c + 1);
        if (out)
            return out;
    }
    return 0;
}

void count_routes(int n, int m, int p, int edges[][2], int q, int stud[])
{
    graph = vi(2 * n, -1);
    invg = vvi(2 * n);
    frange(i, m)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        if (graph[2 * a] == -1)
        {
            if (graph[2 * b] == -1)
            {
                graph[2 * a] = 2 * b + 1;
                graph[2 * b] = 2 * a + 1;
            }
            else
            {
                graph[2 * a] = 2 * b;
                if (graph[2 * b + 1] == -1)
                    graph[2 * b + 1] = 2 * a + 1;
            }
        }
        else
        {
            if (graph[2 * b] == -1)
            {
                graph[2 * b] = 2 * a;
                if (graph[2 * a + 1] == -1)
                    graph[2 * a + 1] = 2 * b + 1;
            }
            else
            {
                if (graph[2 * a + 1] == -1)
                    graph[2 * a + 1] = 2 * b;
                if (graph[2 * b + 1] == -1)
                    graph[2 * b + 1] = 2 * a;
            }
        }
    }
    frange(i, n)
    {
        if (graph[2 * i + 1] == -1)
            graph[2 * i + 1] = graph[2 * i];
    }
    // frange(i, 2 * n)
    // {
    //     if (graph[i] == -1)
    //         cout << i << "\n";
    // }
    frange(i, 2 * n)
    {
        invg[graph[i]].pb(i);
    }
    cnt1 = cnt2 = vi(2 * n, 1e9);
    vis = vb(2 * n);
    dfs(2 * p, 0, cnt1);
    vis = vb(2 * n);
    dfs(2 * p + 1, 0, cnt2);
    vis = vb(2 * n);
    int v1 = cyc(2 * p, 2 * p, 0);
    vis = vb(2 * n);
    int v2 = cyc(2 * p + 1, 2 * p + 1, 0);
    frange(i, q)
    {
        int x = stud[i];
        int c = 0;
        for (int j = 0; j < 2 * n; j += 2)
        {
            int k1 = x - cnt1[j];
            if (k1 >= 0 && v1 != 0)
            {
                k1 %= v1;
            }
            int k2 = x - cnt2[j];
            if (k2 >= 0 && v2 != 0)
                k2 %= v2;
            if (k1 == 0 || k2 == 0)
                c++;
        }
        answer(c);
        // cout << c << "\n";
    }
}

int main()
{
    int n, m, p, q;
    cin >> n >> m >> p;
    int edges[m][2];
    frange(i, m)
    {
        cin >> edges[i][0] >> edges[i][1];
    }
    cin >> q;
    int stud[q];
    frange(i, q)
    {
        cin >> stud[i];
    }
    count_routes(n, m, p, edges, q, stud);
}