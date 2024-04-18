#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t);
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const lli mod = 1e9 + 7;

struct Data {
    bool curr = true;
    lli arr[8][8] = {0};
};

struct SegTree
{
    int size = 1, n;
    vector<Data> segtree;
    vector<int> vec;
    vector<vll> val;

    int def = 0; // Assign a value

    void init(int l)
    {
        n = l;

        while (size < n)
            size *= 2;

        segtree = vector<Data>(2 * size);
        vec = vi(size);
        val = vector<vll>(8, vll(8));

        // frange(i, 8) val[i][i] = 1;

        frange(j, 8) {
            val[0][j]++;
            val[3][j]++;
            val[6][j]++;
            frange(k, 3) {
                if((j & (1<<k)) == 0) {
                    val[1<<k][j]++;
                }
            }
        }
        val[7][0] += 3;
        val[7][1]++;
        val[7][4]++;
        val[7][2] += 2;
        val[7][3]++;
        val[7][6]++;
        val[3][0]++;
        val[3][4]++;
        val[6][0]++;
        val[6][1]++;
        val[5][0]++;
        val[5][2]++;
    }

    Data operation(Data x, Data y)
    {
        if(!x.curr) return y;
        if(!y.curr) return x;
        Data out;
        out.curr = true;

        frange(i, 8) {
            frange(j, 8) {
                frange(k, 8) {
                    out.arr[i][j] += y.arr[i][k] * x.arr[k][j];
                    out.arr[i][j] %= mod;
                }
            }
        }
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
            // cout << l << ": " << vec[l] << "\n";
            Data tmp;
            frange(j, 8) {
                if((j | vec[l]) == j) {
                    frange(k, 8)
                        tmp.arr[j][k] = val[j^vec[l]][k];
                }
            }
            segtree[x] = tmp;
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

    void set(int id, int v)
    {
        vec[id] = v;
    }

    void update(int x, int l, int r, int id, int v)
    {
        if (l == r)
        {
            vec[l] = v;
            Data tmp;
            frange(j, 8) {
                if((j | vec[l]) == j) {
                    frange(k, 8)
                        tmp.arr[j][k] = val[j^vec[l]][k];
                }
            }
            segtree[x] = tmp;
            return;
        }
        int mid = (l + r) / 2;
        if (id <= mid)
        {
            update(2 * x + 1, l, mid, id, v);
        }
        else
        {
            update(2 * x + 2, mid + 1, r, id, v);
        }
        recalculate(x);
    }

    void update(int id, int v)
    {
        update(0, 0, size - 1, id, v);
    }

    Data query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            Data tmp;
            tmp.curr = false;
            return tmp;
        }
        if (lx <= l && r <= rx)
        {
            return segtree[x];
        }
        int mid = (l + r) / 2;
        Data v1 = query(2 * x + 1, l, mid, lx, rx);
        Data v2 = query(2 * x + 2, mid + 1, r, lx, rx);
        return operation(v1, v2);
    }

    lli query(int lx, int rx)
    {
        Data out = query(0, 0, size - 1, lx, rx);
        // frange(i, 8) {
        //     frange(j, 8) {
        //         cout << out.arr[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        lli tot = 0;
        frange(i, 8) tot += out.arr[i][7];
        tot %= mod;
        return tot;
    }
};


int main() {
    // usaco();
    fastio();
    int n, q;
    cin >> n >> q;

    vi grid(n);
    SegTree segtree;
    segtree.init(n);
    frange(i, 3) {
        string str;
        cin >> str;
        frange(j, n) {
            if(str[j] == 'x')
                grid[j] += (1<<i);
        }
    }

    frange(i, n) segtree.set(i, grid[i]);
    segtree.build();
    // cout << segtree.query(0, 0) << "\n";
    // Data out = segtree.query(0, 0,)
    frange(_, q) {
        int t;
        cin >> t;
        if(t == 1) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            grid[y] = grid[y] ^ (1<<x);
            segtree.update(y, grid[y]);
        }
        else {
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            
            cout << segtree.query(l, r) << "\n";
        }
    }
}