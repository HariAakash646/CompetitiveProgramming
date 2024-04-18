#include "race.h"
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
int n, k;
int out = 1e9;
vi sze;
vb vis;

int get_size(int x, int p=-1) {
  sze[x] = 1;
  for(auto e : graph[x]) {
    if(e.f != p && !vis[e.f]) {
      sze[x] += get_size(e.f, x);
    }
  }
  return sze[x];
}

int get_cent(int x, int subsz, int p=-1) {
  for(auto e : graph[x]) {
    if(e.f != p && !vis[e.f] && 2*sze[e.f] > subsz) {
      return get_cent(e.f, subsz, x);
    }
  }
  return x;
}

map<lli, int> dist;

void dist_dfs(int x, int p, lli d, int d1) {
  if(dist.find(d) == dist.end()) dist[d] = d1;
  else dist[d] = min(dist[d], d1);
  for(auto e : graph[x]) {
    if(e.f != p && !vis[e.f]) {
      dist_dfs(e.f, x, d+e.s, d1+1);
    }
  }
}

void decomp(int x) {
  int sz = get_size(x);
  x = get_cent(x, sz);
  vis[x] = true;
  map<lli, int> curr;
  curr[0] = 0;

  for(auto e : graph[x]) {
    if(!vis[e.f]) {
      dist = {};
      dist_dfs(e.f, x, e.s, 1);
      for(auto p : dist) {
        auto it = curr.find(k-p.f);
        if(it != curr.end()) {
          out = min(out, p.s + (*it).s);
        }
      }
      for(auto p : dist) {
        if(curr.find(p.f) == curr.end()) curr[p.f] = p.s;
        else curr[p.f] = min(curr[p.f], p.s);
      }
    }
  }

  for(auto e : graph[x]) {
    if(!vis[e.f]) decomp(e.f);
  }
}

int best_path(int N, int K, int H[][2], int L[])
{
  n = N;
  k = K;
  graph = vector<vii>(n);

  frange(i, n-1) {
    graph[H[i][0]].pb(mp(H[i][1], L[i]));
    graph[H[i][1]].pb(mp(H[i][0], L[i]));
  }

  vis = vb(n+1);
  sze = vi(n+1);
  
  decomp(0);
  if(out == 1e9) return -1;
  return out;
}

