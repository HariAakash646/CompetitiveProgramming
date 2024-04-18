#include "joitour.h"
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
vvi graph;
vi type;
lli tot = 0;
lli c0 = 0;
lli c2 = 0;

template <class T>
struct LazySegTree
{
    int size = 1, n;
    vector<vector<T>> seg;
    vector<vector<T>> segc;
    vector<vector<T>> lazy;
    vector<vector<T>> vec;

    void init(int l)
    {
        n = l;

        while (size < n)
            size *= 2;

        seg = vector<vector<T>>(4, vector<T>(2*size));
        lazy = vector<vector<T>>(4, vector<T>(2*size));
        segc = vector<vector<T>>(3, vector<T>(2*size));

        vec = vector<vector<T>>(4, vector<T>(size));
    }

    T operation(T x, T y)
    {
        return x + y; // Any required operation
    }

    void recalculate(int x, int id)
    {
        seg[id][x] = operation(seg[id][2 * x + 1], seg[id][2 * x + 2]);
    }

    void build(int x, int l, int r, int id)
    {
        if (l == r)
        {
            seg[id][x] = vec[id][l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * x + 1, l, mid, id);
        build(2 * x + 2, mid + 1, r, id);
        recalculate(x, id);
    }

    void build(int id)
    {
        build(0, 0, size - 1, id);
    }

    void set(int x, int id, T val)
    {
        vec[id][x] = val;
    }

    void propagate(int x, int l, int r, int id)
    {
        seg[id][x] += segc[1][x] * lazy[id][x];
        if (l < r)
        {
            lazy[id][2 * x + 1] += lazy[id][x];
            lazy[id][2 * x + 2] += lazy[id][x];
        }
        lazy[id][x] = 0;
    }

    void update(int x, int l, int r, int lx, int rx, int id, T val)
    {
        propagate(x, l, r, id);
        if (lx <= l && r <= rx)
        {
            lazy[id][x] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (lx <= mid)
        {
            update(2 * x + 1, l, mid, lx, rx, id, val);
        }
        if (rx >= mid + 1)
        {
            update(2 * x + 2, mid + 1, r, lx, rx, id, val);
        }
        propagate(2 * x + 1, l, mid, id);
        propagate(2 * x + 2, mid + 1, r, id);
        recalculate(x, id);
    }

    void update(int lx, int rx, int id, T val)
    {
        update(0, 0, size - 1, lx, rx, id, val);
    }

    T query(int x, int l, int r, int lx, int rx, int id)
    {
        if (lx > r || rx < l)
        {
            return 0;
        }
        propagate(x, l, r, id);
        if (lx <= l && r <= rx)
        {
            return seg[id][x];
        }
        int mid = (l + r) / 2;
        T v1 = query(2 * x + 1, l, mid, lx, rx, id);
        T v2 = query(2 * x + 2, mid + 1, r, lx, rx, id);
        return operation(v1, v2);
    }

    T query(int lx, int rx, int id)
    {
        return query(0, 0, size - 1, lx, rx, id);
    }

    void recalculatec(int x, int id)
    {
        segc[id][x] = operation(segc[id][2 * x + 1], segc[id][2 * x + 2]);
    }

    void updatec(int x, int l, int r, int idx, int id, T val)
    {   if(id == 1) {
          frange(i, 4) propagate(x, l, r, i);
        }
        if (l == r)
        {
            segc[id][x] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
        {
            updatec(2 * x + 1, l, mid, idx, id, val);
        }
        else
        {
            updatec(2 * x + 2, mid + 1, r, idx, id, val);
        }
        recalculatec(x, id);
    }

    void updatec(int idx, int id, T val)
    {
        updatec(0, 0, size - 1, idx, id, val);
    }

    T queryc(int x, int l, int r, int lx, int rx, int id)
    {
        if (lx > r || rx < l)
        {
            return 0;
        }
        if (lx <= l && r <= rx)
        {
            return segc[id][x];
        }
        int mid = (l + r) / 2;
        T v1 = queryc(2 * x + 1, l, mid, lx, rx, id);
        T v2 = queryc(2 * x + 2, mid + 1, r, lx, rx, id);
        return operation(v1, v2);
    }

    T queryc(int lx, int rx, int id)
    {
        return queryc(0, 0, size - 1, lx, rx, id);
    }
};

pair<lli, lli> dfs(int x, int p) {
  lli ct0 = 0;
  lli ct2 = 0;
  if(type[x] == 0) ct0++;
  if(type[x] == 2) ct2++;

  for(auto e : graph[x]) {
    if(e != p) {
      auto out = dfs(e, x);
      if(type[x] == 1) {
        tot += out.f * (c2 - out.s);
        // tot += out.s * (c0 - out.f);
      }
      ct0 += out.f;
      ct2 += out.s;

    }
  }
  if(type[x] == 1) {
      tot += ct2 * (c0 - ct0);
    }
  return mp(ct0, ct2);
}

LazySegTree<lli> segtree;

void init(int N, std::vector<int> F, std::vector<int> U, std::vector<int> V,
          int Q) {
  n = N;
  graph = vvi(n);
  type = F;

  
  segtree.init(n);

  frange(i, n) {
    if(type[i] == 0)
      segtree.updatec(i, 0, 1);
    else if(type[i] == 1) segtree.updatec(i, 1, 1);
    else segtree.updatec(i, 2, 1);
  }

  frange(i, n) {
    if(type[i] == 1) {
      lli l0 = segtree.queryc(0, i, 0);
      lli r2 = segtree.queryc(i, n-1, 2);
      tot +=  l0 * r2;
      lli r0 = segtree.queryc(i, n-1, 0);
      lli l2 = segtree.queryc(0, i, 2);
      tot += r0 * l2;
      segtree.update(i, i, 0, l0);
      segtree.update(i, i, 1, r0);
      segtree.update(i, i, 2, l2);
      segtree.update(i, i, 3, r2);
    }
  }

  frange(i, n-1) {
    int a = U[i];
    int b = V[i];
    graph[a].pb(b);
    graph[b].pb(a);
  }

}

void change(int X, int Y) {
  int i = X;
  if(type[X] == 1) {
      lli l0 = segtree.queryc(0, i, 0);
      lli r2 = segtree.queryc(i, n-1, 2);
      tot -=  l0 * r2;
      lli r0 = segtree.queryc(i, n-1, 0);
      lli l2 = segtree.queryc(0, i, 2);
      tot -= r0 * l2;
      segtree.update(i, i, 0, -l0);
      segtree.update(i, i, 1, -r0);
      segtree.update(i, i, 2, -l2);
      segtree.update(i, i, 3, -r2);
      segtree.updatec(i, 1, 0);
  }
  else if (type[X] == 0) {
    tot -= segtree.query(i, n-1, 3);
    tot -= segtree.query(0, i, 2);
    segtree.update(i, n-1, 0, -1);
    segtree.update(0, i, 1, -1);
    segtree.updatec(i, 0, 0);
  }
  else {
    tot -= segtree.query(i, n-1, 1);
    tot -= segtree.query(0, i, 0);
    segtree.update(i, n-1, 2, -1);
    segtree.update(0, i, 3, -1);
    segtree.updatec(i, 2, 0);
  }

  type[X] = Y;

  if(type[X] == 1) {
      lli l0 = segtree.queryc(0, i, 0);
      lli r2 = segtree.queryc(i, n-1, 2);
      tot +=  l0 * r2;
      lli r0 = segtree.queryc(i, n-1, 0);
      lli l2 = segtree.queryc(0, i, 2);
      tot += r0 * l2;
      segtree.updatec(i, 1, 1);
      segtree.update(i, i, 0, l0);
      segtree.update(i, i, 1, r0);
      segtree.update(i, i, 2, l2);
      segtree.update(i, i, 3, r2);
  }
  else if (type[X] == 0) {
    tot += segtree.query(i, n-1, 3);
    tot += segtree.query(0, i, 2);
    segtree.update(i, n-1, 0, 1);
    segtree.update(0, i, 1, 1);
    segtree.updatec(i, 0, 1);
  }
  else {
    tot += segtree.query(i, n-1, 1);
    tot += segtree.query(0, i, 0);
    segtree.update(i, n-1, 2, 1);
    segtree.update(0, i, 3, 1);
    segtree.updatec(i, 2, 1);
  }
}

long long num_tours() {
  
  return tot;
}

// int main() {

// }