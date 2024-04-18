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
    int n;
    scd(n);

    vi vec(n);
    vi pos(n+1);
    frange(i, n) {
        scd(vec[i]);
        pos[vec[i]] = i;
    }

    BIT<lli> bit(n);
    lli tot = 0;
    frange(i, n) {
        tot += bit.query(n) - bit.query(vec[i]);
        bit.add(vec[i], 1);
    }

    printf("%lld ", tot);

    vi v2 = vec;
    tot = 0;
    forr(i, 1, n+1) {
        if(pos[i] != i-1) {
            tot++;
            int v = v2[i-1];
            int p = pos[i];
            v2[p] = v;
            v2[i-1] = i;
            pos[v] = p;
            pos[i] = i-1;
        }
    }

    printf("%lld ", tot);

    vi lis(n+1, 1e9+10);
    lis[0] = 0;

    frange(i, n) {
        auto it = upper_bound(all(lis), vec[i]) - lis.begin();
        lis[it] = vec[i];
    }

    int v = 0;
    forr(i, 1, n+1) {
        if(lis[i] <= n) v = i;
    }

    printf("%d ", n - v);

    int curr = n;
    v = 0;
    for(int i=n-1; i>=0; i--) {
        if(vec[i] == curr) {
            v++;
            curr--;
        }
    }

    printf("%d", n-v);

}