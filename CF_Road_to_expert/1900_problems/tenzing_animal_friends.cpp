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
    int n, m;
    scd(n);
    scd(m);
    vector<vector<pair<int, lli>>> graph(n + 1);

    frange(i, m)
    {
        int a, b;
        lli v;
        scd(a);
        scd(b);
        sclld(v);
        graph[a].pb({b, v});
        graph[b].pb({a, v});
    }

    lli t = 0;
    vb curr(n + 1);

    priority_queue<pair<lli, int>> pq;
    pq.push(mp(0, 1));
    vector<pair<string, int>> out;
    bool inf = true;
    while (pq.size())
    {
        auto p = pq.top();
        pq.pop();
        if (p.s == n)
        {
            inf = false;
            if (t != -p.f)
            {
                string str = "";
                forr(i, 1, n + 1)
                {
                    if (curr[i])
                        str += "1";
                    else
                        str += "0";
                }
                out.pb(mp(str, -p.f - t));
                t = -p.f;
            }
            t = -p.f;
            break;
        }
        if (curr[p.s])
            continue;
        if (t != -p.f)
        {
            string str = "";
            forr(i, 1, n + 1)
            {
                if (curr[i])
                    str += "1";
                else
                    str += "0";
            }
            out.pb(mp(str, -p.f - t));
            t = -p.f;
        }
        curr[p.s] = true;
        for (auto e : graph[p.s])
        {
            pq.push({-(t + e.s), e.f});
        }
    }
    if (inf)
        printf("inf\n");
    else
    {
        printf("%lld %d\n", t, out.size());
        for (auto p : out)
        {
            cout << p.f << " " << p.s << "\n";
        }
    }
}