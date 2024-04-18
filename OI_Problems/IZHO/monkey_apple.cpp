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
        T val;
        bool lazy;
        int lc=-1, rc=-1;
        int lr=0, rr=0;
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
        tmp.val = def1;
        tmp.lazy = false;
        segtree.assign(64*1e5+1, tmp);
        segtree[0].val = def1;
        segtree[0].lazy = false;
        segtree[0].lr = 0;
        segtree[0].rr = size;
        id = 1;
    }

    T operation(T x, T y)
    {
        return x + y;
    }

    void recalculate(int x)
    {
        if(segtree[x].lc != -1 && segtree[x].rc != -1)
            segtree[x].val = operation(segtree[segtree[x].lc].val, segtree[segtree[x].rc].val);
        else if(segtree[x].lc != -1) {
            segtree[x].val = segtree[segtree[x].lc].val;
        }
        else if(segtree[x].rc != -1) {
            segtree[x].val = segtree[segtree[x].rc].val;
        }
        
    }


    void propagate(int x)
    {
        if(segtree[x].lazy)
            segtree[x].val = (segtree[x].rr - segtree[x].lr + 1);
        if (segtree[x].lazy)
        {
            int mid = (segtree[x].lr + segtree[x].rr)/2;
            if(segtree[x].lc == -1) {
                segtree[x].lc = id++;
                segtree[segtree[x].lc].val = 0;
                segtree[segtree[x].lc].lr = segtree[x].lr;
                segtree[segtree[x].lc].rr = mid;
            }

            if(segtree[x].rc == -1) {
                segtree[x].rc = id++;
                segtree[segtree[x].rc].val = 0;
                segtree[segtree[x].rc].lr = mid+1;
                segtree[segtree[x].rc].rr = segtree[x].rr;
            }
            segtree[segtree[x].lc].lazy = true;
            segtree[segtree[x].rc].lazy = true;
        }
        segtree[x].lazy = false;
    }

    void update(int x, int lx, int rx)
    {
        int l = segtree[x].lr;
        int r = segtree[x].rr;
        propagate(x);
        if (lx <= l && r <= rx)
        {
            segtree[x].lazy = true;
            return;
        }
        int mid = (l + r) / 2;
        if (lx <= mid)
        {
            if(segtree[x].lc == -1) {
                segtree[x].lc = id++;
                segtree[segtree[x].lc].val = def1;
                segtree[segtree[x].lc].lr = l;
                segtree[segtree[x].lc].rr = mid;
            }
            update(segtree[x].lc, lx, rx);
            propagate(segtree[x].lc);
        }
        if (rx >= mid + 1)
        {
            if(segtree[x].rc == -1) {
                segtree[x].rc = id++;
                segtree[segtree[x].rc].val = def1;
                segtree[segtree[x].rc].lr = mid+1;
                segtree[segtree[x].rc].rr = r;
            }
            update(segtree[x].rc, lx, rx);
            propagate(segtree[x].rc);
        }
        
        recalculate(x);
    }

    void update(int lx, int rx)
    {
        update(0, lx, rx);
    }

    T query(int x, int lx, int rx)
    {
        int l = segtree[x].lr;
        int r = segtree[x].rr;
        if (lx > r || rx < l)
        {
            return def1;
        }
        propagate(x);
        if(segtree[x].val == 0) return 0;
        
        if (lx <= l && r <= rx)
        {
            return segtree[x].val;
        }
        int mid = (l + r) / 2;
        if(segtree[x].lc == -1) {
            segtree[x].lc = id++;
            segtree[segtree[x].lc].val = def1;
            segtree[segtree[x].lc].lr = l;
            segtree[segtree[x].lc].rr = mid;
        }
        
        if(segtree[x].rc == -1) {
            segtree[x].rc = id++;
            segtree[segtree[x].rc].val = def1;
            segtree[segtree[x].rc].lr = mid+1;
            segtree[segtree[x].rc].rr = r;
        }
        T v1 = query(segtree[x].lc, lx, rx);
        T v2 = query(segtree[x].rc, lx, rx);
        return operation(v1, v2);
    }

    T query(int lx, int rx)
    {
        return query(0, lx, rx);
    }
};

int main() {
    // usaco();
    int m;
    scd(m);
    LazySegTree<int> segtree;
    segtree.init(1e9, 0);

    int c = 0;
    frange(i, m) {
        int d;
        scd(d);
        if(d == 1) {
            int x, y;
            scd(x);
            scd(y);
            x--;
            y--;
            x+=c;
            y+=c;
            int v = segtree.query(x, y);
            printf("%d\n", v);
            c = v;
        }
        else {
            int x, y;
            scd(x);
            scd(y);
            x--;
            y--;
            x+=c;
            y+=c;
            segtree.update(x, y);
            // frange(j, 10) {
            //     printf("%d ", segtree.query(j, j));

            // }
            // printf("\n");
        }
    }
}

