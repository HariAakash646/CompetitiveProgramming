#include "archaeologist.h"
#include <utility>
#include <vector>
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


void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

vvi graph;
vi dp;
void dfs(int x, int p) {
    int c = 0;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
            dp[x] += dp[e];
            c++;
        }
    }
    if(c == 0) dp[x]++;
}

void archaeologist(int n, int k, int l, std::vector<int> map, int lightlevel, std::vector<int> paths) {
    
    graph = vvi(n);
    forr(i, 1, n) {
        int p = map[i];
        graph[i].pb(p);
        graph[p].pb(i);
    }
    dp = vi(n);
    dfs(0, -1);
    if(l == 1) {while(paths.size()){int v;
            frange(i, paths.size()) {
                if(!paths[i]) {
                    v = i;
                    break;
                }
            }
            pair<int, vi> out = take_path(v);
            paths = out.s;
            set_light(1);    }}
    else if(l == n) {
        while(paths.size()) {
            int v;
            frange(i, paths.size()) {
                if(paths[i] != 1) {
                    v = i;
                    break;
                }
            }
            pair<int, vi> out = take_path(v);
            int e = out.f;
            if(paths[v] == 0) set_light(dp[e]);
            else set_light(paths[v]-1);
            paths = out.s;
        }
    }
    else {
        
        while(paths.size()) {
            int v=0;
            if(paths[0] > paths[1] && paths[0] - paths[1] == 2) {
                v = 1;
            }
            else if(paths[1] - paths[0] == 1) v = 1;
            else v = 0;
            pair<int, vi> out = take_path(v);
            set_light((paths[v] + 2) % 3)
            paths = out.s;

        }
    }
    
}