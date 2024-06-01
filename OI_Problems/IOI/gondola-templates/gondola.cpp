#include "gondola.h"
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

int valid(int n, int inputSeq[])
{
  pii mi = mp(2e9, 1e9);
  seti st;
  frange(i, n) {
    mi = min(mi, mp(inputSeq[i], i));
    st.insert(inputSeq[i]);
  }
  if(st.size() != n) return 0;
  if(mi.f > n) return 1;
  int v = mi.f;
  forr(i, mi.s, n) {
    if(inputSeq[i] <= n) {
      if(inputSeq[i] != v) return 0;
    }
    v++;
  }
  forr(i, 0, mi.s) {
    if(inputSeq[i] <= n) {
      if(inputSeq[i] != v) return 0;
    }
    v++;
  }
  return 1;
}

//----------------------

int replacement(int n, int inputSeq[], int replacementSeq[])
{
  pii mi = mp(2e9, 1e9);
  int ma = 0;
  vi pos(3e5+1, -1);
  frange(i, n) {
    mi = min(mi, mp(inputSeq[i], i));
    ma = max(ma, inputSeq[i]);
    pos[inputSeq[i]] = i;
  }
  
  if(mi.f > n) {
    int v = pos[ma]+1;
    pos[ma] = -1;
    forr(i, n+1, ma+1) {
      if(pos[i] == -1) {
        replacementSeq[i-(n+1)] = v;
        v = i;
      }
      else {
        replacementSeq[i-(n+1)] = pos[i]+1;
      }
    }
  }
  else {
    vi val(n);
    int v1 = mi.f;
    frange(i, n) {
      val[i] = ((v1-1) + (i-mi.s) + n) % n + 1; 
      // printf("%d ", val[i]);
    }

    int v = val[pos[ma]];
    pos[ma] = -1;
    forr(i, n+1, ma+1) {
      // printf("%d\n", i);
      if(pos[i] == -1) {
        // printf("%d\n", v);
        replacementSeq[i-(n+1)] = v;
        v = i;
      }
      else {

        replacementSeq[i-(n+1)] = val[pos[i]];
      }
    }

  }
  return ma-n;
}

//----------------------

const lli mod = 1e9 + 9;

lli modexp(lli x, int c) {
  if(c == 0) return 1;
  lli v = modexp(x, c/2);
  v = v*v%mod;
  if(c%2) return v*x%mod;
  else return v;
}

int countReplacement(int n, int inputSeq[])
{
  
  if(!valid(n, inputSeq)) return 0;
  lli out = 1;
  int ma = 0;
  int mi = 2e9;
  int c = n;
  seti st;
  frange(i, n) {mi = min(mi, inputSeq[i]); if(inputSeq[i] > n) st.insert(inputSeq[i]);}
  
  if(mi > n) {
    out = n;
  }
  frange(i, n) {
    if(inputSeq[i] <= n) c--;
  }
  int pre = n;
  for(auto e : st) {
    out = out * modexp(c, e-pre-1) % mod;
    c--;
    pre = e;
  }
  
  return out;
}
