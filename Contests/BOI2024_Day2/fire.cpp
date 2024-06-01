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

vector<vi> lift;
vii vec;

int binlift(int x, int c) {
    
    frange(i, 20) {
        if(c & (1<<i)) {
            x = lift[i][x];
        }
    }
    return x;
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    vec = vii(n);
    frange(i, n) {
        scd(vec[i].s);
        scd(vec[i].f);
        if(vec[i].f < vec[i].s) vec[i].f += m;
    }
    sort(all(vec));
    int mi = 2e9+10;
    // vii v2;
    // for(int i=n-1; i>=0; i--) {
    //     auto p = vec[i];
    //     if(p.s < mi) v2.pb(p);
    //     mi = min(mi, p.s);
    // }

    // vec = v2;
    // sort(all(vec));

    n = vec.size();

    lift = vvi(20, vi(n));

    deque<int> dq;
    int id = 0;

    frange(i, n) {
        while(id < n && vec[id].s <= vec[i].f) {
            while(dq.size() && vec[dq.back()].f <= vec[id].f) dq.pop_back();
            dq.pb(id);
            id++;
        }
        
        while(dq.size() && vec[dq.front()].s < vec[i].s) dq.pop_front();
        lift[0][i] = dq.back();
    }



    forr(i, 1, 20) {
        // deque<int> dq;
        // int id = 0;
        // frange(j, n) {
        //     while(id < n && vec[id].s <= lift[i-1][j]) {
        //         while(dq.size() && lift[i-1][dq.back()] <= lift[i-1][id]) dq.pop_back();
        //         dq.pb(id);
        //         id++;
        //     }
            
        //     while(dq.size() && vec[dq.front()].s < vec[j].s) dq.pop_front();
        //     lift[i][j] = lift[i-1][dq.front()];
        // }
        frange(j, n) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    mi = n+1;

    frange(i, n) {
        int lo = 0;
        int hi = n;

        while(lo != hi) {
            int mid = (lo+hi)/2;
            // printf("%d %d %d\n", vec[i].s, mid, vec[binlift(i, mid)].f);
            if(vec[binlift(i, mid)].f-m >= vec[i].s) hi = mid;
            else lo = mid+1;
        }
        mi = min(mi, lo+1);
    }
    if(mi <= n)
    printf("%d", mi);
    else printf("-1");
}