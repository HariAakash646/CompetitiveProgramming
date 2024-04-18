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
    int n, m;
    cin >> n >> m;
    vector<vii> graph(n + 1);

    frange(i, m)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        graph[a].pb({b, c - 'a'});
        graph[b].pb({a, c - 'a'});
    }

    vector<vb> vis(n + 1, vb(n + 1));
    queue<pair<pii, int>> q;
    q.push(mp(mp(1, n), 0));
    int mi = 1e9 + 10;
    while (q.size())
    {
        auto p = q.front();
        q.pop();
        if (p.f.f == p.f.s)
        {
            mi = min(mi, p.s * 2);
        }

        if (vis[p.f.f][p.f.s])
            continue;
        vis[p.f.f][p.f.s] = true;
        vis[p.f.s][p.f.f] = true;

        for (auto e : graph[p.f.f])
        {
            if (e.f == p.f.s)
            {
                mi = min(mi, 2 * p.s + 1);
            }
            for (auto x : graph[p.f.s])
            {
                if (x.f == p.f.f)
                {
                    mi = min(mi, 2 * p.s + 1);
                }

                if (e.s == x.s)
                {
                    // if (e.f == x.f)
                    // {
                    //     cout << 2 * p.s + 2;
                    //     return 0;
                    // }
                    q.push(mp(mp(e.f, x.f), p.s + 1));
                }
            }
        }
    }
    if (mi == 1e9 + 10)
        cout << "-1";
    else
        cout << mi;
}