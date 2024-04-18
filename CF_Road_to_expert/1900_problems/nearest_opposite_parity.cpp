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

int main()
{
    int n;
    scd(n);
    vi vec(n);
    frange(i, n) scd(vec[i]);
    vvi graph(n);

    frange(i, n)
    {
        if (i + vec[i] < n)
        {
            graph[i + vec[i]].pb(i);
        }
        if (i - vec[i] >= 0)
        {
            graph[i - vec[i]].pb(i);
        }
    }
    vi deve(n, -1), dodd(n, -1);
    queue<pii> q;
    frange(i, n)
    {
        if (vec[i] % 2)
            q.push({i, 0});
    }
    vb vis(n);
    while (q.size())
    {
        auto x = q.front();
        q.pop();
        if (vis[x.f])
            continue;
        vis[x.f] = true;
        deve[x.f] = x.s;
        for (auto e : graph[x.f])
        {
            q.push({e, x.s + 1});
        }
    }

    frange(i, n)
    {
        if (vec[i] % 2 == 0)
            q.push({i, 0});
    }
    vis = vb(n);
    while (q.size())
    {
        auto x = q.front();
        q.pop();
        if (vis[x.f])
            continue;
        vis[x.f] = true;
        dodd[x.f] = x.s;
        for (auto e : graph[x.f])
        {
            q.push({e, x.s + 1});
        }
    }

    frange(i, n)
    {
        if (vec[i] % 2)
            printf("%d ", dodd[i]);
        else
            printf("%d ", deve[i]);
    }
}