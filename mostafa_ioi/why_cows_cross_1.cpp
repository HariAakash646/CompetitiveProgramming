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

int main() {
    // usaco();
    freopen("mincross.in", "r", stdin);
    freopen("mincross.out", "w", stdout);
    int n;
    scd(n);

    vi vec(n+1), vec2(n+1);
    vi val1(n+1), val2(n+1);
    forr(i, 1, n+1) {
        int a;
        scd(a);
        vec[a] = i;
        val1[i] = a;
    }

    forr(i, 1, n+1) {
        int a;
        scd(a);
        vec2[i] = vec[a];
        val2[i] = a;
    }

    BIT<lli> bit(n);

    lli tot = 0;

    forr(i, 1, n+1) {
        tot += bit.query(n) - bit.query(vec2[i]);
        bit.add(vec2[i], 1);
    }

    lli mi = tot;

    forr(i, 1, n+1) {
        tot += (n-vec2[i]) - (vec2[i]-1);
        mi = min(mi, tot);
    }

    forr(i, 1, n+1) {
        vec[val2[i]] = i;
    }
    forr(i, 1, n+1) {
        vec2[i] = vec[val1[i]];
    }
    tot = 0;
    bit = BIT<lli>(n);

    forr(i, 1, n+1) {
        tot += bit.query(n) - bit.query(vec2[i]);
        bit.add(vec2[i], 1);
    }

    mi = min(mi, tot);

    forr(i, 1, n+1) {
        tot += (n-vec2[i]) - (vec2[i]-1);
        mi = min(mi, tot);
    }
    printf("%lld", mi);

}