#include "paint.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;

int minimumInstructions(
    int n, int m, int k, vector<int> col,
    vector<int> cnt, vector<std::vector<int>> fav) {

    // vector<vb> favb(m, vb(k));
    if(k <= 1e4) {vector<vector<short>> val(k);
    
        frange(i, fav.size()) {
            for(auto e : fav[i]) {
                val[e].pb(i);
            }
        }
    
    
        vector<vector<short>> dp1(n), dp2(n);
        if(val[col[0]].size() >= 1 && val[col[0]][0] == 0) dp1[0].pb(0);
    
        forr(i, 1, n) {
            int id = 0;
            while(id < val[col[i]].size() && val[col[i]][id] < 0) id++;
            if(id < val[col[i]].size() && val[col[i]][id] == 0) dp1[i].pb(0);
            for(auto e : dp1[i-1]) {
                while(id < val[col[i]].size() && val[col[i]][id] < e+1) id++;
                if(id < val[col[i]].size() && val[col[i]][id] == e+1) dp1[i].pb(e+1);
            }
        }
    
        if(val[col[n-1]].size() && val[col[n-1]].back() == m-1) dp2[n-1].pb(m-1);
    
        for(int i=n-2; i>=0; i--) {
            int id = 0;
            for(auto e : dp2[i+1]) {
                while(id < val[col[i]].size() && val[col[i]][id] < e-1) id++;
                if(id < val[col[i]].size() && val[col[i]][id] == e-1) dp2[i].pb(e-1);
            }
            while(id < val[col[i]].size() && val[col[i]][id] < m-1) id++;
            if(id < val[col[i]].size() && val[col[i]][id] == m-1) dp2[i].pb(m-1);
        }
    
        vb pos(n);
    
        forr(i, m-1, n) {
            int id = 0;
            for(auto e : dp1[i]) {
                while(id < dp2[i-m+1].size() && dp2[i-m+1][id] < e+1) id++;
                if(id < dp2[i-m+1].size() && dp2[i-m+1][id] == e+1) pos[i] = true;
            }
            
            if(dp1[i].size() && dp1[i].back() == m-1) pos[i] = true;
            if(dp2[i-m+1].size() && dp2[i-m+1].front() == 0) pos[i] = true;
        }
    
        vi dp(n, 1e9);
    
        if(pos[m-1]) dp[m-1] = 1;
    
        deque<int> dq;
        dq.pb(m-1);
    
        forr(i, m, n) {
            while(dq.size() && dq.front() < i-m) dq.pop_front();
            if(pos[i]) {
                if(dq.size())
                    dp[i] = min(dp[i], dp[dq.front()]+1);
                while(dq.size() && dp[dq.back()] >= dp[i]) dq.pop_back();
                dq.pb(i);
            }
        }
        if(dp[n-1] >= 1e9) return -1;
        else return dp[n-1];}
    else {vector<vector<int>> val(k);
    
        frange(i, fav.size()) {
            for(auto e : fav[i]) {
                val[e].pb(i);
            }
        }
    
    
        vector<vector<int>> dp1(n), dp2(n);
        if(val[col[0]].size() >= 1 && val[col[0]][0] == 0) dp1[0].pb(0);
    
        forr(i, 1, n) {
            int id = 0;
            while(id < val[col[i]].size() && val[col[i]][id] < 0) id++;
            if(id < val[col[i]].size() && val[col[i]][id] == 0) dp1[i].pb(0);
            for(auto e : dp1[i-1]) {
                while(id < val[col[i]].size() && val[col[i]][id] < e+1) id++;
                if(id < val[col[i]].size() && val[col[i]][id] == e+1) dp1[i].pb(e+1);
            }
        }
    
        if(val[col[n-1]].size() && val[col[n-1]].back() == m-1) dp2[n-1].pb(m-1);
    
        for(int i=n-2; i>=0; i--) {
            int id = 0;
            for(auto e : dp2[i+1]) {
                while(id < val[col[i]].size() && val[col[i]][id] < e-1) id++;
                if(id < val[col[i]].size() && val[col[i]][id] == e-1) dp2[i].pb(e-1);
            }
            while(id < val[col[i]].size() && val[col[i]][id] < m-1) id++;
            if(id < val[col[i]].size() && val[col[i]][id] == m-1) dp2[i].pb(m-1);
        }
    
        vb pos(n);
    
        forr(i, m-1, n) {
            int id = 0;
            for(auto e : dp1[i]) {
                while(id < dp2[i-m+1].size() && dp2[i-m+1][id] < e+1) id++;
                if(id < dp2[i-m+1].size() && dp2[i-m+1][id] == e+1) pos[i] = true;
            }
            
            if(dp1[i].size() && dp1[i].back() == m-1) pos[i] = true;
            if(dp2[i-m+1].size() && dp2[i-m+1].front() == 0) pos[i] = true;
        }
    
        vi dp(n, 1e9);
    
        if(pos[m-1]) dp[m-1] = 1;
    
        deque<int> dq;
        dq.pb(m-1);
    
        forr(i, m, n) {
            while(dq.size() && dq.front() < i-m) dq.pop_front();
            if(pos[i]) {
                if(dq.size())
                    dp[i] = min(dp[i], dp[dq.front()]+1);
                while(dq.size() && dp[dq.back()] >= dp[i]) dq.pop_back();
                dq.pb(i);
            }
        }
        if(dp[n-1] >= 1e9) return -1;
        else return dp[n-1];}
}
