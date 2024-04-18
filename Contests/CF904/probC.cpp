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
    int t;
    scd(t);
    frange(_, t) {
        int n, m;
        scd(n);
        scd(m);

        vii vec(n);
        seti val;
        frange(i, n) {
            scd(vec[i].f);
            scd(vec[i].s);
            val.insert(vec[i].f);
            val.insert(vec[i].s);
        }

        mpii pos;
        int c = 1;
        for(auto e : val) {
            pos[e] = c++;
        }
        
        lli ma = 0;
        BIT<lli> bit1(2*n+10), bit2(2*n+10);

        for(auto p : vec) {
            if(p.f != 1) {
                bit1.add(pos[p.f], 1);
                bit1.add(pos[p.s]+1, -1);
            }
        }

        for(auto p : vec) {
            if(p.s != m) {
                bit2.add(pos[p.f], 1);
                bit2.add(pos[p.s]+1, -1);
            }
        }

        forr(i, 1, 2*n+10) {
            ma = max(ma, bit1.query(i));
            ma = max(ma, bit2.query(i));
        }
        printf("%lld\n", ma);
    }
}