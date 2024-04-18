#include "doll.h"
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

int curr = 0;
vi X, Y;

vii rec(int x, int l, int r) {
  int id = curr + x;
  while(int(X.size()) <= id) {
    X.pb(0);
    Y.pb(0);
  }
  if(l+1 >= r) {
    vii out;
    out.pb(mp(curr + x, 0));
    out.pb(mp(curr + x, 1));
    return out;
  }
  X[x+curr] = -(2*x + curr + 1);
  Y[x+curr] = - (2 * x + 1 + curr + 1);
  int mid = (l+r)/2;
  vii v1 = rec(2*x, l, mid);
  vii v2 = rec(2*x+1, mid+1, r);
  vii out;
  frange(i, (int)v1.size()) {
    out.pb(v1[i]);
    if(i < (int)v2.size())
      out.pb(v2[i]);
  }
  return out;
}

void create_circuit(int m, std::vector<int> A) {
  int n = A.size();
  vi C(m + 1);
  vi cnt(m+1);

  vvi nex(m+1);
  cnt[0]++;
  nex[0].pb(A[0]);
  frange(i, n) {
    cnt[A[i]]++;
    if(i != n-1) {
      nex[A[i]].pb(A[i+1]);
    }
    else nex[A[i]].pb(0);
  }

  
  
  frange(i, m+1) {
    if(cnt[i] == 0) {
      C[i] = 0;
      continue;
    }
    int v = cnt[i];
    // while(v < cnt[i]) v *= 2;
    if(v == 1) {
      C[i] = nex[i][0];
    }
    else {
      curr = X.size() - 1;
      C[i] = -(curr + 2);
      vii out = rec(1, 0, v-1);
      v = out.size();
      frange(j, v - cnt[i]) {
        pii p = out[j];
        if(p.s == 0) {
          X[p.f] = C[i]; 
        }
        else {
          Y[p.f] = C[i];
        }
      }
      frange(j, cnt[i]) {
        pii p = out[j+(v-cnt[i])];
        if(p.s == 0) {
          X[p.f] = nex[i][j];
        }
        else {
          Y[p.f] = nex[i][j];
        }
      }
    }
  }
  // frange(i, m+1) {
  //   printf("%d\n", C[i]);
  // }
  // frange(j, (int)X.size()) printf("%d %d\n", X[j], Y[j]);
  answer(C, X, Y);
}
