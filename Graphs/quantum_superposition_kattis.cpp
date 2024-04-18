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
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

int main()
{
    int n1, n2, m1, m2;
    scd(n1);
    scd(n2);
    scd(m1);
    scd(m2);
    vvi graph1(n1 + 1), graph2(n2 + 1);
    vvi ing1(n1 + 1), ing2(n2 + 1);
    vi indeg1(n1 + 1), indeg2(n2 + 1);
    frange(i, m1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph1[a].pb(b);
        ing1[b].pb(a);
        indeg1[b]++;
    }
    vi topo1, id1(n1 + 1);
    queue<int> q;
    forr(i, 1, n1 + 1)
    {
        if (indeg1[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        auto e = q.front();
        q.pop();
        topo1.pb(e);
        id1[e] = topo1.size();
        for (auto x : graph1[e])
        {
            indeg1[x]--;
            if (indeg1[x] == 0)
            {
                q.push(x);
            }
        }
    }

    frange(i, m2)
    {
        int a, b;
        scd(a);
        scd(b);
        graph2[a].pb(b);
        ing2[b].pb(a);
        indeg2[b]++;
    }
    vi topo2, id2(n2 + 1);
    forr(i, 1, n2 + 1)
    {
        if (indeg2[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        auto e = q.front();
        q.pop();
        topo2.pb(e);
        id2[e] = topo2.size();
        for (auto x : graph2[e])
        {
            indeg2[x]--;
            if (indeg2[x] == 0)
            {
                q.push(x);
            }
        }
    }
    vector<vb> dp1(n1 + 1, vb(2001)), dp2(n2 + 1, vb(2001));
    dp1[id1[1]][0] = true;
    dp2[id2[1]][0] = true;

    forr(i, id1[1] + 1, n1 + 1)
    {
        int x = topo1[i - 1];
        forr(j, 1, 2001)
        {
            for (auto e : ing1[x])
            {
                dp1[i][j] = dp1[i][j] || dp1[id1[e]][j - 1];
            }
        }
    }

    forr(i, id2[1] + 1, n2 + 1)
    {
        int x = topo2[i - 1];
        forr(j, 1, 2001)
        {
            for (auto e : ing2[x])
            {
                dp2[i][j] = dp2[i][j] || dp2[id2[e]][j - 1];
            }
        }
    }

    int Q;
    scd(Q);
    int i1 = id1[n1];
    int i2 = id2[n2];
    // for (auto e : topo1)
    //     printf("%d ", e);
    // printf("\n");
    // for (auto e : topo2)
    //     printf("%d ", e);
    // printf("\n");
    frange(j, Q)
    {
        int x;
        scd(x);
        bool done = false;
        frange(i, x + 1)
        {
            if (dp1[i1][i] && dp2[i2][x - i])
                done = true;
        }
        if (done)
            printf("Yes\n");
        else
            printf("No\n");
    }
}