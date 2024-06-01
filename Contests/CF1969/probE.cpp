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
struct LazySegTree
{
    int size = 1, n;
    vector<pair<T, T>> segtree;
    vector<T> vec;

    T def1; // Assign a value

    void init(int l, T d1)
    {
        n = l;
        def1 = d1;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, mp(def1, 0));
        vec.assign(size, def1);
    }

    T operation(T x, T y)
    {
        return min(x, y); // Any required operation
    }

    void recalculate(int x)
    {
        segtree[x].f = operation(segtree[2 * x + 1].f, segtree[2 * x + 2].f);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x].f = vec[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * x + 1, l, mid);
        build(2 * x + 2, mid + 1, r);
        recalculate(x);
    }

    void build()
    {
        build(0, 0, size - 1);
    }

    void set(int id, T val)
    {
        vec[id] = val;
    }

    void propagate(int x, int l, int r)
    {
        segtree[x].f += segtree[x].s;
        if (l < r)
        {
            segtree[2 * x + 1].s += segtree[x].s;
            segtree[2 * x + 2].s += segtree[x].s;
        }
        segtree[x].s = 0;
    }

    void update(int x, int l, int r, int lx, int rx, T val)
    {
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            segtree[x].s += val;
            return;
        }
        int mid = (l + r) / 2;
        if (lx <= mid)
        {
            update(2 * x + 1, l, mid, lx, rx, val);
        }
        if (rx >= mid + 1)
        {
            update(2 * x + 2, mid + 1, r, lx, rx, val);
        }
        propagate(2 * x + 1, l, mid);
        propagate(2 * x + 2, mid + 1, r);
        recalculate(x);
    }

    void update(int lx, int rx, T val)
    {
        update(0, 0, size - 1, lx, rx, val);
    }

    int query(int x, int l, int r)
    {
        // printf("%d %d\n", l, r);
        propagate(x, l, r);
        // printf("%d %d %d\n", l, r, segtree[x].f);
        if (l == r)
        {   
            if(segtree[x].f <= 0)
                return l;
            else return n;
        }
        int mid = (l + r) / 2;
        propagate(2 * x + 1, l, mid);
        propagate(2 * x + 2, mid + 1, r);
        if(segtree[2*x+1].f <= 0)
            return query(2 * x + 1, l, mid);
        else
            return query(2 * x + 2, mid + 1, r);
    }

    int query()
    {
        return query(0, 0, size - 1);
    }
};


int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        vi vec(n);
        frange(i, n) scd(vec[i]);

        vi pos(n+1);
        vi pre(n), nex(n, n);
        frange(i, n) {
            pre[i] = pos[vec[i]];
            pos[vec[i]] = i;
        }
        pos = vi(n+1, n);
        for(int i=n-1; i>=0; i--) {
            nex[i] = pos[vec[i]];
            pos[vec[i]] = i;
        }

        LazySegTree<int> tree;
        tree.init(n, 1e9);
        tree.build();
        vi val(n);
        for(int i=n-1; i>=0; i--) {
            tree.update(i, i, -1e9);
            int v = nex[i]-1;
            tree.update(i, v, 1);
            if(nex[i] < n)
                tree.update(nex[i], nex[nex[i]]-1, -1);
            // printf("%d\n", i);
            int id = tree.query();
            // printf("\n");
            val[i] = id;          
        }
        int id = 0;
        int i1 = 0;
        int c = 0;
        while(id < n) {
            id = val[i1];

            while(i1 < min(n-1, id)) {

                i1++;

                id = min(id, val[i1]);
                // printf("%d: %d\n", i1, val[i1]);
            }
            // printf("%d ", id);
            if(id < n) c++;
            id = i1 = id +1;
        }
        // printf("**************\n");
        printf("%d\n", c);
    }
}