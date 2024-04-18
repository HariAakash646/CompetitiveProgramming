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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}


const lli mod = 1e9 + 9;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const lli p = uniform_int_distribution<lli>(0, mod - 1)(rng);

vll po;

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

    T operation(T x, T y, lli l)
    {
        return (x * po[l] % mod + y) % mod;
    }

    void recalculate(int x, int l, int r)
    {   
        int mid = (l+r)/2;
        segtree[x] = operation(segtree[2 * x + 1], segtree[2 * x + 2], r-mid);
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
        recalculate(x, l, r);
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
        recalculate(x, l, r);
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
        if(rx > mid)
            return operation(v1, v2, min(r, rx) - mid);
        else return v1;
    }

    T query(int lx, int rx)
    {
        return query(0, 0, size - 1, lx, rx);
    }
};

int main() {
    fastio();
    // usaco();
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;

    po = vll(2*n+1);
    po[0] = 1;

    forr(i, 1, 2*n+1) po[i] = po[i-1] * p % mod;

    string str2 = str;
    reverse(all(str2));

    SegTree<lli> seg1, seg2;
    seg1.init(n, 0);
    seg2.init(n, 0);

    frange(i, n) {
        seg1.set(i, str[i] - 'a' + 1);
        seg2.set(i, str2[i] - 'a' + 1);
    }
    seg1.build();
    seg2.build();

    frange(_, q) {
        int t;
        cin >> t;
        if(t == 1) {
            int id;
            char c;
            cin >> id >> c;
            id--;
            seg1.update(id, c - 'a' + 1);
            seg2.update(n-1-id, c - 'a' + 1);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int mid = (l+r)/2;
            int lm, rm;
            if((r-l) % 2) {
                lm = mid;
                rm = mid+1;
            }
            else {
                lm = mid;
                rm = mid;
            }
            // printf("%d %d %d %d ", l, lm, n-1-r, n-1-rm);
            // printf("%lld %lld\n", seg1.query(l, lm), seg2.query(n-1-r, n-1-rm));
            if(seg1.query(l, lm) == seg2.query(n-1-r, n-1-rm)) cout << ("YES\n");
            else cout << ("NO\n");
        }
    }
}