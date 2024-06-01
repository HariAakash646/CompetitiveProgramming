#include "purwokerto.h"
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

const lli mod = 1e9 + 7;

int n, m;

std::pair<long long, int> purwokerto(int N, int M, std::vector<int> T) {
  n = N;
  m = M;

  if(n > 11 || lli(m) * lli(1LL<<n) > 1e7) {
    seti emp, full;
    frange(i, n) emp.insert(i);
    lli tot = 0;
    frange(i, m) {
      if(T[i]) {
        if(full.size()) {
          tot += *prev(full.end()) + 1;
          emp.insert(*prev(full.end()));
          full.erase(prev(full.end()));

        }
      }
      else {
        if(emp.size()) {
          full.insert(*prev(emp.end()));
          emp.erase(prev(emp.end()));
        }
      }
    }
    return mp(tot, 1LL);
  }

  vector<vector<pair<lli, lli>>> dp(m+1, vector<pair<lli, lli>>(1<<n, mp(-1e16, 0)));

  dp[0][0] = mp(0, 1);

  forr(i, 0, m) {
    frange(j, 1<<n) {
      if(T[i]) {
        frange(k, n) {
          if(j & (1<<k)) {
            lli v = dp[i][j].f + k+1;
            if(dp[i+1][j^(1<<k)].f == v) {
              dp[i+1][j^(1<<k)].s += dp[i][j].s;
              dp[i+1][j^(1<<k)].s %= mod;
            }
            else if(v > dp[i+1][j^(1<<k)].f) {
              dp[i+1][j^(1<<k)] = mp(v, dp[i][j].s);
            }
          }
          
        }
        lli v = dp[i][j].f;
        if(dp[i+1][j].f == v) {
          dp[i+1][j].s += dp[i][j].s;
          dp[i+1][j].s %= mod;
        }
        else if(v > dp[i+1][j].f) {
          dp[i+1][j] = mp(v, dp[i][j].s);
        }
      }
      else {
        frange(k, n) {
          
          if(!(j&(1<<k))) {
            lli v = dp[i][j].f;
            if(dp[i+1][j^(1<<k)].f == v) {
              dp[i+1][j^(1<<k)].s += dp[i][j].s;
              dp[i+1][j^(1<<k)].s %= mod;
            }
            else if(v > dp[i+1][j^(1<<k)].f) {
              dp[i+1][j^(1<<k)] = mp(v, dp[i][j].s);
            }
          }
        }
        lli v = dp[i][j].f;
        if(dp[i+1][j].f == v) {
          dp[i+1][j].s += dp[i][j].s;
          dp[i+1][j].s %= mod;
        }
        else if(v > dp[i+1][j].f) {
          dp[i+1][j] = mp(v, dp[i][j].s);
        }
      }
    }
  }


  return dp[m][0];
}
