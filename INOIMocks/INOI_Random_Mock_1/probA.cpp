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

const lli mod = 998244353;

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
        vec[id] += v + mod;
        vec[id] %= mod;
        while (id <= size)
        {
            bit[id] += v + mod;
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
            tot += bit[id] + mod;
            tot %= mod;
            id -= lsb(id);
        }
        return tot;
    }
};

vll fact;

lli inv(lli a) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

int main() {
    // usaco();
    fact = vll(2e5+1);

    fact[0] = 1;
    forr(i, 1, 2e5+1) fact[i] = (i*fact[i-1]) % mod;
    int n, m;
    scd(n);
    scd(m);

    vi v1(n), v2(m);
    vi cnt1(2e5+1), cnt2(2e5+1);

    frange(i, n) {
        scd(v1[i]);
        cnt1[v1[i]]++;
    }
    frange(i, m) {
        scd(v2[i]);
        cnt2[v2[i]]++;
    }

    BIT<lli> bit(2e5+1);

    lli tot = fact[n];
    forr(i, 1, 2e5+1) {
        tot *= inv(fact[cnt1[i]]);
        bit.add(i, cnt1[i]);
        tot %= mod;
    }

    int sz = n;
    lli out = 0;
    frange(i, m) {
        tot *= inv(sz);
        tot %= mod;
        sz--;
        int x = v2[i];
        // forr(j, 1, x) {
        //     if(cnt1[j]) {
        //         out += tot * cnt1[j];
        //         out %= mod;
        //     }
        // }
        out += tot * bit.query(x-1);
        out %= mod;
        if(cnt1[x]) {
            tot *= cnt1[x];
            tot %= mod;
            cnt1[x]--;
            bit.add(x, -1);
        }
        else break;
        // printf("%lld\n", out);
        if(sz == 0) {
            // printf("%d %d\n", n, m);
            if(n < m) {
                out++;
                out %= mod;
            }
            break;
        }
    }
    printf("%lld", out);

}