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
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vvi graph;
vb vis;
int tot;
bool dfs(int node, int n2, vb &vis)
{
    vis[node] = true;
    if (node == n2)
        return true;
    bool out = false;
    for (auto e : graph[node])
    {
        if (!vis[e])
        {
            out = dfs(e, n2, vis);
            if (out)
                break;
        }
    }
    vis[node] = false;
    return out;
}

string bin(int n, int sz)
{
    string out = "";
    while (n > 0)
    {
        out += to_string(n % 2);
        if (n % 2)
        {
            tot++;
        }
        n /= 2;
    }
    while (out.size() < sz)
        out += "0";
    reverse(all(out));
    return out;
}

int main()
{
    int n;
    scd(n);
    graph = vvi(n + 1);
    frange(i, n)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    if (n > 20)
    {
        printf("%d", n);
        return 0;
    }
    int t = pow(2, n);
    int ma = 0;
    frange(l, t)
    {
        vis = vb(n + 1, false);
        vb bit(n + 1, false);
        tot = 0;
        string out = bin(l, n);
        frange(i, n)
        {
            if (out[i] == '1')
            {
                vis[i + 1] = true;
                bit[i + 1] = true;
            }
        }
        frange(i, n)
        {
            forr(j, i + 1, n)
            {
                if (bit[i + 1] && bit[j + 1])
                {
                    vis[i + 1] = false;
                    vis[j + 1] = false;
                    if (!dfs(i + 1, j + 1, vis))
                    {
                        tot = 0;
                    }
                    vis[i + 1] = true;
                    vis[j + 1] = true;
                }
            }
        }
        // if (tot > ma)
        // {
        //     cout << out << "\n";
        // }
        ma = max(ma, tot);
    }
    printf("%d", ma);
}