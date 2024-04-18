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

int main()
{
    string str;
    cin >> str;
    vvi graph(26 * 26 + 1);

    int n = str.size();
    forr(i, 1, n)
    {
        int c1 = str[i - 1] - 'a';
        int c2 = str[i] - 'a';
        graph[c1 * 26 + c2].pb(i);
    }
    int m;
    scd(m);
    vector<pair<pii, int>> quer(m);
    vi cnt(n);
    vector<vii> qg(n);
    frange(i, m)
    {
        scd(quer[i].f.f);
        scd(quer[i].f.s);
        if (quer[i].f.f > quer[i].f.s)
            swap(quer[i].f.f, quer[i].f.s);
        quer[i].s = i;
        cnt[quer[i].f.f]++;
        cnt[quer[i].f.s]++;
        qg[quer[i].f.f].pb(mp(quer[i].f.s, i));
        qg[quer[i].f.s].pb(mp(quer[i].f.f, i));
    }

    vi out(m);
    vb done(m);
    for (auto p : quer)
    {
        if (done[p.s])
            continue;
        int a = p.f.f;
        int b = p.f.s;
        if (cnt[a] < cnt[b])
        {
            swap(a, b);
        }

        queue<pii> q;
        vb vis(n + 1);
        q.push({a, 0});
        vi dist(n + 1);
        vb pos(26 * 26);
        while (q.size())
        {
            auto p = q.front();
            q.pop();
            if (vis[p.f])
                continue;
            vis[p.f] = true;
            dist[p.f] = p.s;
            int v = (str[p.f - 1] - 'a') * 26 + str[p.f] - 'a';

            if (!pos[v])
            {
                for (auto e : graph[v])
                    q.push({e, p.s + 1});
            }
            pos[v] = true;
            if (p.f + 1 < n)
                q.push(mp(p.f + 1, p.s + 1));
            if (p.f - 1 >= 1)
                q.push(mp(p.f - 1, p.s + 1));
        }

        for (auto e : qg[a])
        {
            if (done[e.s])
                continue;
            done[e.s] = true;
            out[e.s] = dist[e.f];
            cnt[e.f]--;
        }
        cnt[a] = 0;
    }
    for (auto e : out)
        printf("%d\n", e);
}