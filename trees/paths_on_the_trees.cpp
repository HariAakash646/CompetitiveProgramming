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

vector<vll> dp;
vvi graph;
vll vec;

void dfs(int x, int prev, lli v)
{
    int c = 0;
    dp[x][0] = v * vec[x];
    dp[x][1] = (v + 1) * vec[x];
    for (auto e : graph[x])
    {
        if (e != prev)
            c++;
    }
    priority_queue<lli> pq;
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dfs(e, x, v / c);
            dp[x][0] += dp[e][0];
            dp[x][1] += dp[e][0];
            pq.push(dp[e][1] - dp[e][0]);
        }
    }
    if (c == 0)
        return;
    lli cn = (v / c) * c;
    // printf("%lld %lld %lld\n", cn, c, v);
    forr(i, cn, v)
    {
        if (!pq.size())
            break;
        auto p = pq.top();
        pq.pop();
        dp[x][0] += p;
        dp[x][1] += p;
    }
    if (pq.size())
        dp[x][1] += pq.top();
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        lli k;
        scd(n);
        sclld(k);
        vec = vll(n + 1);
        graph = vvi(n + 1);
        dp = vector<vll>(n + 1, vll(2));
        forr(i, 2, n + 1)
        {
            int a;
            scd(a);
            graph[a].pb(i);
            graph[i].pb(a);
        }
        forr(i, 1, n + 1) sclld(vec[i]);

        dfs(1, 0, k);
        printf("%lld\n", dp[1][0]);
    }
}