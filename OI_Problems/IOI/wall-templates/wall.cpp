#include "wall.h"
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

template <class T>
struct LazySegTree {
  int n;
  int size = 1;
  vector<T> vec, segtree;
  vb lazy;

  T def = mp(-1e9, 1e9);

  void init(int l) {
    n = l;
    while(size < n) size *= 2;
    vec = vector<T>(size, def);
    segtree = vector<T>(2*size, def);
    lazy = vector<bool>(2*size, false);
  }

  void set(int x, T v) {
    vec[x] = v;
  }

  T operation(T x, T y) {
    T out;
    out.f = min(x.f, y.f);
    out.s = max(x.s, y.s);
    return out;
  }

  void build(int x, int l, int r) {
    if(l == r) {
      segtree[x] = vec[l];
      return;
    }
    int mid = (l+r)/2;
    build(2*x+1, l, mid);
    build(2*x+2, mid+1, r);
  }

  void build() {
    build(0, 0, size-1);
  }
  void propagate(int x, int l, int r) {
    int v = segtree[x].f;
    segtree[2*x+1].f = max(segtree[2*x+1].f, v);
    segtree[2*x+1].s = max(segtree[2*x+1].s, segtree[2*x+1].f);
    v = segtree[x].s;
    segtree[2*x+1].s = min(segtree[2*x+1].s, v);
    segtree[2*x+1].f = min(segtree[2*x+1].f, segtree[2*x+1].s);
    lazy[2*x+1] = true;

    v = segtree[x].f;
    segtree[2*x+2].f = max(segtree[2*x+2].f, v);
    segtree[2*x+2].s = max(segtree[2*x+2].s, segtree[2*x+2].f);
    v = segtree[x].s;
    segtree[2*x+2].s = min(segtree[2*x+2].s, v);
    segtree[2*x+2].f = min(segtree[2*x+2].f, segtree[2*x+2].s);
    lazy[2*x+2] = true;
  } 

  void update(int x, int l, int r, int lx, int rx, int v, int t) {
    if(l > rx || r < lx) {
      return;
    }
    if(lx <= l && r <= rx) {
      lazy[x] = true;
      if(t == 1) {
        segtree[x].f = max(segtree[x].f, v);
        segtree[x].s = max(segtree[x].s, segtree[x].f);
      }
      else {
        segtree[x].s = min(segtree[x].s, v);
        segtree[x].f = min(segtree[x].f, segtree[x].s);
      }
      return;
    }
    if(lazy[x]) {
      propagate(x, l, r);
      lazy[x] = false;
    }
    
    int mid = (l+r)/2;
    update(2*x+1, l, mid, lx, rx, v, t);
    update(2*x+2, mid+1, r, lx, rx, v, t);
  }


  void update(int lx, int rx, int v, int t) {
    update(0, 0, size-1, lx, rx, v, t);
  }

  T query(int x, int l, int r, int id) {
    if(l == r) {
      return segtree[x];
    }
    if(lazy[x]) {
      propagate(x, l, r);
      lazy[x] = false;
    }
    int mid = (l+r)/2;
    if(id <= mid)
      return query(2*x+1, l, mid,id);
    else
      return query(2*x+2, mid+1, r, id);
  }

  T query(int id) {
    return query(0, 0, size-1, id);
  }
};

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
  
  LazySegTree<pii> seg;
  seg.init(n);
  seg.build();
  // seg.update(0, mp(0, 0));
  seg.update(0, n-1, 0, 1);
  seti add, rem;
  set<pii> act;
  frange(i, k) {
    seg.update(left[i], right[i], height[i], op[i]);
  }
  frange(i, n) {
    pii p = seg.query(i);
    finalHeight[i] = p.f;
  }
  return;
}

