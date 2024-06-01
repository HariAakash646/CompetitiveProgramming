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
   // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "w", stdout);
}

template <class T> 
struct Data {
    T v=1e9;
    int lc=-1, rc=-1;
};

template <class T>
struct PersistentSegtree {
    vector<Data<T>> tree;
    vi root;
    int n, sz;

    void init(int l) {
        n = l;
        sz = 1;
        while(sz < n) sz *= 2;
        Data<T> tmp;
        tmp.v = 1e9;
        tree.pb(tmp);
        root.pb(0);
    } 

    T operation(T x, T y) {
        return min(x, y);
    }

    void recalculate(int x) {
        if(tree[x].lc==-1 && tree[x].rc == -1) return;
        else if(tree[x].lc == -1) tree[x].v = tree[tree[x].rc].v;
        else if(tree[x].rc == -1) tree[x].v = tree[tree[x].lc].v;
        else
            tree[x].v = operation(tree[tree[x].lc].v, tree[tree[x].rc].v);
    }

    void update(int x, int l, int r, int id, T v) {
        if(l == r) {
            tree[x].v = v;
            return;
        }
        int mid = (l+r)/2;
        if(id <= mid) {
            Data<T> tmp;
            if(tree[x].lc != -1) tmp = tree[tree[x].lc];
            tree[x].lc = tree.size();
            
            tree.pb(tmp);
            update(tree[x].lc, l, mid, id, v);
        }
        else {
            Data<T> tmp;
            if(tree[x].rc != -1) tmp = tree[tree[x].rc];
            tree[x].rc = tree.size();
            
            tree.pb(tmp);
            update(tree[x].rc, mid+1, r, id, v);
        }
        recalculate(x);
    }

    void update(int id, T v) {
        Data<T> tmp = tree[root.back()];
        root.pb(tree.size());
        tree.pb(tmp);
        // if(v >= tmp.v) return;
        update(root.back(), 0, sz-1, id, v);
    }

    T query(int x, int l, int r, int lx, int rx) {
        if(lx > r || rx < l) {
            return 1e9;
        }
        if(lx <= l && r <= rx) {
            return tree[x].v;
        }
        int mid = (l+r)/2;
        T v1 = 1e9;
        if(tree[x].lc != -1) v1 = query(tree[x].lc, l, mid, lx, rx);
        T v2 = 1e9;
        if(tree[x].rc != -1) v2 = query(tree[x].rc, mid+1, r, lx, rx);
        return operation(v1, v2);
    }

    T query(int id, int lx, int rx) {
        T v = query(root[id], 0, sz-1, lx, rx);
        if(v >= 1e9) return -1;
        return v;
    } 
};

int main() {
    // usaco();
    // printf("500000 1\n");
    // frange(i, 500000) printf("1 ");
    // printf("\n1 500000\n");
    // fflush(stdout);
    int n, m;
    scd(n);
    scd(m);

    mpii mv;
    PersistentSegtree<int> tree;
    tree.init(n+1);

    forr(i, 1, n+1) {
        int x;
        scd(x);
        tree.update(mv[x], i-mv[x]);
        mv[x] = i;
    }

    // mv = {};

    

    frange(_, m) {
        int l, r;
        scd(l);
        scd(r);
        printf("%d\n", tree.query(r, l, r));
    }

    // printf("%d\n", (int)tree.tree.size());
}