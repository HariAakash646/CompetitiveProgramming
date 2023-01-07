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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vvi graph(n + 1);
    int a, b;
    frange(i, m)
    {
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    queue<int> q;
    vector<pii> data(n + 1, {0, 0});
    q.push(1);
    data[1] = {-1, 1};
    int node = 0;
    while (q.size() != 0)
    {
        int e = q.front();
        q.pop();
        if (e == n)
        {
            node = e;
            break;
        }
        for (int k : graph[e])
        {
            if (data[k].f == 0)
            {
                data[k].f = e;
                data[k].s = data[e].s + 1;
                q.push(k);
            }
        }
    }
    if (node == 0)
    {
        printf("IMPOSSIBLE");
    }
    else
    {
        printf("%d\n", data[node].s);
        int o = node;
        vi out_vec;
        while (o != -1)
        {
            out_vec.pb(o);
            o = data[o].f;
        }
        reverse(out_vec.begin(), out_vec.end());
        for (int l : out_vec)
        {
            printf("%d ", l);
        }
    }
}