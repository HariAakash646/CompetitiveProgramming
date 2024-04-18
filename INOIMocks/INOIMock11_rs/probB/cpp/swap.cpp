#include "swap.h"
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

int n, m;

vector<vi> graph;
vi depth;
vvi lift;
vvi liftv;
vb swa;
vi deg;

vi disset;

int findf(int x) {
  if(disset[x] == x) return x;
  disset[x] = findf(disset[x]);
  return disset[x];
}

void unionf(int x, int y, int id, int w) {
  int x1 = x;
  int y1 = y;
  deg[x1]++;
  deg[y1]++;
  x = findf(x);
  y = findf(y);
  if(x == y) {
    disset[x] = id;
    lift[0][x] = id;
    liftv[0][y] = w;
    graph[id].pb(y);
    swa[id] = true;
    return;
  }
  disset[x] = id;
  disset[y] = id;
  lift[0][x] = id;
  lift[0][y] = id;
  liftv[0][x] = w;
  liftv[0][y] = w;
  graph[id].pb(x);
  graph[id].pb(y);
  if(swa[x] || swa[y] || deg[x1] >= 3 || deg[y1] >= 3) swa[id] = true;
}

void dfs(int x, int p, int d) {
  depth[x] = d;
  for(auto e : graph[x]) {
    if(e != p) {
      dfs(e, x, d+1);
    }
  }
}

pii binlift(int x, int c) {
  int ma = 0;
  frange(i, 20) {
    if(c & (1<<i)) {
      ma = max(ma, liftv[i][x]);
      x = lift[i][x];
    }
  }  
  return mp(x, ma);
}

pii lca(int u, int v) {
  if(depth[u] > depth[v]) swap(u, v);
  pii p = binlift(v, depth[v] - depth[u]);
  v = p.f;
  int ma = p.s;
  if(u == v) {
    return mp(u, ma);
  }

  for(int i=19; i>=0; i--) {
    int ut = lift[i][u];
    int vt = lift[i][v];
    if(ut != vt || !swa[ut] && ut != -1 && vt != -1) {
      ma = max(ma, liftv[i][u]);
      ma = max(ma, liftv[i][v]);
      // printf("%d %d\n", ut, vt);
      u = ut;
      v = vt;
    }
  }
  ma = max(ma, liftv[0][u]);
  ma = max(ma, liftv[0][v]);
  int l = lift[0][u];
  if(swa[l])
    return mp(l, ma);
  else return mp(l, -1);
}

void init(int N, int M,
          std::vector<int> U, std::vector<int> V, std::vector<int> W) {
    n = N;
    m = M;
    graph = vector<vi>(n+m);

    vector<pair<int, pii>> edg;

    frange(i, m) {
      edg.pb(mp(W[i], mp(U[i], V[i])));
      // graph[U[i]].pb(mp(V[i], W[i]));
      // graph[V[i]].pb(mp(U[i], W[i]));
    }

    sort(all(edg));

    disset = vi(n+m);

    frange(i, n+m) disset[i] = i;

    depth = vi(n+m);
    lift = vvi(20, vi(n+m, -1));
    liftv = vvi(20, vi(n+m, 0));
    swa = vb(n+m);
    deg = vi(n+m);

    frange(i, m) {
      auto p = edg[i];
      unionf(p.s.f, p.s.s, n+i, p.f);
    }
    dfs(n+m-1, -1, 0);

    forr(i, 1, 20) {
      frange(j, n+m) {
        if(lift[i-1][j] == -1) {
          lift[i][j] = -1;
          liftv[i][j] = liftv[i-1][j];
          continue;
        }
        lift[i][j] = lift[i-1][lift[i-1][j]];
        liftv[i][j] = max(liftv[i-1][j], liftv[i-1][lift[i-1][j]]);
      }
    }
}

int getMinimumFuelCapacity(int x, int y) {
  int ma = lca(x, y).s;
  // printf("%d ", lca(x, y).f);

  return ma;

}
