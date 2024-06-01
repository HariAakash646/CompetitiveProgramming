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

    int query_pos(T v) {
        T tot = 0;
        int id = 0;
        for(int i=19; i>=0; i--) {
            if(id+(1<<i) <= size) {
                T tott = tot + bit[id+(1<<i)];
                if(tott < v) {
                    id += (1<<i);
                    tot = tott;
                }
            }
        }
        return id+1;
    }
};

int msb(int x) {

    return 31 - __builtin_clz(x);
}

int main() {
    // usaco();
    // cout << __builtin_clz(0) << "\n";
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        vii vec(n+1);
        vector<BIT<lli>> bit1(30, BIT<lli>(n)), bit2(30, BIT<lli>(n));
        forr(i, 1, n+1) {
            int l, r;
            scd(l);
            scd(r);
            int msr = msb(r);
            int msl = msb(l);
            while(msr == msl) {
                bit1[msl].add(i, 1);
                l = l ^ (1<<msl);
                r = r ^ (1<<msr);
                if(l == 0) {
                    if(r==0) break;
                    msr = msb(r);
                    break;
                }
                msr = msb(r);
                msl = msb(l);
            }
            if(r != 0) {
                bit1[msr].add(i, 1);
                bit2[msr].add(i, 1);
            }
            vec[i] = mp(l, r);
            
        }
        int q;
        scd(q);
        frange(_, q) {
            int l, r;
            scd(l);
            scd(r);
            int out = 0;
            vii up1, up2;

            for(int i=29; i>=0; i--) {
                int c = bit1[i].query(r) - bit1[i].query(l-1);
                if(c) {
                    out = out | (1<<i);
                    if(c == 1) {
                        if(!(bit2[i].query(r) - bit2[i].query(l-1))) continue;
                        int id = bit1[i].query_pos(bit1[i].query(l-1)+1);
                        int lv = 0;
                        int rv = (vec[id].s & ((1<<i)-1));
                        if(rv==0) continue;
                        int msr = msb(rv);
                        int msl = msb(lv);

                        while(msr == msl) {
                            bit1[msl].add(id, 1);
                            up1.pb(mp(msr, id));
                            lv = lv ^ (1<<msl);
                            rv = rv ^ (1<<msr);
                            if(lv == 0) {
                                if(rv==0) break;
                                msr = msb(rv);
                                break;
                            }
                            msr = msb(rv);
                            msl = msb(lv);
                        }
                        if(rv != 0) {
                            bit1[msr].add(id, 1);
                            up1.pb(mp(msr, id));
                            up2.pb(mp(msr, id));
                            bit2[msr].add(id, 1);
                        }
                    }
                    else {
                        if((bit2[i].query(r) - bit2[i].query(l-1))) {
                            frange(j, i) out = out | (1<<j);
                            break;
                        }
                    }
                }
            }
            printf("%d ", out);
            for(auto p : up1) {
                bit1[p.f].add(p.s, -1);
            } 
            for(auto p : up2) {
                bit2[p.f].add(p.s, -1);
            }
        }
        printf("\n");
    }
}