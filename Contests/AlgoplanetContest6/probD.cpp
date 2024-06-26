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

vvi tree;
vi subtree;

void dfs(int x, int pre)
{
    for (auto e : tree[x])
    {
        if (e != pre)
        {
            dfs(e, x);
            subtree[x] += subtree[e];
        }
    }
}

int main()
{
    int n;
    scd(n);
    if (n % 2)
    {
        printf("-1\n");
        return 0;
    }

    tree = vvi(n + 1);
    frange(_, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        tree[a].pb(b);
        tree[b].pb(a);
    }
    subtree = vi(n + 1, 1);
    dfs(1, 0);
    int c = 0;
    forr(i, 1, n + 1)
    {
        if (subtree[i] % 2 == 0)
            c++;
    }
    printf("%d", c - 1);
}