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

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vvi vec(n, vi(m));
    seti st;
    frange(i, n)
    {
        frange(j, m)
        {
            scd(vec[i][j]);
            st.insert(vec[i][j]);
        }
    }
    mpii vid;
    vi idv(st.size() + 1);
    int i = 1;
    for (auto e : st)
    {
        vid[e] = i;
        idv[i] = e;
        i++;
    }
    BIT<lli> bit(st.size());
    lli tot = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        frange(j, m)
        {
            tot += (j + 1) * ((n - 1) - i) + bit.query(vid[vec[i][j]]);
        }
        frange(j, m)
        {
            bit.add(vid[vec[i][j]], 1);
        }
    }
    printf("%lld", tot);
}