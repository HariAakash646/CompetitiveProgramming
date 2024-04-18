#include <bits/stdc++.h>
 
using namespace std;
 
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

struct BIT {
    vi vec, bit;
    int n;

    void init(int l) {
        n = l;
        vec = bit = vi(n+1);
    }

    int lsb(int x) {
        return x & (-x);
    }

    void set(int id, int v) {
        vec[id] = v;
        for(int i=id; i<=n; i+=lsb(i)) {
            bit[i] = max(bit[i], v);
        }
    }

    int query(int id) {
        int out = 0;
        for(int i=id; i>=1; i-=lsb(i)) {
            out = max(out, bit[i]);
        }
        return out;
    }
};

int main() {
    // usaco();
    int n, x;
    scd(n);
    scd(x);

    vi vec(n);
    seti st;
    frange(i, n) {
        scd(vec[i]);
        st.insert(vec[i]);
        st.insert(vec[i]+x);
    }

    map<int, int> mv;
    int id = 1;
    for(auto e : st) {
        mv[e] = id++;
    }

    BIT bit1, bit2;
    bit1.init(2*n+1);
    bit2.init(2*n+1);

    frange(i, n) {
        int v2 = max(bit2.query(mv[vec[i]+x]-1), bit1.query(mv[vec[i]+x]-1))+1;
        int v = bit1.query(mv[vec[i]]-1) + 1;
        bit1.set(mv[vec[i]], v);
        
        bit2.set(mv[vec[i]+x], v2);
        // printf("%d ", v2);
    }

    printf("%d", max(bit1.query(2*n), bit2.query(2*n)));
}