#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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
    freopen("input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

template <class T>
struct LazySegTree
{
    struct Node {
        T val=0;
        T lazy = 0;
        int lc=-1, rc=-1;
        int lr, rr;
    };
    int size = 1, n;
    vector<Node> segtree;

    T def1; // Assign a value
    int id;
    void init(int l, T d1)
    {
        n = l;
        def1 = d1;

        while (size < n)
            size *= 2;

        Node tmp;
        tmp.lr = 0;
        tmp.rr = size-1;
        segtree.assign(64*2e5+1, tmp);
        id = 1;
    }

    T operation(T x, T y)
    {
        return x + y;
    }

    void recalculate(int x)
    {
        segtree[x].val = 0;
        if(segtree[x].lc != -1) segtree[x].val += segtree[segtree[x].lc].val;
        if(segtree[x].rc != -1) segtree[x].val += segtree[segtree[x].rc].val;
    }

    void propagate(int x, int l, int r)
    {
        segtree[x].val += (r-l+1) * segtree[x].lazy;
        if (l < r)
        {
            int mid = (l + r)/2;
            if(segtree[x].lc == -1) {
                segtree[x].lc = id++;
                segtree[segtree[x].lc].lr = l;
                segtree[segtree[x].lc].rr = mid;
            }
            if(segtree[x].rc == -1) {
                segtree[x].rc = id++;
                segtree[segtree[x].rc].lr = mid+1;
                segtree[segtree[x].rc].rr = r;
            }
            segtree[segtree[x].lc].lazy += segtree[x].lazy;
            segtree[segtree[x].rc].lazy += segtree[x].lazy;
        }
        segtree[x].lazy = 0;
    }

    void update(int x, int l, int r, int lx, int rx, T val)
    {
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            segtree[x].lazy += val;
            return;
        }
        int mid = (l + r) / 2;
        if (lx <= mid)
        {
            if(segtree[x].lc == -1) {
                segtree[x].lc = id++;
                segtree[segtree[x].lc].lr = l;
                segtree[segtree[x].lc].rr = mid;
            }
            update(segtree[x].lc, l, mid, lx, rx, val);
            
        }
        if (rx >= mid + 1)
        {
            if(segtree[x].rc == -1) {
                segtree[x].rc = id++;
                segtree[segtree[x].rc].lr = mid+1;
                segtree[segtree[x].rc].rr = r;
            }
            update(segtree[x].rc, mid + 1, r, lx, rx, val);
        }
        if(segtree[x].lc != -1)
            propagate(segtree[x].lc, l, mid);
        if(segtree[x].rc != -1) {
            propagate(segtree[x].rc, mid + 1, r);
        }
        recalculate(x);
    }

    void update(int lx, int rx, T val)
    {
        update(0, 0, size - 1, lx, rx, val);
    }

    T query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            return def1;
        }
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            return segtree[x].val;
        }
        int mid = (l + r) / 2;
        if(segtree[x].lc == -1) {
            segtree[x].lc = id++;
            segtree[segtree[x].lc].lr = l;
            segtree[segtree[x].lc].rr = mid;
        }
        if(segtree[x].rc == -1) {
            segtree[x].rc = id++;
            segtree[segtree[x].rc].lr = mid+1;
            segtree[segtree[x].rc].rr = r;
        }
        T v1 = query(segtree[x].lc, l, mid, lx, rx);
        T v2 = query(segtree[x].rc, mid + 1, r, lx, rx);
        return operation(v1, v2);
    }

    T query(int lx, int rx)
    {
        return query(0, 0, size - 1, lx, rx);
    }
};

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);
    LazySegTree<lli> segtree;
    segtree.init(n, 0);

    frange(_, q) {
        int t;
        scd(t);
        int l, r;
        scd(l);
        scd(r);
        l--;
        r--;
        if(t == 1) {
            lli v;
            sclld(v);
            segtree.update(l, r, v);
        }
        else {
            printf("%lld\n", segtree.query(l, r));
        }
    }
}