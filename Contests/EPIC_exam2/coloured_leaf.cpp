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
vi col;
vi dp;

seti dfs(int x, int par)
{
    seti curr;
    if (col[x])
        curr.insert(col[x]);
    for (auto e : graph[x])
    {
        if (e != par)
        {
            seti st = dfs(e, x);
            if (st.size() > curr.size())
                swap(st, curr);
            for (auto e : st)
                curr.insert(e);
        }
    }
    dp[x] = curr.size();
    return curr;
}

int main()
{
    int n, k;
    scd(n);
    scd(k);

    graph = vvi(n + 1);
    col = vi(n + 1);

    forr(i, 1, n + 1) scd(col[i]);
    forr(i, 2, n + 1)
    {
        int a;
        scd(a);
        graph[a].pb(i);
        graph[i].pb(a);
    }
    dp = vi(n + 1);
    dfs(1, 0);
    forr(i, 1, n + 1) printf("%d ", dp[i]);
}