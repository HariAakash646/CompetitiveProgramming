#include "zebra.h"
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

vector<vii> graph;

vi sze;
vi par;
vb vis;

int n;

int get_sze(int x, int p) {
  sze[x] = 1;
  for(auto e : graph[x]) {
    if(e.f != p && !vis[e.f]) {
      sze[x] += get_sze(e.f, x);
    }
  }
  return sze[x];
}

int get_centroid(int x, int p, int sz) {
  for(auto e : graph[x]) {
    if(!vis[e.f] && e.f != p && 2 * sze[e.f] > sz) {
      return get_centroid(e.f, x, sz);
    }
  }
  return x;
}

int decompose(int x, int p) {
  int sz = get_sze(x, 0);
  x = get_centroid(x, 0, sz);
  // printf("%d\n", x);
  vis[x] = true;
  par[x] = p;

  vii adj;
  for(auto e : graph[x]) {
    // printf("%d %d\n", e.f, e.s);
    if(!vis[e.f]) adj.pb(e);
  }

  if(adj.empty()) return x;

  if(adj.size() == 1) {
    int x2 = adj[0].f;
    if(graph[x].size() < graph[x2].size()) swap(x, x2);
    vi vec;
    for(auto e : graph[x]) vec.pb(e.s);
    if(!is_zebra(vec)) return x;
    else return x2; 
  }

  
  vi vec;
  for(auto e : adj) {vec.pb(e.s);}
  // printf("is_zeb: %d\n", is_zebra(vec));
  if(!is_zebra(vec)) return x;

  int lo = 1;
  int hi = (int)adj.size()-1;

  while(lo != hi) {
    vi vec;
    int mid = (lo+hi)/2;
    frange(i, mid+1) vec.pb(adj[i].s);
    if(is_zebra(vec)) hi = mid;
    else lo = mid+1; 
  }
  int nx = -1;
  if(lo > 1) {
    nx = adj[lo].f;
  }
  else {
    bool z1=false, z2=false;
    vi vec;
    if(adj.size() > 2) {
      if(is_zebra({adj[0].s, adj[2].s})) nx = adj[0].f;
      else nx = adj[1].f;
    }
    else {
    for(auto e : graph[adj[0].f]) {
      if(e.f != x) {
        vec.pb(e.s);
      }
    }
    if(vec.size())
      z1 = is_zebra(vec);
    if(z1) {
      nx = adj[0].f;
    }
    else {
      vec = {};
      for(auto e : graph[adj[1].f]) {
        if(e.f != x) {
          vec.pb(e.s);
        }
      }
      if(vec.size()) {
        z2 = is_zebra(vec);
      }
      if(z2) {
        nx = adj[1].f;
      }
      else {
        if(p) {
          int i0, i1;
          vi v0, v1;
          for(auto e : graph[adj[0].f]) {
            if(e.f == x) i0 = e.s;
            else v0.pb(e.s);
          }
          for(auto e : graph[adj[1].f]) {
            if(e.f == x) i1 = e.s;
            else v1.pb(e.s);
          }
          if(v0.size()) {
            v0.pb(i0);
            if(is_zebra(v0)) nx = adj[1].f;
            else nx = adj[0].f;
          }
          else if(v1.size()) {
            v1.pb(i1);
            if(is_zebra(v1)) nx = adj[0].f;
            else nx = adj[1].f;
          }
          else if(is_zebra({p, i0})) return adj[0].f;
          else return adj[1].f;
        }
      }
    }
    }
  }
  

  for(auto e : graph[x]) {
    if(e.f == nx) return decompose(e.f, e.s);
  }
  return 0;
}


int find_root(int N, std::vector<int> U, std::vector<int> V) {
  n = N;
  par = sze = vi(n);
  vis = vb(n);
  graph = vector<vii>(n);
  frange(i, n-1) {
    graph[U[i]].pb(mp(V[i], i));
    graph[V[i]].pb(mp(U[i], i));
  }
  return decompose(0, 0);
}
