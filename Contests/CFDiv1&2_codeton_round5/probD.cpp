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

int n, m;
vector<vector<pair<int, lli>>> graph;
vb curr;
vb vis;
void dfs(int x)
{
    // if (x == 1)
    //     return true;
    // if (curr[x])
    //     return true;
    if (vis[x])
        return;
    vis[x] = true;

    curr[x] = true;
    for (auto e : graph[x])
    {
        dfs(e.f);
    }

    // return out;
}

bool dfs1(int x)
{
    if (x == 1)
        return true;
    if (vis[x])
        return false;
    for (auto e : graph[x])
    {
        bool out = dfs1(e.f);
        if (out)
            return true;
    }
    return false;
}

int main()
{

    scd(n);
    scd(m);
    graph = vector<vector<pair<int, lli>>>(n + 1);

    frange(i, m)
    {
        int a, b;
        lli c;
        scd(a);
        scd(b);
        sclld(c);
        graph[a].pb({b, c});
        graph[b].pb({a, c});
    }
    vis = vb(n + 1);
    if (!dfs1(n))
    {
        printf("inf");
        return 0;
    }
    seti done;
    queue<int> q;
    q.push(n);
    lli t = 0;
    lli cn = 0;
    vector<pair<string, lli>> out;
    while (q.size())
    {
        int x = q.front();
        q.pop();

        done.insert(x);
        vector<pair<vb, lli>> vec;
        for (auto p : graph[x])
        {
            if (done.find(p.f) != done.end())
            {
                continue;
            }
            vis = vb(n + 1);
            curr = vb(n + 1);
            for (auto e : done)
                vis[e] = true;
            q.push(p.f);
            dfs(p.f);
            if (curr[1])
                vec.pb(mp(curr, p.s));
        }
        vb mark(vec.size(), false);
        frange(i, vec.size())
        {
            if (mark[i])
                continue;
            forr(j, i + 1, vec.size())
            {
                if (mark[j])
                    continue;
                bool inter = false;
                forr(k, 1, n + 1)
                {
                    if (vec[i].f[k] && vec[j].f[k])
                    {
                        inter = true;
                        mark[j] = true;
                        break;
                    }
                }
                if (inter)
                {
                    forr(k, 1, n + 1)
                    {
                        vec[i].f[k] = vec[i].f[k] || vec[j].f[k];
                    }
                    vec[i].s = min(vec[i].s, vec[j].s);
                }
            }
        }

        frange(i, vec.size())
        {
            pair<string, lli> v;
            if (mark[i])
                continue;
            forr(j, 1, n + 1)
            {
                if (vec[i].f[j])
                {
                    v.f += "1";
                }
                else
                    v.f += "0";
            }
            v.s = vec[i].s;
            t += v.s;
            out.pb(v);
        }
    }
    printf("%lld %lld\n", t, out.size());
    for (auto v : out)
    {
        cout << v.f << " " << v.s << "\n";
    }
}