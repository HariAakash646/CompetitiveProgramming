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

const lli mod = 1e9 + 7;


int main() {
    // usaco();
    int n;
    scd(n);
    vi vec(n);
    frange(i, n) scd(vec[i]);

    vi tmp = vec;
    sort(all(tmp));
    map<int, int> mv;
    forr(i, 1, n+1) mv[tmp[i-1]] = i;

    vi cnt(n);
    BIT<int> bit(n+1);

    for(int i=n-1; i>=0; i--) {
        cnt[i] = bit.query(mv[vec[i]]);
        bit.add(mv[vec[i]], 1);
    }

    vll fact(n+1);
    fact[0] = 1;
    forr(i, 1, n+1) {
        fact[i] = (fact[i-1] * i) % mod;
    }

    vll dp(n+1);
    forr(i, 1, n+1) {
        dp[i] = (cnt[i-1] * fact[n-i] + dp[i-1]) % mod;
    }

    printf("%lld", (dp[n]+1)%mod);
}