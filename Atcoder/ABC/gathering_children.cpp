// Got idea. But tricky to implement.
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

vi graph;
vb vis;
seti cyc;
map<int, mpii> mpt;

void dfs(int x)
{
    if (vis[x])
    {
        cyc.insert(x);
        return;
    }
    vis[x] = true;
    for (auto e : graph[x])
    {
        dfs(e);
    }
}

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    graph = vi(n);
    frange(i, n)
    {
        if (str[i] == 'L')
        {
            graph[i] = (i - 1);
        }
        else
        {
            graph[i] = (i + 1);
        }
    }

    vis = vb(n);
    for (auto)
}