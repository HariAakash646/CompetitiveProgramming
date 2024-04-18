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
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

vvii graph;
vi comp;
vb vis;
int imp;

void connected_comp(int x)
{
    comp.pb(x);
    vis[x] = true;
    for (auto e : graph[x])
    {
        if (!vis[e.f])
        {
            connected_comp(e.f);
        }
    }
}

bool dfs(int x, int r, vi &role)
{
    if (role[x])
    {
        if (role[x] != r)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    role[x] = r;
    if (r == -1)
        imp++;
    for (auto e : graph[x])
    {
        bool out = dfs(e.f, e.s * r, role);
        if (!out)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    frange(_, t)
    {
        int n, m;
        cin >> n >> m;
        graph = vvii(n + 1);
        frange(i, m)
        {
            int r, a, b;
            cin >> r >> a >> b;
            if (r == 1)
            {
                graph[a].pb({b, -1});
                graph[b].pb({a, -1});
            }
            else
            {
                graph[a].pb({b, 1});
                graph[b].pb({a, 1});
            }
        }
        vvi con_comps;
        vis = vb(n + 1);
        forr(i, 1, n + 1)
        {
            if (!vis[i])
            {
                comp = {};
                connected_comp(i);
                con_comps.pb(comp);
            }
        }
        vi role1(n + 1);
        vi role2(n + 1);
        int tot = 0;
        bool done = true;
        for (auto v : con_comps)
        {
            int cnt = -1;
            imp = 0;
            bool out = dfs(v[0], 1, role1);
            if (out)
                cnt = max(cnt, imp);
            imp = 0;
            out = dfs(v[0], -1, role2);
            if (out)
                cnt = max(cnt, imp);
            if (cnt == -1)
            {
                cout << "-1\n";
                done = false;
                break;
            }
            tot += cnt;
        }
        if (done)
            cout << tot << "\n";
    }
}