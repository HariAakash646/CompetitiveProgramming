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

struct Data {
  int l=0, r=0, v=0;
};

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
        if(x.v == 0) return y;
        if(y.v == 0) return x;
        T out;
        if(x.v == y.v) {
          out.v = x.v;
          out.l = min(x.l, y.l);
          out.r = max(x.r, y.r);
        }
        else {
          if(x.l == y.l && x.r == y.r) {
            out.l=out.r =0;
            out.v = 0;
            return out;
          }
          if(!(x.l <= y.l && y.r <= x.r)) {
            swap(x, y);
          }
          out.v = x.v;
          if(x.l == y.l) {
            out.l = y.r+1;
            out.r = x.r;
          }
          else {
            out.l = x.l;
            out.r = y.l-1;
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
        return x + y; // Any required operation
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
        segtree[x].f += (r - l + 1) * segtree[x].s;
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

    int query(int x, int l, int r, T v)
    {
        propagate(x, l, r);
        if (l==r)
        {
            if(segtree[x].f >= v) return l;
            else return 1e9;
        }
        int mid = (l + r) / 2;
        propagate(2*x+1, l, mid);
        propagate(2*x+2, mid+1, r);
        if(segtree[2*x+1].f >= v)
          return query(2 * x + 1, l, mid, v);
        else if(segtree[2*x+2].f >= v-segtree[2*x+1].f)
          return query(2 * x + 2, mid + 1, r, v-segtree[2*x+1].f);
        return 1e9;
    }

    int query(T v)
    {
        return query(0, 0, size - 1, v);
    }
};

const int MAXN = 1e6+1;

string str="";
SegTree<Data> seg1;
LazySegTree<int> seg2;

int id = -1;

void Init() {
  Data tmp;
  seg1.init(MAXN, tmp);
  seg1.build();
  seg2.init(MAXN, 0);
  seg2.build();
}

void TypeLetter(char L) {
  id++;
  str += L;
  Data tmp;
  tmp.l = tmp.r = (int)str.size() - 1;
  tmp.v = 1;
  printf("%d %d %d\n", tmp.l, tmp.r, tmp.v);
  seg1.update(id, tmp);
  seg2.update(tmp.l, tmp.r, 1);
}

void UndoCommands(int U) {
  Data out = seg1.query(id-U+1, id);
  out.v = -out.v;
  seg2.update(out.l, out.r, out.v);
  id++;
  printf("%d %d %d\n", out.l, out.r, out.v);
  seg1.update(id, out);
}

char GetLetter(int P) {
  int i1 = seg2.query(P+1);
  cout << str;
  printf(" %d\n", i1);
  return str[i1];

}
