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
    usaco();
    int n, k;
    scd(n);
    scd(k);
    vi vec(n+1);
    vvi val(2e5+1);
    forr(i, 1, n+1) {
        scd(vec[i]);
        val[vec[i]].pb(i);
    }

    BIT<int> bit1(n), bit2(n);

    for(int i=1; i<=n; i+=2)
        bit1.set(i, 1);
    for(int i=0; i<=n; i+=2)
        bit2.set(i, 1);

    lli tot = 0;

    forr(i, 1, 2e5+1) {
        for(auto e : val[i]) {
            bit1.set(e, 0);
            bit2.set(e, 0);
        }

        for(auto e : val[i]) {
            
            if(e + k/2 >= n) continue;
            
            int lo = e + max(2, k-2*e);
            int hi = min(n, e + k - 1) - max(0, (k+1)/2 - n - k/2 - e );
            printf("%d %d %d\n", e, lo, hi);
            if(e % 2)
                tot += bit1.query(hi) - bit1.query(lo- 1);
            else tot += bit2.query(hi) - bit2.query(lo - 1);
        }
        for(auto e : val[i]) {
            if(e % 2) bit1.set(e, 1);
            else bit2.set(e, 1);
        }
    }
    
    printf("%lld", tot);



}