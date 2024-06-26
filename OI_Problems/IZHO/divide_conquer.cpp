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
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

template <class T>
struct SegTree
{
    int size = 1, n;
    vector<T> segtree;
    vector<T> vec;

    T def; // Assign a value

    void init(int l, T defv)
    {
        n = l;
        def = defv;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, def);
        vec.assign(size, def);
    }

    T operation(T x, T y)
    {
        return max(x, y); // Any required operation
    }

    void recalculate(int x)
    {
        segtree[x] = operation(segtree[2 * x + 1], segtree[2 * x + 2]);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x] = vec[l];
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

    void update(int x, int l, int r, int id, T val)
    {
        if (l == r)
        {
            segtree[x] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (id <= mid)
        {
            update(2 * x + 1, l, mid, id, val);
        }
        else
        {
            update(2 * x + 2, mid + 1, r, id, val);
        }
        recalculate(x);
    }

    void update(int id, T val)
    {
        update(0, 0, size - 1, id, val);
    }

    int query(int x, int l, int r, int lx, T v)
    {
        if (lx > r)
        {
            return -1;
        }
        if(l == r) {
            if(segtree[x] >= v)
                return l;
            else return -1;
        }
        
        int mid = (l + r) / 2;
        if(segtree[2*x+2] >= v) {
            return query(2 * x + 2, mid + 1, r, lx, v);
        }
        else return query(2 * x + 1, l, mid, lx, v);
    }

    int query(int lx, T v)
    {
        return query(0, 0, size - 1, lx, v);
    }
};

int main() {
    // usaco();
    int n;
    scd(n);
    vll pos(n+1), gold(n+1), en(n+1), ppos(n+1), pgold(n+1), pen(n+1);

    forr(i, 1, n+1) {
        sclld(pos[i]);
        ppos[i] = ppos[i-1] + pos[i];
        sclld(gold[i]);
        pgold[i] = pgold[i-1] + gold[i];
        sclld(en[i]);
        pen[i] = pen[i-1] + en[i];
        // printf("%lld ", pgold[i]);
    }

    SegTree<lli> segtree;
    segtree.init(n+1, -1e18);

    forr(i, 1, n+1) {
        segtree.set(i, pen[i] - pos[i]);
    }

    segtree.build();
    lli ma = 0;
    forr(i, 1, n+1) {
        lli d = pen[i-1] - pos[i];
        int id = segtree.query(i, d);
        if(id != -1) {
            // printf("\n%d\n", id);
            ma = max(ma, pgold[id] - pgold[i-1]);
        }
    }
    printf("%lld", ma);

}