#include "game.h"
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

vvi revg, graph;
int n, k;
vi inv, outv;

void init(int N, int K) {
  n = N;
  k = K;
  graph = revg = vvi(n);
  inv = vi(n, -1);
  outv = vi(n, k);
  frange(i, k) inv[i] = outv[i] = i;
  frange(i, k-1) {
    graph[i].pb(i+1);
    revg[i+1].pb(i);
  }
}

void dfsi(int x, int v) {
  if(inv[x] >= v) return;
  inv[x] = v;
  for(auto e : graph[x]) {
    dfsi(e, v);
  }
}

void dfso(int x, int v) {
  if(outv[x] <= v) return;
  outv[x] = v;
  for(auto e : revg[x]) {
    dfso(e, v);
  }
}

int add_teleporter(int u, int v) {
  if(inv[u] >= outv[v]) return 1;
  dfsi(v, inv[u]);
  dfso(u, outv[v]);
  graph[u].pb(v);
  revg[v].pb(u);
  return 0;
}
