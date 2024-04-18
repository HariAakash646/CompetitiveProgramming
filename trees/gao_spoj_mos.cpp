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

vvi graph;
int timer = 0;
int timer2 = 0;
vi st, st2, en2, timv, depth, timv2;

void dfs(int x, int p) {
    st[x] = timer++;
    st2[x] = timer2++;
    timv2.pb(x);
    timv.pb(x);

    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
            timv.pb(x);
            timer++;
        }
    }
    en2[x] = timer2++;
    timv2.pb(x);
}

int bsze;

struct Query {
    int l, r;
    int id;
    int c;
    int lca=0;

    bool operator<(Query other) const {
        return mp(l/ bsze, r) < mp(other.l / bsze, other.r);
    }
};

int main() {
    // usaco();
    int n, m;
    m=-1;
    while(cin >> n) {
        if(m != -1) printf("\n");
        scd(m);
        timer = timer2 = 0;
        timv = timv2 = {};
        vi val(n+1);
        forr(i, 1, n+1) scd(val[i]);
    
        graph = vvi(n+1);
        depth = st = st2 = en2 = vi(n+1);
    
        frange(i, n-1) {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }
    
        dfs(1, 0);
        int x = timv.size();
    
        SegTree<pii> segtree;
    
        segtree.init(x, mp(1e9, 0));
    
        frange(i, x) {
            segtree.set(i, mp(depth[timv[i]], timv[i]));
        }
    
        segtree.build();
    
        bsze = sqrt(timer2);
        vector<Query> quer(m);
    
        frange(i, m) {
            int a, b, c;
            scd(a);
            scd(b);
            scd(c);
    
            if(st[b] < st[a]) swap(a, b);
            int lca = segtree.query(st[a], st[b]).s;
    
            if(lca == a) {
                quer[i].l = st2[a];
                quer[i].r = st2[b];
            }
            else {
                quer[i].l = en2[a];
                quer[i].r = st2[b];
                quer[i].lca = lca;
            }
            quer[i].c = c;
            quer[i].id = i+1;
        }
    
        sort(all(quer));
    
        vi cnt(n+1);
        vb out(n+1);
        int l = 0;
        int r = 0;
        cnt[val[timv2[0]]]++;
        for(auto p : quer) {
            // printf("%d %d %d %d\n", p.l, p.r, p.lca, p.c);
            while(l < p.l) {
                if(st2[timv2[l]] == l)
                    cnt[val[timv2[l]]]--;
                else cnt[val[timv2[l]]]++;
                l++;
            }
    
            while(l > p.l) {
                l--;
                if(st2[timv2[l]] == l)
                    cnt[val[timv2[l]]]++;
                else cnt[val[timv2[l]]]--;
            }
    
            while(r < p.r) {
                r++;
                if(st2[timv2[r]] == r)
                    cnt[val[timv2[r]]]++;
                else cnt[val[timv2[r]]]--;
            }
    
            while(r > p.r) {
                if(st2[timv2[r]] == r)
                    cnt[val[timv2[r]]]--;
                else cnt[val[timv2[r]]]++;
                r--;
            }
            // forr(i, 1, n+1) printf("%d ", cnt[i]);
            // printf("\n");
            int d = 0;
            if(p.lca) {
                if(val[p.lca] == p.c) d=1;
            }
            
            if(cnt[p.c] || d) out[p.id] = true;
        }
    
        forr(i, 1, n+1) {
            if(out[i]) printf("Find\n");
            else printf("NotFind\n");
        }
        
    }

}