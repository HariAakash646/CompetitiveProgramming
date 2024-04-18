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

vvi tree;
vi st, en;
int timer = 0;

void euler(int x)
{
    timer++;
    st[x] = timer;

    for (auto e : tree[x])
    {
        euler(e);
    }
    en[x] = timer;
}

int main()
{
    int n, q;
    scd(n);
    scd(q);
    tree = vvi(n + 1);
    st = en = vi(n + 1);
    int a;
    scd(a);

    forr(i, 2, n + 1)
    {
        scd(a);
        a++;
        tree[a].pb(i);
    }
    euler(1);
    BIT<lli> bit(n);
    frange(i, n)
    {
        lli a;
        sclld(a);
        bit.add(st[i + 1], a);
        if (st[i + 1] + 1 <= n)
            bit.add(st[i + 1] + 1, -a);
    }
    // forr(i, 1, n + 1) printf("%d %d\n", st[i], en[i]);
    printf("\n");
    frange(i, q)
    {
        int t;
        scd(t);
        if (t)
        {
            int x;
            scd(x);
            x++;
            printf("%lld\n", bit.query(st[x]));
        }
        else
        {
            int x;
            lli v;
            scd(x);
            sclld(v);
            x++;
            bit.add(st[x], v);
            if (en[x] + 1 <= n)
                bit.add(en[x] + 1, -v);
        }
    }
}