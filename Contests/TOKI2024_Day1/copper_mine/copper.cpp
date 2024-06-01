#include "copper.h"
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

int n, m;
vvi graph;
vvi lift, liftl, liftr, liftlv, liftrv;
vi depth;
vvi pos;

void dfs(int x, int p) {
  lift[0][x] = p;
  depth[x] = depth[p] + 1;
  // printf("%d %d\n", x, p);
  for(auto e : graph[x]) {
    if(e != p) {
      // if(pos[e] > pos[x]) liftl[0][e] = 1;
      // else liftr[0][e] = 1;
      dfs(e, x);
    }
  }
}

int binlift(int x, int c) {
  frange(i, 20) {
    if(c & (1<<i)) {
      x = lift[i][x];
    }
  }
  return x;
}

int lca(int u, int v) {
  if(depth[u] > depth[v]) swap(u, v);
  v = binlift(v, depth[v]-depth[u]);
  if(u==v) return u;

  for(int i=19; i>=0; i--) {
    int ut = lift[i][u];
    int vt = lift[i][v];
    if(ut != vt) {
      u = ut;
      v = vt;
    }
  }
  return lift[0][u];
}

pii binl(int x, int c) {
  int tot = 0;
  frange(i, 20) {
    if(c & (1<<i)) {
      tot += liftlv[i][x];
      x = liftl[i][x];
    }
  }
  return mp(tot, x);
}

pair<int, int> binr(int x, int c) {
  int tot = 0;
  frange(i, 20) {
    if(c & (1<<i)) {
      tot += liftrv[i][x];
      x = liftr[i][x];
      // printf("%d: %d ", i, x);
    }
  }
  return mp(tot, x);
}

long long min_risk(int N, int M, int L, std::vector<int> U, std::vector<int> V,
                   std::vector<int> A, std::vector<int> S) {
  n = N;
  m = M;

  liftlv = liftrv = liftr = liftl = vvi(20, vi(m));
  graph = vvi(n+1);

  frange(i, n-1) {
    graph[U[i]+1].pb(V[i]+1);
    graph[V[i]+1].pb(U[i]+1);
  }

  lift = vvi(20, vi(n+1));
  depth = vi(n+1);
  dfs(1, 0);

  pos = vvi(n+1);
  frange(i, m) {
    pos[A[i]+1].pb(i);
  }

  forr(i, 2, n+1) {
    
    for(auto e : pos[i]) {
      auto it = lower_bound(all(pos[lift[0][i]]), e);
      int c = 0;
      if(it == pos[lift[0][i]].end()) {
        c++;
        it = pos[lift[0][i]].begin();
      }
      liftl[0][e] = *it;
      liftlv[0][e] = c;
    }
  
  
    for(auto e : pos[i]) {
      auto it = lower_bound(all(pos[lift[0][i]]), e);
      int c = 0;
      if(it == pos[lift[0][i]].begin()) {
        c++;
        it = pos[lift[0][i]].end();
      }
      it--;
      liftr[0][e] = *it;
      liftrv[0][e] = c;
    }
    
    
  }


  forr(i, 1, 20) {
    forr(j, 1, n+1) {
      lift[i][j] = lift[i-1][lift[i-1][j]];
    }
    forr(j, 0, m) {
      liftl[i][j] = liftl[i-1][liftl[i-1][j]];
      liftr[i][j] = liftr[i-1][liftr[i-1][j]];
      liftlv[i][j] = liftlv[i-1][j] + liftlv[i-1][liftl[i-1][j]];
      liftrv[i][j] = liftrv[i-1][j] + liftrv[i-1][liftr[i-1][j]];
      
    }
  }
  // printf("%d\n", liftr[0][2]);
  lli tot = 0;
  int l = 1;
  int id = 0;
  forr(i, 0, L) {
    int r = S[i]+1;
    // printf("%d %d ", l, r);
    int lc = lca(l, r);
    pii p = binl(id, depth[l]-depth[lc]);
    int id2 = pos[r].back();
    pii p2 = binr(id2, depth[r]-depth[lc]);
    lli cos = p.f + p2.f + (p.s>p2.s);
    int lo = 0;
    int hi = pos[r].size() - 1;

    while(lo != hi) {
      int mid = (lo+hi)/2;
      int id2 = pos[r][mid];
      pii p2 = binr(id2, depth[r]-depth[lc]);
      lli ct = p.f + p2.f + (p.s>p2.s);
      if(ct <= cos) hi = mid;
      else lo = mid+1;
    }
    id = pos[r][lo];
    tot += cos;
    l = r;
    // printf("%d\n", id);
    // printf("%d ", id);
  }
  return tot;
}
