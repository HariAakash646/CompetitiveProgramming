#include "aliens.h"
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

long long take_photos(int n, int m, int k, std::vector<int> r, std::vector<int> c) {
   vi val(m);
   seti imp_st;
   vi imp;
   frange(i, n) {
      int id = max(r[i], c[i]);
      imp_st.insert(id);
      // val[id] = max(val[id], id-min(r[i], c[i])+1);
   }
   imp_st.insert(0);
   imp_st.insert(m-1);
   vi id(m);
   for(auto e : imp_st) {
      id[e] = imp.size();
      imp.pb(e);
   }
   frange(i, n) {
      int id = max(r[i], c[i]);
      val[id] = max(val[id], id-min(r[i], c[i])+1);
   }
   vector<vll> dp(imp.size(), vll(k+1, 1e17));
   if(val[0]) {
      forr(i, 1, k+1) dp[0][i] = 1;
   }
   else {
      frange(i, k+1) dp[0][i] = 0;
   }

   forr(i, 1, imp.size()) {
      if(!val[imp[i]]) dp[i][0] = dp[i-1][0];
      // printf("%d\n", val[i]);
      forr(j, 1, k+1) {
         dp[i][j] = dp[i][j-1];
         lli c = (lli)val[imp[i]];
         for(lli x=1; i-x>=0; x++) {
            lli l = imp[i] - imp[i-x];
            if(val[imp[i-x]] && val[imp[i-x]]+l>c) {
               dp[i][j] = min(dp[i][j], 2*c*min(l, c) - min(l, c) * min(l, c) + dp[i-x][j-(c>0)]);
               c = val[imp[i-x]] + l;
            }
            else dp[i][j] = min(dp[i][j], dp[i-x][j-(c>0)] + c*c);
            // dp[i][j] = max(dp[i][j], )
         }
         dp[i][j] = min(dp[i][j], c*c);
         // printf("%lld ", dp[i][j]);
      }
      // printf("\n");
   }

   return dp[imp.size()-1][k];
}
