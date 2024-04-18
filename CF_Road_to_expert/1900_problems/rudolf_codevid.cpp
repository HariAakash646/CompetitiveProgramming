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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n, m;

int binnum(string &str)
{
    int v = 0;
    frange(i, n)
    {
        if (str[i] == '1')
            v += (1 << i);
    }
    return v;
}

int main()
{
    fastio();
    int t;
    cin >> t;
    frange(_, t)
    {

        cin >> n >> m;
        string str;
        cin >> str;
        int v = binnum(str);

        vector<pair<pii, int>> med(m);
        frange(i, m)
        {
            int d;
            string a, b;
            cin >> d >> a >> b;
            med[i] = mp(mp(binnum(a), binnum(b)), d);
        }
        vector<vii> graph(1 << n);
        frange(i, 1 << n)
        {
            for (auto p : med)
            {
                int x = (i ^ (i & p.f.f));
                x = (x | p.f.s);
                graph[i].pb(mp(x, p.s));
            }
        }
        vi dist((1 << n), 1e9);
        priority_queue<pii> pq;
        dist[v] = 0;
        pq.push(mp(0, v));

        vb vis(1 << n);

        while (pq.size())
        {
            auto p = pq.top();
            pq.pop();
            if (vis[p.s])
                continue;
            vis[p.s] = true;
            for (auto e : graph[p.s])
            {
                if (e.s + dist[p.s] < dist[e.f])
                {
                    dist[e.f] = e.s + dist[p.s];
                    pq.push({-dist[e.f], e.f});
                }
            }
        }
        if (dist[0] == 1e9)
            cout << "-1\n";
        else
            cout << dist[0] << "\n";
    }
}