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

void usaco() {
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

struct BIT {
    int n;
    vi vec, tree;

    void init(int l) {
        n = l;
        vec = vi(n+1);
        tree = vi(n+1);
    }

    int lsb(int x) {
        return x & (-x);
    }

    void add(int id, int v) {
        vec[id]+=v;
        while(id <= n) {
            tree[id] += v;
            id += lsb(id);
        }
    }

    int query(int id) {
        if(id == 0) return 0;
        int tot = 0;
        while(id >= 1) {
            tot += tree[id];
            id -= lsb(id);
        }
        return tot;
    }
};

int main() {
    // usaco();
    int n;
    scd(n);
    vll vec(n+1);
    set<lli> st;

    forr(i, 1, n+1) {
        sclld(vec[i]);
        st.insert(vec[i]);
    }

    map<lli, int> mv;
    int id = 1;

    for(auto e : st) {
        mv[e] = id++;
    }

    BIT bit1, bit2;
    bit1.init(n);
    bit2.init(n);

    forr(i, 1, n+1) {
        bit2.add(mv[vec[i]], 1);
    }

    lli out = 0;

    forr(i, 1, n+1) {
        bit2.add(mv[vec[i]], -1);
        lli v1 = bit1.query(mv[vec[i]]-1);
        lli v2 = bit2.query(mv[vec[i]]-1);
        bit1.add(mv[vec[i]], 1);
        out += v1 * v2;
    }
    printf("%lld", out);
}