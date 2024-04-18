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
 
vvi pos;
vll val;
vector<pair<pii, lli>> met;
vi out;
BIT<lli> bit(0);
 
void upd(int l, int r, lli v) {
    if(l <= r) {
        bit.add(l, v);
        bit.add(r+1, -v);
    }
    else {
        bit.add(l, v);
        bit.add(1, v);
        bit.add(r+1, -v);
    }
}
 
void pbs(int l, int r, vi curr) {
    if(l == r) {
        upd(met[l].f.f, met[l].f.s, met[l].s);
        for(auto x : curr) {
            lli tot = 0;
            for(auto e : pos[x]) {
                tot += bit.query(e);
            }
            if(tot >= val[x]) out[x] = l;
            else out[x] = -1;
        }
        upd(met[l].f.f, met[l].f.s, -met[l].s);
        return;
    }
    int mid = (l+r)/2;
    vi lv, rv;
    forr(i, l, mid+1) {
        upd(met[i].f.f, met[i].f.s, met[i].s);
    }
    for(auto x : curr) {
        lli tot = 0;
        for(auto e : pos[x]) {
            tot += bit.query(e);
            if(tot >= val[x]) break;
        }
        if(tot >= val[x]) {
            lv.pb(x);
        }
        else {
            val[x] -= tot;
            rv.pb(x);
        }
    }
    forr(i, l, mid+1) {
        upd(met[i].f.f, met[i].f.s, -met[i].s);
    }
    pbs(l, mid, lv);
    pbs(mid+1, r, rv);
}
 
 
int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);
    pos = vvi(n+1);
    val = vll(n+1);
 
    forr(i, 1, m+1) {
        int id;
        scd(id);
        pos[id].pb(i);
    }
 
    forr(i, 1, n+1) sclld(val[i]);
 
    int k;
    scd(k);
 
    met = vector<pair<pii, lli>>(k);
 
    frange(i, k) {
        scd(met[i].f.f);
        scd(met[i].f.s);
        sclld(met[i].s);
    }
 
    bit = BIT<lli>(m+1);
    vi curr;
    forr(i, 1, n+1) curr.pb(i);
    out = vi(n+1);
 
    pbs(0, k-1, curr);
 
    forr(i, 1, n+1) {
        out[i]++;
        if(out[i]) printf("%d\n", out[i]);
        else printf("NIE\n");
    }
 
 
 
}