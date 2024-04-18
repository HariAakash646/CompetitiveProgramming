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
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vvi graph(n + 1);
    vvi ingraph(n + 1);
    vi indeg(n + 1);
    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        ingraph[b].pb(a);
        indeg[b]++;
    }
    queue<int> q;
    forr(i, 1, n + 1)
    {
        if (!indeg[i])
            q.push(i);
    }
    vi topo;
    while (q.size())
    {
        int e = q.front();
        q.pop();
        topo.pb(e);
        for (auto x : graph[e])
        {
            indeg[x]--;
            if (!indeg[x])
                q.push(x);
        }
    }
    vi dp(n + 1);
    for (auto e : topo)
    {
        for (auto x : ingraph[e])
            dp[e] = max(dp[e], dp[x] + 1);
    }
    printf("%d", *max_element(all(dp)));
}