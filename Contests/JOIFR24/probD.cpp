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
        return min(x, y); // Any required operation
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

    T query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            return def;
        }
        if (lx <= l && r <= rx)
        {
            return segtree[x];
        }
        int mid = (l + r) / 2;
        T v1 = query(2 * x + 1, l, mid, lx, rx);
        T v2 = query(2 * x + 2, mid + 1, r, lx, rx);
        return operation(v1, v2);
    }

    T query(int lx, int rx)
    {
        return query(0, 0, size - 1, lx, rx);
    }
};


int main() {
    // usaco();
    int n;
    scd(n);

    vi v1(n), v2(n);

    frange(i, n) scd(v1[i]);
    frange(i, n) scd(v2[i]);

    int q;
    scd(q);
    if(q <= 10) {
        frange(_, q) {
            int l, r;
            scd(l);
            scd(r);
            l--;
            r--;
            vii vec;
    
            forr(i, l, r+1) {
                // st.insert(mp(v1[i], i));
                vec.pb(mp(v2[i], i));
    
            }
    
            sort(all(vec));
    
            vi vl2(vec.size());
            vl2[0] = v1[vec[0].s];
            forr(i, 1, vec.size()) {
                vl2[i] = max(vl2[i-1], v1[vec[i].s]);
            }
    
            bool done = false;
            int curr = vec.size();
    
            for(int i=vec.size()-1; i>=1; i--) {
                auto p = vec[i];
                int id = lower_bound(all(vl2), p.f) - vl2.begin();
                // printf("%d %d\n", p.f, )
                if(id >= i && i < curr) {
                    done = false;
                    break;
                }
                curr = id;
                if(id == 0) {
                    done = true;
                    break;
                }
    
                
            }
            
            if(done) printf("Yes\n");
            else printf("No\n");
            
        }
    }
    else {
        SegTree<int> tree;
        tree.init(n, 1e9);
        tree.build();
        deque<int> dq;
        frange(i, n) {
            
            while(dq.size() && v1[dq.front()] < v2[i]) dq.pop_front();
            if(dq.size()) {
                // tree.update(i, dq.front());
                tree.update(i, min(dq.front(), tree.query(max(0, dq.front()-1), i)));
            }
            dq.pb(i);
            
        }

        frange(_, q) {
            int l, r;
            scd(l);
            scd(r);
            l--;
            r--;
            if(tree.query(r, r) <= l) printf("Yes\n");
            else printf("No\n");
        }
    }
}