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

vvi graph;
vb vis;

void dfs(int x)
{
    if (vis[x])
        return;
    vis[x] = true;
    for (auto e : graph[x])
        dfs(e);
}

int main()
{
    int n;
    scd(n);
    vii vec(n);
    vi pos;
    frange(i, n)
    {
        scd(vec[i].f);
        scd(vec[i].s);
        pos.pb(vec[i].f);
        pos.pb(vec[i].s);
    }

    sort(all(vec));
    sort(all(pos));

    multiset<pii> st;
    graph = vvi(n);

    int c = 0;

    frange(i, n)
    {
        auto it = st.lower_bound({vec[i].f, 0});
        vii er;
        for (auto i1 = st.begin(); i1 != it; i1++)
        {
            er.pb(*i1);
        }
        for (auto e : er)
            st.erase(e);

        it = st.begin();
        for (; it != st.end(); it++)
        {
            if ((*it).f < vec[i].s)
            {
                c++;
                graph[(*it).s].pb(i);
                graph[i].pb((*it).s);
            }
            else
                break;
        }

        if (c >= n)
        {
            printf("NO");
            return 0;
        }
        st.insert(mp(vec[i].s, i));
    }
    // printf("%d ", c);
    vis = vb(n);
    dfs(0);

    bool done = true;
    for (auto e : vis)
        done = done && e;

    if (done)
        printf("YES");
    else
        printf("NO");
}