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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

vll vec;
vll segtree;

void recalculate(int node)
{
    segtree[node] = max(segtree[2 * node + 1], segtree[2 * node + 2]);
}

void build(int node, int l, int r)
{
    if (r == l)
    {
        segtree[node] = vec[l];
    }
    else
    {
        int mid = (r + l) / 2;
        build(2 * node + 1, l, mid);
        build(2 * node + 2, mid + 1, r);
        recalculate(node);
    }
}

lli query(int l, int r, int lx, int rx, int node)
{
    if (lx > r || rx < l)
        return 0;
    if (lx >= l && rx <= r)
        return segtree[node];
    lli mid = (lx + rx) / 2;
    lli s1 = query(l, r, lx, mid, 2 * node + 1);
    lli s2 = query(l, r, mid + 1, rx, 2 * node + 2);
    return max(s1, s2);
}

int main()
{
    int n, e, q;
    scd(n);
    scd(e);
    scd(q);
    vector<vector<pair<int, lli>>> graph(n);

    frange(i, e)
    {
        int a, b;
        lli w;
        scd(a);
        scd(b);
        sclld(w);
        graph[a].pb({b, w});
        graph[b].pb({a, w});
    }
    vi line(n);
    int sze = 1;
    while (sze < n)
        sze *= 2;
    segtree = vll(2 * sze);
    vec = vll(sze);
    int curr;
    int prev = -1;
    int id = 0;
    frange(i, n)
    {
        if (graph[i].size() == 1)
        {
            // printf("%d ", i);
            line[i] = id;
            curr = i;
            id++;
            break;
        }
    }
    while (true)
    {

        for (auto e : graph[curr])
        {
            if (e.f != prev)
            {
                // printf("%d ", e.f);
                line[e.f] = id;
                vec[id] = e.s;
                id++;
                prev = curr;
                curr = e.f;
                break;
            }
        }
        if (graph[curr].size() == 1)
            break;
    }

    build(0, 0, n - 1);
    // for (auto e : segtree)
    //     printf("%d ", e);
    // printf("\n");
    frange(i, q)
    {
        int a, b;
        scd(a);
        scd(b);
        a = line[a];
        b = line[b];
        if (a > b)
            swap(a, b);
        a++;

        lli out = query(a, b, 0, n - 1, 0);
        printf("%lld\n", out);
    }
}