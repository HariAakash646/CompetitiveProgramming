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

int main() {
    // usaco();
    int n;
    lli k;
    scd(n);
    sclld(k);

    vector<pair<lli, lli>> v1(n/2), v2((n+1)/2);
    frange(i, n/2) {sclld(v1[i].f); sclld(v1[i].s);}
    frange(i, (n+1)/2) {sclld(v2[i].f); sclld(v2[i].s);}

    vector<pair<lli, lli>> val1, val2;
    // val1.pb(mp(0, 0));
    // val2.pb(mp(1e18, 0));
    vll av;
    // av.pb(0LL);
    // av.pb(k);

    frange(i, 1<<(n/2)) {
        lli pre = 0;
        lli tot = 0;
        bool done = true;
        frange(j, n/2) {
            if(i & (1<<j)) {
                if(v1[j].f < pre) {
                    done = false;
                    break;
                }
                pre = v1[j].f;
                tot += v1[j].s;
            }
        }
        if(done) {val1.pb(mp(pre, k-tot)); av.pb(k-tot);}
    }

    frange(i, 1<<(((n+1)/2))) {
        lli pre = 0;
        lli tot = 0;
        lli fir = 1e18;
        bool done = true;
        frange(j, (n+1)/2) {
            if(i & (1<<j)) {
                if(v2[j].f < pre) {
                    done = false;
                    break;
                }
                if(fir == 1e18) fir = v2[j].f;
                pre = v2[j].f;
                tot += v2[j].s;
            }
        }
        if(done) {val2.pb(mp(fir, tot)); av.pb(tot);}
    }
    sort(all(av), greater<lli>());
    sort(all(val1), greater<>());
    sort(all(val2), greater<>());
    map<lli, int> pos;
    frange(i, av.size()) {
        pos[av[i]] = i+1;
    }

    BIT<lli> bit(av.size()+10);

    lli id = 0;
    int x = val2.size();
    // printf("%d\n", x);
    lli tot = 0;
    for(auto p : val1) {
        // printf("%lld %lld\n", p.f, p.s);
        for(; id<x; id++) {
            if(val2[id].f < p.f) break;
            // printf("%lld %lld %d\n", val2[id].f, val2[id].s, pos[val2[id].s]);
            bit.add(pos[val2[id].s], 1);
        }
        tot += bit.query(pos[p.s]);

    }
    printf("%lld", tot);
}