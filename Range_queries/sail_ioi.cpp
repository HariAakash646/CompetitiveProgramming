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
    int n;
    scd(n);

    vii vec(n);

    frange(i, n)
    {
        scd(vec[i].f);
        scd(vec[i].s);
    }

    sort(all(vec));

    int h = 1e6;

    BIT<lli> bit(h + 10);

    int id = 0;

    frange(i, n)
    {
        pii p = vec[i];
        id %= p.f;
        id++;
        bit.add(id, 1);
        id += p.s - 1;
        if (id > p.f)
        {
            bit.add(p.f + 1, -1);
            bit.add(1, 1);
            p.s = (id - p.f);
            id = 1;
            id += p.s - 1;
        }
        bit.add(id + 1, -1);
    }
    lli tot = 0;
    forr(i, 1, h + 1)
    {
        lli v = bit.query(i);
        // printf("%lld\n", v);
        tot += v * (v - 1) / 2;
    }
    printf("%lld", tot);
}