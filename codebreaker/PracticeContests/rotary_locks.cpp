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

lli v;

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

    void set(int id, T v1)
    {
        add(id, v1 - vec[id]);
    }

    void add(int id, T v1)
    {
        if (id == 0)
            return;
        vec[id] += v1;
        vec[id] %= v;
        while (id <= size)
        {
            bit[id] += v1;
            bit[id] %= v;
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
            tot %= v;
            id -= lsb(id);
        }
        return tot;
    }
};

int main() {
    // usaco();
    int n, q, k;
    scd(n);
    scd(q);
    scd(k);
    v = (1LL << k);

    BIT<lli> bit(n);

    frange(_, q) {
        int t;
        scd(t);
        if(t) {
            int d;
            scd(d);
            printf("%lld\n", bit.query(d));
        }
        else {
            int d;
            scd(d);
            lli si;
            sclld(si);
            bit.add(d, si);
        }
    }
    // forr(i, 1, n+1) printf("%lld ", bit.query(i));
}