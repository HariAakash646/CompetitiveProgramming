// #include "jumps.h"
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randNo(int lower_limit, int upper_limit){
    if(upper_limit == lower_limit) return upper_limit;
    return lower_limit + rng()%(upper_limit-lower_limit);
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
      if(lx > rx) return def;
        return query(0, 0, size - 1, lx, rx);
    }
};


vvi graph;
int n;
vvi lifti, lifta, rgt;
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
  frange(i, n) {
    while(dq.size() && h[i] >= h[dq.back()]) dq.pop_back();
    if(dq.size()) {
      mi[i] = mp(h[dq.back()], dq.back());
      ma[i] = mp(h[dq.back()], dq.back());
    }
    dq.pb(i);
  }

  dq = {};

  rgt = vvi(20, vi(n));

  for(int i=n-1; i>=0; i--) {
    while(dq.size() && h[i] >= h[dq.back()]) dq.pop_back();
    if(dq.size()) {
      pii p = mp(h[dq.back()], dq.back());
      rgt[0][i] = p.s;
      if(p > ma[i]) ma[i] = p;
      if(p < mi[i]) mi[i] = p;
    }
    else rgt[0][i] = i;
    dq.pb(i);
  }

  
  tree.init(n, mp(0, -1));

  frange(i, n) tree.set(i, mp(h[i], i));

  tree.build();

  lifti = lifta = vvi(20, vi(n));

  frange(i, n) {
    if(mi[i].s != -1) lifti[0][i] = mi[i].s;
    else lifti[0][i] = i;
    if(ma[i].s != -1) lifta[0][i] = ma[i].s;
    else lifta[0][i] = i;
  }

  forr(i, 1, 20) {
    frange(j, n) {
      lifti[i][j] = lifti[i-1][lifti[i-1][j]];
      lifta[i][j] = lifta[i-1][lifta[i-1][j]];
      rgt[i][j] = rgt[i-1][rgt[i-1][j]];
    }
  }

}

int minimum_jumps(int a, int b, int c, int d) {

  pii v = tree.query(c, d);
  
  if(ma[v.s].s < v.s && ma[v.s].s != -1) {
    pii p = tree.query(max(a, ma[v.s].s+1), b);
    if(p.s == -1) return -1;
    int out = lift(p.s, hgt[v.s], c, d);
    int out2 = lift(p.s, hgt[c], c, d);
    if(out == -1)
      return out2;
    else if(out2 == -1) return out;
    else return min(out, out2);
  }
  else if(mi[v.s].s < v.s && mi[v.s].s != -1) {
    pii p = tree.query(max(a, mi[v.s].s+1), b);
    if(p.s == -1) return -1;
    int out = lift(p.s, hgt[v.s], c, d);
    int out2 = lift(p.s, hgt[c], c, d);
    if(out == -1)
      return out2;
    else if(out2 == -1) return out;
    else return min(out, out2);
  }
  else {
    pii p = tree.query(a, b);
    // printf("%d\n", p.s);
    if(p.s == -1) return -1;
    int out = lift(p.s, hgt[v.s], c, d);
    int out2 = lift(p.s, hgt[c], c, d);
    if(out == -1)
      return out2;
    else if(out2 == -1) return out;
    else return min(out, out2);
  }
  
}
void init2(int N, std::vector<int> h) {
  n = N;
  graph = vvi(n);
  deque<int> dq;
  frange(i, n) {
    while(dq.size() && h[i] >= h[dq.back()]) dq.pop_back();
    if(dq.size()) graph[i].pb(dq.back());
    dq.pb(i);
  }
 
  dq = {};
 
  for(int i=n-1; i>=0; i--) {
    while(dq.size() && h[i] >= h[dq.back()]) dq.pop_back();
    if(dq.size()) graph[i].pb(dq.back());
    dq.pb(i);
  }
 
}
 
int minimum_jumps2(int A, int B, int C, int D) {
 
  queue<pii> q;
  forr(i, A, B+1) q.push(mp(i, 0));
  vb vis(n);
 
  while(q.size()) {
    auto p = q.front();
    q.pop();
 
    if(C <= p.f && p.f <= D) return p.s;
    if(vis[p.f]) continue;
    vis[p.f] = true;
 
    for(auto e : graph[p.f]) {
      q.push(mp(e, p.s+1));
    }
  }
 
  return -1;
}

int main() {
  // usaco();
  int t = 1000;
  frange(_, t) {
    int N, Q;
    // assert(2 == scanf("%d %d", &N, &Q));
    N = randNo(2, 20);
    Q = randNo(1, 100);

    vi H(N);
    frange(i, N) H[i] = i+1;

    frange(j, 10*N) {
        int a, b;
        a = randNo(0, N-1);
        b = randNo(0, N-1);
        swap(H[a], H[b]);
    } 
    init(N, H);
    init2(N, H);

    frange(i, Q) {
        int a, b, c, d;
        a = randNo(0, N-2);
        b = randNo(a, N-2);
        c = randNo(b+1, N-1);
        d = randNo(c, N-1);
        // printf("%d %d %d %d\n", a, b, c,d);
        if(minimum_jumps(a, b, c, d) != minimum_jumps2(a, b, c, d)) {
            printf("Test %d: Failure\n", _);
            printf("%d %d\n", N, Q);
            frange(j, N) printf("%d ", H[j]);
            printf("\n");
            printf("%d %d %d %d\n", a, b, c, d);
            printf("Correct: %d\n", minimum_jumps2(a, b, c, d));
            printf("Output: %d\n", minimum_jumps(a, b, c, d));
            return 0;
        }

    }
    printf("Test %d: Success\n", _);
  }
  return 0;
}
