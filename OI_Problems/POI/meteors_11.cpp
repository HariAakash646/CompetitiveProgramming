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

template <class T>
struct BIT
{
    int size;
    vector<T> bit;
    vector<T> vec;

    BIT(int n) : size(n), bit(n + 1), vec(n + 1) {}

    int lsb(int x)
    {
        return x & (-x);
    }

    void set(int id, T v)
    {
        add(id, v - vec[id]);
    }

    void add(int id, T v)
    {
        if (id == 0)
            return;
        vec[id] += v;
        while (id <= size)
        {
            bit[id] += v;
            id += lsb(id);
        }
    }

    T query(int id)
    {
        T tot = 0;
        if (id == 0)
            return tot;
        while (id >= 1)
        {
            tot += bit[id];
            id -= lsb(id);
        }
        return tot;
    }
};

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vvi pos(n);
    frange(i, m)
    {
        int a;
        scd(a);
        a--;
        pos[a].pb(i);
    }
    vi vec(n);
    frange(i, n) scd(vec[i]);
    int q;
    scd(q);

    vector<pair<pii, lli>> quer(q);
    frange(i, q)
    {
        scd(quer[i].f.f);
        scd(quer[i].f.s);
        // quer[i].f.f--;
        // quer[i].f.s--;
        sclld(quer[i].s);
    }

    vii range(n, mp(1, q));

    for (int k = 1; k <= q; k *= 2)
    {
        BIT<lli> tree(m + 1);
        vvi check(q + 1);

        frange(i, n)
        {
            if (range[i].f != range[i].s)
            {
                int mid = (range[i].f + range[i].s) / 2;
                check[mid].pb(i);
            }
        }

        frange(i, q)
        {
            if (quer[i].f.f <= quer[i].f.s)
            {
                tree.add(quer[i].f.f, quer[i].s);
                tree.add(quer[i].f.s + 1, -quer[i].s);
            }
            else
            {
                tree.add(quer[i].f.f, quer[i].s);
                tree.add(1, quer[i].s);
                tree.add(quer[i].f.s + 1, -quer[i].s);
            }
            for (auto e : check[i + 1])
            {
                lli tot = 0;
                for (auto x : pos[e])
                    tot += tree.query(x + 1);
                if (tot >= vec[e])
                {
                    range[e].s = i + 1;
                }
                else
                {
                    range[e].f = i + 1 + 1;
                }
            }
        }
    }
    BIT<lli> tree(m + 1);

    frange(i, q)
    {
        if (quer[i].f.f <= quer[i].f.s)
        {
            tree.add(quer[i].f.f, quer[i].s);
            tree.add(quer[i].f.s + 1, -quer[i].s);
        }
        else
        {
            tree.add(quer[i].f.f, quer[i].s);
            tree.add(1, quer[i].s);
            tree.add(quer[i].f.s + 1, -quer[i].s);
        }
    }

    frange(i, n)
    {
        int x = range[i].f;
        int e = i;
        lli tot = 0;
        for (auto k : pos[e])
            tot += tree.query(k + 1);
        // printf("%lld\n", tot);
        if (tot >= vec[e])
        {
            printf("%d\n", x);
        }
        else
        {
            printf("NIE\n");
        }
    }
}