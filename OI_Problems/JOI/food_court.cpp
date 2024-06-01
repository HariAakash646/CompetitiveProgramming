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


void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

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

vi out;
BIT<lli> bit2(0);
vector<pair<pii, pair<int, lli>>> upd;

void rec(int l, int r, vector<pair<pair<int, lli>, pii>> quer) {
    if(l == r) {
        for(auto p : quer) {
            if(p.s.s >= l) {
                out[p.s.f] = upd[l].s.f;
            }
            else {
                out[p.s.f] = 0;
            }
        }
        return;
    }
    int mid = (l+r)/2;
    forr(i, l, mid+1) {
        auto p = upd[i];
        bit2.add(p.f.f, p.s.s);
        bit2.add(p.f.s+1, -p.s.s);
    }
    vector<pair<pair<int, lli>, pii>> lv, rv;
    for(auto p : quer) {
        lli v = bit2.query(p.f.f);
        if(v >= p.f.s) {
            lv.pb(p);
        }
        else {
            rv.pb(mp(mp(p.f.f, p.f.s-v), p.s));
        }
    }
    forr(i, l, mid+1) {
        auto p = upd[i];
        bit2.add(p.f.f, -p.s.s);
        bit2.add(p.f.s+1, +p.s.s);
    }
    rec(l, mid, lv);
    rec(mid+1, r, rv);
}

int main() {
    // usaco();
    int n, m, q;
    scd(n);
    scd(m);
    scd(q);

    BIT<lli> bit(n+1);
    BIT<lli> bitv(n+1);

    vector<pair<pair<int, lli>, pii>> quer;
    

    frange(i, q) {
        int t;
        scd(t);

        if(t == 1) {
            int l, r, c;
            lli k;
            scd(l);
            scd(r);
            scd(c);
            sclld(k);
            upd.pb(mp(mp(l, r), mp(c, k)));
        }
        else if(t == 2) {
            int l, r;
            lli k;
            scd(l);
            scd(r);
            sclld(k);
            bit.add(l, k);
            bit.add(r+1, -k);
        }
        else {
            int a;
            lli b;
            scd(a);
            sclld(b);
            b += bit.query(a);
            quer.pb(mp(mp(a, b), mp(quer.size(), upd.size()-1)));
        }
    }
    upd.pb(mp(mp(0, 0), mp(0, 0LL)));
    bit2 = BIT<lli>(n+1);
    out = vi(quer.size());
    rec(0, upd.size()-1, quer);

    for(auto e : out) printf("%d\n", e);
}