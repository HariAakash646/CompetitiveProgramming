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
vvi grid;
vector<vb> vis;
vii way;

void dfs(int i, int j, int d) {
   vis[i][j] = true;
   if(i < n-1 && !vis[i+1][j] && abs(grid[i][j] - grid[i+1][j]) <= d) {
       dfs(i + 1, j, d);
   }
   if(j < m-1 && !vis[i][j+1] && abs(grid[i][j] - grid[i][j+1]) <= d) {
       dfs(i, j+1, d);
   }
   if(i > 0 && !vis[i-1][j] && abs(grid[i][j] - grid[i-1][j]) <= d) {
       dfs(i - 1, j, d);
   }
   if(j > 0 && !vis[i][j-1] && abs(grid[i][j] - grid[i][j-1]) <= d) {
       dfs(i, j-1, d);
   }
}

bool check(int d) {
    vis = vector<vb>(n, vb(m+1, false));
    dfs(way[0].f, way[0].s, d);
    for(auto p : way) {
        if(!vis[p.f][p.s]) return false;
    }
    return true;
}

int main() {
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    scd(n); scd(m);
    grid = vvi(n, vi(m));
    frange(i, n) {
        frange(j, m) {
            scd(grid[i][j]);
        }
    }
    
    frange(i, n) {
        frange(j, m) {
            int a;
            scd(a);
            if(a == 1) {
                way.pb({i, j});
            }
        }
    }
    
    int l = 0;
    int h = 1e9;
    while(l != h) {
        int mid = (l + h) / 2;
        if(check(mid)) {
            h = mid;
        }
        else {
            l = mid + 1;
        }
    }
    printf("%d", l);
    
}
