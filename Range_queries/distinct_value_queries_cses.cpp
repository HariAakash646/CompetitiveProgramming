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

struct Query
{
    int l, r, id;

    bool operator>(Query other) const
    {
        return mp(l, r) > mp(other.l, other.r);
    }
};

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
    int n, q;
    scd(n);
    scd(q);

    BIT<int> bit(n);
    vi vec(n + 1);

    frange(i, n) scd(vec[i + 1]);

    vector<Query> quer(q);
    frange(i, q)
    {
        quer[i].id = i;
        scd(quer[i].l);
        scd(quer[i].r);
    }

    sort(all(quer), greater<>());
    int prev = n + 1;
    mpii last_idx;
    vi out(q);
    for (auto p : quer)
    {
        for (int i = prev - 1; i >= p.l; i--)
        {
            bit.set(last_idx[vec[i]], 0);
            last_idx[vec[i]] = i;
            bit.set(i, 1);
        }
        prev = p.l;
        out[p.id] = bit.query(p.r) - bit.query(p.l - 1);
    }
    for (auto e : out)
    {
        printf("%d\n", e);
    }
}
