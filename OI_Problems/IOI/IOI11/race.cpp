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

vector<seti> graph;
vector<int> lenv;
int mi = 1e9;

void dfs(int x, int par, int k, int l, int c, vi &cnt)
{
    for (auto e : graph[x])
    {
        if (e == par)
            conitnue;
        int l1 = l + lenv[e];
        if (k == l1)
        {
            mi = min(mi, c + 1);
        }
        if (k - l1 > 0 && cnt[k - l1])
        {
            mi = min(mi, cnt[k - l1] + c + 1);
        }
        dfs(e, x, k, l1, c + 1, cnt);
    }
}

void dfs2(int x, int par, int l, int c, vi &cnt)
{
    for (auto e : graph[x])
    {
        if (e == par)
            continue;
        int l1 = l + lenv[e];
        if (l1 < cnt.size())
        {
            cnt[l1] = min(cnt[l1], c + 1);
        }
        dfs2(e, x, l1, c + 1, cnt);
    }
}

int decomp()

    int best_path(int n, int k, int edges[][2], int len[])
{
    frange(i, n - 1)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        graph[a].insert(b);
        graph[b].insert(a);
    }
    frange(i, n) lenv[i] = len[i];
}