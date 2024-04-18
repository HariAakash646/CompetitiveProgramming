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
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    scd(n);

    BIT<int> bit(n);
    vii vec(n);

    frange(i, n) {scd(vec[i].f); vec[i].s = i+1;}
    // vi v2 = vec;
    sort(all(vec));
    int id = 1;

    // map<int, seti> mv;
    // for(auto e : v2) mv[e].insert(id++);

    // frange(i, n) {
    //     int x = vec[i];
    //     vec[i] = *mv[x].begin();
    //     mv[x].erase(mv[x].begin());
    // }
    int ma = 0;
    forr(i, 1, n+1) {
        bit.add(vec[i-1].s, 1);
        ma = max(ma, i - bit.query(i));
    }   
    if(ma == 0) ma = 1;
    printf("%d", ma);
}