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

lli mod = 998244353;

int main() {
    usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, k;
        scd(n);
        scd(k);

        vi v1(n), v2(k);

        frange(i, n) scd(v1[i]);
        frange(i, k) scd(v2[i]);

        BIT<int> bit1(k+1);
        lli tot = 0;
        for(auto e : v2) {
            tot += bit1.query(k) - bit1.query(e);
            tot %= mod;
            bit1.add(e+1, 1);
        }
        printf("%lld ", tot*n);
        tot *= n;
        tot %= mod;

        BIT<lli> bit2(2*n+10);

        for(int j=n-1; j>=0; j--) {
            lli v = v1[j];
            lli curr = bit2.query(v-1);
            lli pre = tot;
            frange(i, min(k, 20)) {
                // if(v -1 > 2*n) break;
                lli cnt = bit2.query(min(v-1, (lli)2*n));
                curr = cnt - curr;
                printf("%lld %lld %d\n", v, curr, k-i);
                tot += ((lli(k-i) * (k-i+1)/2) % mod * curr) % mod;
                // printf("%lld ", (((k-i) * (k-i+1)/2) % mod * curr));
                tot %= mod;
                v *= 2;
            }
            printf("%lld ", tot-pre);
            bit2.add(v1[j], 1);
        }

        bit2 = BIT<lli>(2*n+10);

        // frange(j, n) {
        //     lli v = v1[j];
        //     lli curr = bit2.query(v-1);
        //     lli val = 0;
        //     frange(i, min(k, 20)) {
        //         // if(v -1 > 2*n) break;
        //         lli cnt = bit2.query(min(v-1, (lli)2*n));
        //         curr = cnt - curr;
        //         // printf("%lld %lld\n", v, curr);
        //         val += (((k-i) * (k-i+1)/2) % mod * curr) % mod;
        //         // printf("%lld ", (((k-i) * (k-i+1)/2) % mod * curr));
        //         val %= mod;
        //         v *= 2;
        //     }
        //     // printf("%lld ", tot-pre);
        //     tot += (k*k - val) % mod;
        //     tot %= mod;
        //     bit2.add(v1[j], 1);
        // }
        printf("%lld\n", tot);
    }
}