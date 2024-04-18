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
    int h, w;
    cin >> h >> w;
    vector<string> vec(h);

    frange(i, h) cin >> vec[i];

    deque<pii> dq;
    vector<vb> vis(h, vb(w));

    vvi dist(h, vi(w, 0));
    dq.pb({0, 0});
    dist[0][0] = 1;
    vii pos;
    pos.pb({0, 1});
    pos.pb({0, -1});
    pos.pb({1, 0});
    pos.pb({-1, 0});
    int ans = 1;
    while (dq.size())
    {
        auto p = dq.front();
        dq.pop_front();
        if (vis[p.f][p.s])
            continue;
        vis[p.f][p.s] = true;
        ans = max(ans, dist[p.f][p.s]);
        for (auto e : pos)
        {
            if (0 <= p.f + e.f && p.f + e.f < h && 0 <= p.s + e.s && p.s + e.s < w && vec[p.f + e.f][p.s + e.s] != '.')
            {
                int w = 0;
                if (vec[p.f][p.s] != vec[p.f + e.f][p.s + e.s])
                {
                    w = 1;
                }
                if (dist[p.f + e.f][p.s + e.s] == 0)
                {
                    dist[p.f + e.f][p.s + e.s] = dist[p.f][p.s] + w;
                    if (w)
                        dq.pb({p.f + e.f, p.s + e.s});
                    else
                        dq.push_front({p.f + e.f, p.s + e.s});
                }
            }
        }
    }
    printf("%d", ans);
}