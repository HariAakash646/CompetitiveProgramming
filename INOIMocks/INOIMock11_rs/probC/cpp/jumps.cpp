#include "jumps.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
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
typedef multiset<int> mseti;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int randNo(int lower_limit, int upper_limit){
//     if(upper_limit == lower_limit) return upper_limit;
//     return lower_limit + rng()%(upper_limit-lower_limit);
// }

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
      if(lx > rx) return def;
        return query(0, 0, size - 1, lx, rx);
    }
};


vvi graph;
int n;
vvi lifti, lifta, rgt, lft;
vii mi, ma;
vi hgt;
SegTree<pair<int, int>> tree;

int lift(int x, int h, int pos, int d) {
  int c = 0;
  for(int i=19; i>=0; i--) {
    int xt1 = lifta[i][x];
    int xt2 = lifti[i][x];
    if(hgt[xt2] < h && hgt[xt1] < h && xt1 < pos && xt2 < pos) {
      x = xt1;
      c+=(1<<i);
    }
  }

  for(int i=19; i>=0; i--) {
    int xt = rgt[i][x];
    if(hgt[xt] < h && xt < pos) {
      x = xt;
      c += (1<<i);
    }
  }
  if(pos <= rgt[0][x] && rgt[0][x] <= d) return c + 1;
  else return -1;
}

void init(int N, std::vector<int> h) {
  n = N;
  graph = vvi(n);
  hgt = h;
  deque<int> dq;
  mi = vii(n, mp(2e9, -1));
  ma = vii(n, mp(-1, -1));
  lft = vvi(20, vi(n, -1));
  frange(i, n) {
    while(dq.size() && h[i] >= h[dq.back()]) dq.pop_back();
    if(dq.size()) {
      mi[i] = mp(h[dq.back()], dq.back());
      ma[i] = mp(h[dq.back()], dq.back());
      lft[0][i] = dq.back();
    }
    else lft[0][i] = -1;
    dq.pb(i);
  }

  dq = {};

  rgt = vvi(20, vi(n, -1));

  for(int i=n-1; i>=0; i--) {
    while(dq.size() && h[i] >= h[dq.back()]) dq.pop_back();
    if(dq.size()) {
      pii p = mp(h[dq.back()], dq.back());
      rgt[0][i] = p.s;
      if(p > ma[i]) ma[i] = p;
      if(p < mi[i]) mi[i] = p;
    }
    else rgt[0][i] = -1;
    dq.pb(i);
  }

  
  tree.init(n, mp(0, -1));

  frange(i, n) tree.set(i, mp(h[i], i));

  tree.build();

  lifti = lifta = vvi(20, vi(n, -1));

  frange(i, n) {
    if(mi[i].s != -1) lifti[0][i] = mi[i].s;
    else lifti[0][i] = -1;
    if(ma[i].s != -1) lifta[0][i] = ma[i].s;
    else lifta[0][i] = -1;
  }

  forr(i, 1, 20) {
    frange(j, n) {
        if(lifti[i-1][j] != -1)
            lifti[i][j] = lifti[i-1][lifti[i-1][j]];
        if(lifta[i-1][j] != -1)
            lifta[i][j] = lifta[i-1][lifta[i-1][j]];
        if(rgt[i-1][j] != -1)
            rgt[i][j] = rgt[i-1][rgt[i-1][j]];
        if(lft[i-1][j] != -1) 
            lft[i][j] = lft[i-1][lft[i-1][j]];
    }
  }

}

int minimum_jumps(int a, int b, int c, int d) {

  pii p = tree.query(b+1, c-1);
  if(hgt[b] > p.f) {
    if(rgt[0][b] != -1 && rgt[0][b] <= d) return 1;
    else return -1;
  }

  if(rgt[0][p.s] > d) return -1;

  int l = lft[0][p.s];
  if(l >= a && rgt[0][l] != -1 && rgt[0][l] <= d) {
    return 1;
  }

  l = tree.query(max(a, l+1), b).s;
  int ct = 0;
  for(int i=19; i>=0; i--) {
    int lt = lifta[i][l];
    if(lt >= 0 && hgt[lt] <= hgt[p.s]) {
        l = lt;
        ct += (1<<i);
    }
  }

  if(l == p.s) {
    return ct+1;
  }

  if(lft[0][l] >= 0 && rgt[0][lft[0][l]] <= d && rgt[0][lft[0][l]] != -1) {
    return ct + 2;
  }

  for(int i=19; i>=0; i--) {
    int lt = rgt[i][l];
    if(lt != -1 && lt < c) {
        l = lt;
        ct += (1<<i);
    }
  }

  if(c <= rgt[0][l] && rgt[0][l] <= d) return ct+1;
  else return -1;
  
  
  
}