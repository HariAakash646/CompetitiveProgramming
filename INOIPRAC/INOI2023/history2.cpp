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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int bsze;

struct Query
{
    int l, r, idx;
    bool operator<(Query other) const
    {
        return mp(l / bsze, r) <
               mp(other.l / bsze, other.r);
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
    fastio();
    int n, m;
    cin >> n >> m;
    vi vec(n + 1);
    forr(i, 1, n + 1) cin >> vec[i];
    vector<Query> quer(m);
    frange(i, m)
    {
        int t, l, r;
        cin >> t;
        cin >> l >> r;
        quer[i].l = l;
        quer[i].r = r;
        quer[i].idx = i;
    }
    bsze = sqrt(n);
    sort(all(quer));
    int l = 1;
    int r = 1;
    lli tot = 0;
    BIT<int> bit(n + 1);
    bit.add(vec[1], 1);
    vll out(m);
    for (auto p : quer)
    {
        // cout << bit.query(n) << " r\n";
        while (r > p.r)
        {
            tot -= bit.query(n) - bit.query(vec[r]);
            bit.add(vec[r], -1);
            r--;
        }
        while (r < p.r)
        {
            r++;
            tot += bit.query(n) - bit.query(vec[r]);
            bit.add(vec[r], 1);
        }
        while (l < p.l)
        {
            tot -= bit.query(vec[l] - 1);
            bit.add(vec[l], -1);
            l++;
        }
        while (l > p.l)
        {
            l--;
            tot += bit.query(vec[l] - 1);
            bit.add(vec[l], 1);
        }

        out[p.idx] = tot;
    }
    for (auto e : out)
        cout << e << "\n";
}