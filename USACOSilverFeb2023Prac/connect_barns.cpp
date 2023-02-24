// TLE for higher onstraints. Correct appoach?
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define pb push_back
#define f first
#define s second
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

lli inf = 1e15;

int n, m;
vvi graph;
vb vis;
seti con;

void dfs(int n) {
   vis[n] = true;
   con.insert(n);
   for(auto e : graph[n]) {
       if(!vis[e]) {
           dfs(e);
       }
   }
}

int main() {
    int t;
    scd(t);
    frange(_, t) {
        scd(n); scd(m);
        graph = vvi(n+1);
        vis = vb(n+1);
        frange(i, m) {
            int a, b;
            scd(a); scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }
        vector<seti> comps;
        seti st, en = {};
        int c = 0;
        forr(i, 1, n+1) {
            if(!vis[i]) {
                con = {};
                dfs(i);
                if(con.find(1) != con.end()) {
                    st = con;
                }
                else if(con.find(n) != con.end()) {
                    en = con;
                }
                else {
                    comps.pb(con);
                    c++;
                }
            }
        }
        if(en.empty()) {
            printf("0\n");
            continue;
        }
        vector<lli> dist1(c, inf);
        frange(i, c) {
            auto e = comps[i];
            for(auto l : st) {
                auto itr = e.lower_bound(l);
                dist1[i] = min(dist1[i], lli(l - *itr) * lli(l - *itr));
                itr--;
                dist1[i] = min(dist1[i], lli(l - *itr) * lli(l - *itr));
            }
        }
        vector<lli> distn(c, inf);
        frange(i, c) {
            auto e = comps[i];
            for(auto l : en) {
                auto itr = e.lower_bound(l);
                distn[i] = min(distn[i], lli(l - *itr) * lli(l - *itr));
                itr--;
                distn[i] = min(distn[i], lli(l - *itr) * lli(l - *itr));
            }
        }
        lli out = inf;
        for(auto l : st) {
            auto itr = en.lower_bound(l);
            out = min(out, lli(l - *itr) * lli(l - *itr));
            itr--;
            out = min(out, lli(l - *itr) * lli(l - *itr));
        }
        
        frange(i, c) {
            out = min(out, dist1[i] + distn[i]);
        }
        printf("%lld\n", out);
    }
    
}
