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

template <class T>
struct SegTree
{
    int size = 1, n;
    vector<T> segtree;
    vector<pii> vec;

    void init(int l)
    {
        n = l;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, vii());
        vec.assign(size, mp(0, 0));
    }

    T operation(T x, T y)
    {
        T out(x.size() + y.size());
        merge(all(x), all(y), out.begin()); // Any required operation
        return out;
    }

    void recalculate(int x)
    {
        segtree[x] = operation(segtree[2 * x + 1], segtree[2 * x + 2]);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x].pb(vec[l]);
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

    void set(int id, pii val)
    {
        vec[id] = val;
    }

    bool query(int x, int l, int r, int lx, int rx, pii p)
    {
        if (lx > r || rx < l)
        {
            return false;
        }
        if (lx <= l && r <= rx)
        {
            return binary_search(all(segtree[x]), p);
        }
        int mid = (l + r) / 2;
        bool v1 = query(2 * x + 1, l, mid, lx, rx, p);
        bool v2 = query(2 * x + 2, mid + 1, r, lx, rx, p);
        return v1 || v2;
    }

    bool query(int lx, int rx, pii p)
    {
        return query(0, 0, size - 1, lx, rx, p);
    }
};

int main() {
    fastio();
    // usaco();
    
    int n, q;
    cin >> n >> q;

    string str;
    cin >> str;

    SegTree<vii> segtree;
    segtree.init(n+1);

    pii curr = mp(0, 0);
    segtree.set(0, curr);

    vii vec(n+1);
    vec[0] = curr;

    forr(i, 1, n+1) {
        if(str[i-1] == 'L') curr.f--;
        else if(str[i-1] == 'R') curr.f++;
        else if(str[i-1] == 'U') curr.s++;
        else curr.s--;
        segtree.set(i, curr);
        vec[i] = curr;
    }

    segtree.build();

    frange(_, q) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        bool out = segtree.query(0, l-1, mp(x, y));
        int x1 = x - vec[l-1].f;
        int y1 = y - vec[l-1].s;
        out = out || (segtree.query(l-1, r, mp(vec[r].f - x1, vec[r].s - y1)));
        x1 = x - vec[r].f;
        y1 = y - vec[r].s;
        out = out || (segtree.query(r, n, mp(x, y)));
        if(out) cout << "YES\n";
        else cout << "NO\n";
    }
}