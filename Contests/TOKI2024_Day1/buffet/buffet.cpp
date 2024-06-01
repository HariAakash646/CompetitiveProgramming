#include "buffet.h"
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

int n;
vi vec;

struct Data {
  int l, r;

  bool operator<(Data const other) const {
    return r - l < other.r - other.l;
  }
};

template <class T>
struct LazySegTree
{
    int size = 1, n;
    vector<pair<T, int>> segtree;
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
        segtree[x].f.f += segtree[x].s;
        if (l < r)
        {
            segtree[2 * x + 1].s += segtree[x].s;
            segtree[2 * x + 2].s += segtree[x].s;
        }
        segtree[x].s = 0;
    }

    void update(int x, int l, int r, int lx, int rx, int val)
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

    void update(int lx, int rx, int val)
    {
        update(0, 0, size - 1, lx, rx, val);
    }

    T query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            return def1;
        }
        propagate(x, l, r);
        if (lx <= l && r <= rx)
        {
            return segtree[x].f;
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

long long min_leftover(int N, std::vector<int> A) {
  n = N;
  vec = A;
  
  int id = min_element(all(vec)) - vec.begin();
  int v = vec[id];
  int mi = 1e9+10;
  frange(i, id) {
    mi = min(mi, vec[i]);
    vec[i] -= mi - v;
  }
  mi = 1e9+10;
  for(int i=n-1; i>id; i--) {
    mi = min(mi, vec[i]);
    vec[i] -= mi - v;
  }

  v = vec[0];
  frange(i, n) vec[i] -= v;

  priority_queue<Data> pq;

  id = 0;
  LazySegTree<pii> segtree;
  segtree.init(n, mp(1e9+5, 0));
  lli tot = 0;
  forr(i, 0, n) {
    if(vec[i] == 0) {
      if(id <= i-1) {
        Data tmp;
        tmp.l = id;
        tmp.r = i-1;
        pq.push(tmp);
      }
      id = i+1;
      
    }
    tot += vec[i];
    segtree.set(i, mp(vec[i], i));
  }
  segtree.build();

  while(pq.size() && v > 0) {
    auto p = pq.top();
    pq.pop();
    pii v1 = segtree.query(p.l, p.r);
    tot -= lli(p.r-p.l+1) * min(v, v1.f);
    v -= v1.f;
    if(p.l < v1.s) {
      Data tmp;
      tmp.l = p.l;
      tmp.r = v1.s-1;
      pq.push(tmp);
    }
    if(p.r > v1.s) {
      Data tmp;
      tmp.l = v1.s + 1;
      tmp.r = p.r;
      pq.push(tmp);
    }
    segtree.update(p.l, p.r, -v1.f);
  }

  return tot;


}
