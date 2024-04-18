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
int l, b;

bool dfs(int x, int par)
{
    int c = 0;
    bool bud = true;
    for (auto e : graph[x])
    {
        if (e != par)
        {
            bud = bud && dfs(e, x);
            c++;
        }
    }
    if (c == 0)
    {
        l++;
        return true;
    }
    if (bud)
        b++;
    return false;
}

int main()
{
    int t;
    scd(t);

    frange(_, t)
    {
        int n;
        scd(n);
        graph = vvi(n + 1);

        frange(i, n - 1)
        {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
        }
        l = 0;
        b = 0;
        dfs(1, 0);
        printf("%d\n", l - (b - 1));
    }
}