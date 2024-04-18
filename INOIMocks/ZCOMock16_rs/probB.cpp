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

struct Data {
    lli v11 = 0, v00 = 0, v10 = 0, v01 = 0;
};

struct Segtree {
    int n, size = 1;
    vll vec;
    vector<Data> tree;

    void init(int l) {
        n = l;
        while(size < n) size *= 2;
        vec = vll(size);
        tree = vector<Data>(2*size);
    }

    void set(int id, lli v) {
        vec[id] = v;
    }

    Data operation(Data x, Data y) {
        Data out;
        out.v11 = max({x.v11 + y.v01, x.v10 + y.v11, x.v10 + y.v01});
        out.v10 = max({x.v11 + y.v00, x.v10 + y.v10, x.v10 + y.v00});
        out.v01 = max({x.v01 + y.v01, x.v00 + y.v11, x.v00 + y.v01});
        out.v00 = max({x.v01 + y.v00, x.v00 + y.v10, x.v00 + y.v00});
        return out;
    }

    void recalculate(int x) {
        tree[x] = operation(tree[2*x+1], tree[2*x+2]);
    }

    void build(int x, int l, int r) {
        if(l == r) {
            tree[x].v11 = vec[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*x+1, l, mid);
        build(2*x+2, mid+1, r);
        recalculate(x);
    }

    void build() {
        build(0, 0, size-1);
    }

    void update(int x, int l, int r, int id, lli v) {
        if(l == r) {
            tree[x].v11 = v;
            return;
        }
        int mid = (l+r)/2;
        if(id <= mid)
            update(2*x+1, l, mid, id, v);
        else
            update(2*x+2, mid+1, r, id, v);
        recalculate(x);
    }

    void update(int id, lli v) {
        update(0, 0, size-1, id, v);    
    }

    Data query(int x, int l, int r, int lx, int rx) {
        if(lx >r || rx <l) {
            Data tmp;
            tmp.v11 = tmp.v10 = tmp.v01 = tmp.v00 = 0;
            return tmp;
        } 
        if(lx <= l && r <= rx) return tree[x];
        int mid = (l+r)/2;
        Data v1 = query(2*x+1, l, mid, lx, rx);
        Data v2 = query(2*x+2, mid+1, r, lx, rx);
        return operation(v1, v2);
    }

    Data query(int lx, int rx) {
        return query(0, 0, size-1, lx, rx);
    }

};

int main() {
    // usaco();
    int n, d;
    scd(n);
    scd(d);

    Segtree tree;
    tree.init(n);

    frange(i, n) {
        lli v;
        sclld(v);
        tree.set(i, v);
    }

    tree.build();
    lli tot = 0;
    frange(i, d) {
        int id;
        scd(id);
        id--;
        lli v;
        sclld(v);
        tree.update(id, v);
        Data out = tree.query(0, n-1);

        tot += max({out.v11, out.v10, out.v01, out.v00});
    }

    printf("%lld", tot);
}