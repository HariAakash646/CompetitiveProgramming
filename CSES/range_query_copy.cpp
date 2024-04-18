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

struct Data {
    lli v = 0;
    int l = -1;
    int r = -1;
    int lc = -1;
    int rc = -1;
    int co = 0;
};

struct PersistentSegtree {
    int size;
    vector<Data> segtree;
    vll vec;
    vi copy;

    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        vec = vll(size);
        Data tmp;
        
        tmp.co = 0;
        segtree.pb(tmp);
        copy.pb(0);
    }

    void set(int id, lli v) {
        vec[id] = v;
    }

    void recalculate(int x) {
        segtree[x].v = segtree[segtree[x].lc].v + segtree[segtree[x].rc].v;
    }

    void build(int x, int l, int r) {
        if(l == r) {
            segtree[x].v = vec[l];
            return;
        }
        int mid = (l + r)/2;
        if(segtree[x].lc == -1) {
            Data tmp;
            
            tmp.co = segtree[x].co;
            segtree[x].lc = segtree.size();
            segtree.pb(tmp);
        }
        if(segtree[x].rc == -1) {
            Data tmp;
            
            tmp.co = segtree[x].co;
            segtree[x].rc = segtree.size();
            segtree.pb(tmp);
        }
        build(segtree[x].lc, l, mid);
        build(segtree[x].rc, mid+1, r);

        recalculate(x);
    }

    void build() {
        build(0, 0, size-1);
    }

    void update(int x, int l, int r, int id, lli v) {
        if(l == r) {
            segtree[x].v = v;
            return;
        }
        int mid = (l+r)/2;
        if(id <= mid) {
            Data tmp;
            
            tmp.co = segtree[x].co;
            tmp.lc = segtree[segtree[x].lc].lc;
            tmp.rc = segtree[segtree[x].lc].rc;
            segtree[x].lc = segtree.size();
            segtree.pb(tmp);
            update(segtree[x].lc, l, mid, id, v);
        }
        else {
            Data tmp;
            
            tmp.co = segtree[x].co;
            tmp.lc = segtree[segtree[x].rc].lc;
            tmp.rc = segtree[segtree[x].rc].rc;
            segtree[x].rc = segtree.size();
            segtree.pb(tmp);

            update(segtree[x].rc, mid+1, r, id, v);
        }
        recalculate(x);
    }

    void update(int k, int id, lli v) {
        update(copy[k], 0, size-1, id, v);
    }

    lli query(int x, int l, int r, int lx, int rx) {
        if(lx <= l && r <= rx) {
            return segtree[x].v;
        }
        if(l > rx || r < lx) return 0;

        int mid = (l+r)/2;
        lli v1 = query(segtree[x].lc, l, mid, lx, rx);
        lli v2 = query(segtree[x].rc, mid+1, r, lx, rx);
        return v1 + v2;
    }

    lli query(int k, int lx, int rx) {
        return query(copy[k], 0, size-1, lx, rx);
    }

    void copy_query(int k) {
        Data tmp = segtree[copy[k]];
        tmp.co = copy.size();
        copy.pb(segtree.size());
        segtree.pb(tmp);
    }
};

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);

    PersistentSegtree segtree;
    segtree.init(n);

    frange(i, n) {
        lli a;
        sclld(a);
        segtree.set(i, a);
    }

    segtree.build();

    segtree.copy_query(1);

    frange(_, q) {
        int t;
        scd(t);

        if(t == 1) {
            int k, a;
            lli x;
            scd(k);
            scd(a);
            sclld(x);
            a--;
            segtree.update(k, a, x);
        }
        else if(t == 2) {
            int k, l, r;
            scd(k);
            scd(l);
            scd(r);
            l--;
            r--;
            printf("%lld\n", segtree.query(k, l, r));
        }
        else {
            int k;
            scd(k);
            segtree.copy_query(k);
        }
    }
}