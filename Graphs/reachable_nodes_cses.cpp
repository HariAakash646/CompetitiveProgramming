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

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vvi graph(n + 1);
    vi indeg(n + 1);
    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        indeg[b]++;
    }
    queue<int> q;
    forr(i, 1, n + 1)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    vi topo;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        topo.pb(x);
        for (auto e : graph[x])
        {
            indeg[e]--;
            if (indeg[e] == 0)
                q.push(e);
        }
    }
    reverse(all(topo));
    vector<bitset<50000 + 1>> dp(n + 1);
    for (auto x : topo)
    {
        // printf("%d\n", x);
        dp[x][x] = 1;
        for (auto e : graph[x])
        {
            dp[x] |= dp[e];
        }
    }
    forr(i, 1, n + 1) printf("%d ", dp[i].count());
}