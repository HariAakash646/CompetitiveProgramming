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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
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

vvi graph;
vector<bool> visited;
vector<int> con;
int pos;
int dfs(int node)
{
    int vis_count = 1;
    visited[node] = true;
    con[pos] = node;
    pos++;
    for (auto e : graph[node])
    {
        if (!visited[e])
        {

            vis_count += dfs(e);
        }
    }
    return vis_count;
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    graph = vvi(n + 1);

    int a, b;
    frange(i, m)
    {
        scd(a);
        scd(b);
        graph[a].PB(b);
    }
    forr(i, 1, n + 1, 1)
    {
        con = vi(n + 1);
        pos = 0;
        visited = vector<bool>(n + 1, false);
        int vis_count = dfs(i);
        seti cons(con.begin(), con.end());
        if (vis_count < n)
        {
            cout << "NO\n";
            cout << i << " ";
            forr(j, 1, n + 1, 1)
            {
                auto itr = cons.find(j);
                if (itr == cons.end())
                {
                    cout << j;
                    return 0;
                }
            }
        }
    }

    cout << "YES";

    return 0;
}