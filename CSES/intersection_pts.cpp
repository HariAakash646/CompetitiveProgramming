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
struct BIT {
    vector<T> vec;
    vector<T> bit;
    int size;

    BIT(int n) : size(n), vec(n+1), bit(n+1) {}

    int lsb(int x) {
        return x & (-x);
    }

    void set(int id, T x) {
        add(id, x - vec[id]);
    }

    void add(int id, T x) {
        if(id == 0) return;
        vec[id] += x;
        while(id <= size) {
            bit[id] += x;
            id += lsb(id);
        }
    }

    T query(int id) {
        T tot = 0;
        if(id == 0) return tot;
        while(id >= 1) {
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

    vector<vii> vec(2e6+2);

    frange(i, n) {
        int x1, y1, x2, y2;
        scd(x1);
        scd(y1);
        scd(x2);
        scd(y2);

        x1 += 1e6+1;
        x2 += 1e6+1;
        y1 += 1e6+1;
        y2 += 1e6+1;

        if(x1 == x2) {
            vec[x1].pb(mp(min(y1, y2), max(y1, y2)));
        }
        else {
            vec[min(x1, x2)].pb(mp(y1, 1e9));
            vec[max(x1, x2)].pb(mp(y2, -1e9));
        }
    }
    lli tot = 0;
    BIT<lli> bit(2e6+1);
    forr(i, 1, 2e6+2) {
        for(auto p : vec[i]) {
            if(abs(p.s) == 1e9) {
                bit.add(p.f, p.s/1e9);
            }
            else {
                tot += bit.query(p.s) - bit.query(p.f-1);
            }
        }
    }
    printf("%lld", tot);

}