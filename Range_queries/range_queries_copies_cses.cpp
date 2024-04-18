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

struct Node {
    Node *lc;
    Node *rc;
    int l, r;
    lli v = 0;
};

template <class T>
struct SegTree
{
    int size = 1, n;
    
    vector<Node*> segs;
    T def; // Assign a value
    vector<T> vec;
    void init(int l, T defv)
    {
        n = l;
        def = defv;

        while (size < n)
            size *= 2;

        Node* nd;
        (*nd).l = 0;
        (*nd).r = size-1;
        segs.pb(nd);

        vec.assign(size, defv);
        
    }

    T operation(T x, T y)
    {
        return x + y; // Any required operation
    }

    void recalculate(Node *nd)
    {
        (*nd).v = operation((*(*nd).lc).v, (*(*nd).rc).v);
    }

    void build(Node *nd)
    {
        printf("%d %d\n", nd->l, nd->r);
        if ((*nd).l == (*nd).r)
        {
            (*nd).v = vec[(*nd).l];
            return;
        }

        int mid = ((*nd).l + (*nd).r)/2;

        Node ndl, ndr;
        
        ndl.l = (*nd).l;
        ndl.r = mid;

        ndr.l = mid+1;
        ndr.r = (*nd).r;

        nd->lc = &ndl;
        nd->rc = &ndr;

        build(nd->lc);
        build(nd->rc);

        recalculate(nd);
    }

    void build()
    {
        
        build(segs[0]);
        // printf("%lld\n", (*segs[0].rc).v);
    }

    void set(int id, T val)
    {
        vec[id] = val;
    }

    // void update_diff(Node &nd, Node &og, int id, T val)
    // {
    //     if (nd->l == nd->r)
    //     {
    //         nd->v = val;
    //         return;
    //     }

    //     int mid = (nd->l + nd->r)/2;

    //     if (id <= mid)
    //     {
    //         Node ndl;
    //         ndl.l = nd->l;
    //         ndl.r = mid;

    //         nd->lc = &ndl;
    //         nd->rc = og.rc;

    //         update_diff(ndl, og.lc, id, val);
    //     }
    //     else
    //     {
    //         Node ndr;
    //         ndr.l = mid+1;
    //         ndr.r = nd->r;

    //         nd->lc = og.lc;
    //         nd->rc = &ndr;

    //         update_diff(ndr, og.rc, id, val);
    //     }
    //     recalculate(nd);
    // }

    void update_same(Node *nd, int id, T val)
    {
        if (nd->l == nd->r)
        {
            nd->v = val;
            return;
        }

        int mid = (nd->l + nd->r)/2;
        printf("%d %d %d\n", nd->l, nd->r, mid);
        if (id <= mid)
        {
            update_same(*nd->lc, id, val);
        }
        else
        {
            update_same(*nd->rc, id, val);
        }
        recalculate(nd);
    }

    void update(int arr, int id, T val)
    {
        update_same(segs[arr], id, val);
    }

    T query(Node* nd, int lx, int rx)
    {
        if (lx > nd->r || rx < nd->l)
        {
            return def;
        }
        if (lx <= nd->l && nd->r <= rx)
        {
            return nd->v;
        }
        int mid = (nd->l + nd->r) / 2;
        T v1 = query(nd->lc, lx, rx);
        T v2 = query(nd->rc, lx, rx);
        return operation(v1, v2);
    }

    T query(int arr, int lx, int rx)
    {
        return query(segs[arr], lx, rx);
    }

    void copy(int arr) {
        segs.pb(segs[arr]);
    }

    void rec(Node* nd) {
        printf("%d %d\n", nd->l, nd->r);
        if(nd->l == nd->r) return;
        rec(nd->lc);
        rec(nd->rc);
    }
};

int main() {
    usaco();
    int n, q;
    scd(n);
    scd(q);

    SegTree<lli> segtree;

    segtree.init(n, 0);

    frange(i, n) {
        lli a;
        sclld(a);
        segtree.set(i, a);
    }

    segtree.build();

    // frange(_, q) {
    //     int t;
    //     scd(t);
    //     if(t == 1) {
    //         int k, a;
    //         lli x;
    //         scd(k);
    //         scd(a);
    //         sclld(x);
    //         k--;
    //         a--;
    //         segtree.update(k, a, x);
    //     }
    //     else if(t == 2) {
    //         int a, b, k;
    //         scd(k);
    //         scd(a);
    //         scd(b);
    //         k--;
    //         a--;
    //         b--;
    //         printf("%lld\n", segtree.query(k, a, b));
    //     }
    //     else {
    //         int k;
    //         scd(k);
    //         k--;
    //         segtree.copy(k);
    //     }
    // }
    segtree.rec(segtree.segs[0]);

}