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
    vector<map<int, lli>> grid(n);
    frange(i, m) {
        grid[X[i]][Y[i]+1] = W[i];
    }
    frange(i, n) grid[i][0] = grid[i][2e9] = 0;

    vector<map<int, lli>> dp1(n), dp2(n);
    dp1[0][0] = 0;
    dp1[0][2e9] = 0;
    for(auto p : grid[0]) {
        dp2[0][p.f] = p.s;
        auto it = dp2[0].find(p.f);
        if(it != dp2[0].begin())
            dp2[0][p.f] += (*prev(it)).s;
    }

    forr(i, 1, n) {
        lli ma = 0;
        for(auto p : dp1[i-1]) ma = max(ma, p.s);
        deque<lli> dq;
        lli tot = 0;
        for(auto p : grid[i]) {
            
            tot += p.s;
            auto it = dp2[i-1].lower_bound(p.f);
            lli v2 = 2e9+1;
            auto it2 = grid[i].upper_bound(p.f);
            if(it2 != grid[i].end()) v2 = (*it2).f;

            while(it != dp2[i-1].end() && (*it).f < v2) {
                lli v = (*it).s - tot;
                while(dq.size() && dq.back() <= v) dq.pop_back();
                dq.pb(v);
                it++;
            }
            if(dq.size())
                dp2[i][p.s] = dq.front() + tot; 
            
            dp2[i][p.s] = max(dp2[i][p.s], ma + tot);
            
        }
        tot = 0;
        dq = {};
        auto it = grid[i].end();
        while(it != grid[i].begin()) {
            it--;
            auto p= *it;
            dp1[i][p.f] = 0;
            auto it2 = dp2[i-1].upper_bound(p.f);
            if(it2 != dp2[i-1].begin()) {
                it2--;
                dp1[i][p.f] = (*it2).s;
            }
            // printf("%d %d\n", i, p.f);
            if(dq.size()) {
                dp1[i][p.f] = max(dp1[i][p.f], dq.front() + tot);
                // printf("%d %d %lld\n", i, p.f, dq.front() + tot);
            }
            it2 = dp1[i-1].lower_bound(p.f);
            lli v2 = 2e9+1;
            auto it3 = grid[i].upper_bound(p.f);
            if(it3 != grid[i].end()) v2 = (*it3).f;
            while(it2 != dp1[i-1].end() && (*it2).f < v2) {
                lli v = (*it2).s - tot;
                while(dq.size() && dq.back() <= v) dq.pop_back();
                dq.pb(v);
                it2++;
            }
            
            tot += p.s;
        }
    }   
    lli ma = 0;
    for(auto p : dp1[n-1]) ma = max(ma, p.s);
    return ma;
}
