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

lli mod = 1e9 + 7;

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
        add(id, (v - vec[id] + mod) % mod);
    }

    void add(int id, T v)
    {
        if (id == 0)
            return;
        vec[id] += v;
        vec[id] %= mod;
        while (id <= size)
        {
            bit[id] += v;
            bit[id] %= mod;
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
            tot %= mod;
            id -= lsb(id);
        }
        return tot;
    }
};

int main()
{
    int n;
    scd(n);
    vi vec(n);
    mpii m;

    frange(i, n)
    {
        scd(vec[i]);
        m[vec[i]]++;
    }
    int c = 1;
    for (auto &p : m)
        p.s = c++;
    for (auto &e : vec)
        e = m[e];
    BIT<lli> bit(c);

    for (auto e : vec)
    {
        bit.add(e, bit.query(e - 1) + 1);
    }
    printf("%lld", bit.query(c));
}