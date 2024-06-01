    #include "fish.h"
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
     
    long long max_weights(int N, int M, std::vector<int> X, std::vector<int> Y,
                          std::vector<int> W) {
        n = N;
        m = M;
        vector<vll> grid(n, vll(n+1));
        frange(i, m) {
            grid[X[i]][Y[i]+1] = W[i];
        }
     
        vector<vll> dp1(n, vll(n+1)), dp2(n, vll(n+1));
        forr(i, 1, n+1) {
            dp2[0][i] = grid[0][i];
            dp2[0][i] += dp2[0][i-1];
        }
     
        forr(i, 1, n) {
            lli ma = 0;
            frange(j, n+1) ma = max(ma, dp1[i-1][j]);
            deque<lli> dq;
            lli tot = 0;
            frange(j, n+1) {
                
                tot += grid[i][j];
                lli v = dp2[i-1][j] - tot;
                while(dq.size() && dq.back() <= v) dq.pop_back();
                dq.pb(v);
                dp2[i][j] = dq.front() + tot; 
                
                dp2[i][j] = max(dp2[i][j], ma + tot);
                
            }
            tot = 0;
            dq = {};
            for(int j=n; j>=0; j--) {
                dp1[i][j] = dp2[i-1][j];
                if(dq.size()) {
                    dp1[i][j] = max(dp1[i][j], dq.front() + tot);
                }
                lli v = dp1[i-1][j] - tot;
                while(dq.size() && dq.back() <= v) dq.pop_back();
                dq.pb(v);
                tot += grid[i][j];
            }
        }   
        return *max_element(all(dp1[n-1]));
    }