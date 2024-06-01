#include "secret.h"
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
        return mp(min(x.f, y.f), max(x.s, y.s));
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

int n, m;
SegTree<pii> tree;
vll pref;
vi vec;

void init(int N, int M, std::vector<int> A) {
  n = N;
  m = M;
  vec = A;
  // tree.init(n, mp(1e9+5, -1));
  // pref = vll(n+1);
  // frange(i, n-1) {
  //   // tree.set(i, mp(min(A[i], A[i+1]), max(A[i], A[i+1])-1));
  //   lli v = min(max(A[i], A[i+1]) - min(A[i], A[i+1]), m-max(A[i], A[i+1]) + min(A[i], A[i+1]));
  //   pref[i+1] = pref[i] + v;
  // }
  // tree.build();
  return;
}

seti act;

void toggle(int R) {
  if(act.find(R) == act.end())
  act.insert(R);
  else act.erase(R);
  return;
}

long long query(int S, int T) {
  // pii p = tree.query(S, T-1);
  // auto it = act.lower_bound(p.f);
  // if(it != act.end()) {
  //   if(*it <= p.s) return -1;
  // }
  lli tot = 0;
  forr(i, S, T) {
    int v1 = min(vec[i], vec[i+1]);
    int v2 = max(vec[i], vec[i+1]);
    auto it = act.lower_bound(v1);
    lli mi = 1e15;
    if(it == act.end() || (*it >= v2)) {
      mi = v2 - v1;
    }
    if(act.size() == 0 || (*prev(act.end()) < v2 && *act.begin() >= v1)) {
      mi = min(mi, lli(m-v2 + v1));
    }
    if(mi==1e15) return -1;
    tot += mi;
  }
  return tot;
}
