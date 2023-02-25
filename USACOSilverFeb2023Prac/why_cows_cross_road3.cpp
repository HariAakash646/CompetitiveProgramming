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
#define mp make_pair
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

int n, k, r;
vvi grid;
vvi vis;
set<pair<pii, pii>> road;

void dfs(int i, int j, int d) {
   vis[i][j] = d;
   if(i < n-1 && !vis[i+1][j] && road.find(mp(mp(i, j), mp(i+1, j))) == road.end()) {
       dfs(i + 1, j, d);
   }
   if(j < n-1 && !vis[i][j+1] && road.find(mp(mp(i, j), mp(i, j+1))) == road.end()) {
       dfs(i, j+1, d);
   }
   if(i > 0 && !vis[i-1][j] && road.find(mp(mp(i, j), mp(i-1, j))) == road.end()) {
       dfs(i - 1, j, d);
   }
   if(j > 0 && !vis[i][j-1] && road.find(mp(mp(i, j), mp(i, j-1))) == road.end()) {
       dfs(i, j-1, d);
   }
}

int main() {
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    scd(n); scd(k); scd(r);
    frange(i, r) {
        int r, c, r1, c1;
        scd(r); scd(c); scd(r1); scd(c1);
        r--;
        c--;
        r1--;
        c1--;
        road.insert(mp(mp(r, c), mp(r1, c1)));
        road.insert(mp(mp(r1, c1), mp(r, c)));
    }
    
    vii cows(k);
    frange(i, k) {
        scd(cows[i].f);
        scd(cows[i].s);
        cows[i].f--;
        cows[i].s--;
    }
    vis = vector<vi>(n, vi(n));
    int id = 1;
    frange(i, n) {
        frange(j, n) {
            if(!vis[i][j]) {
                dfs(i, j, id);
                id++;
            }
        }
    }
    vi vec(id, 0);
    for(auto p : cows) {
        vec[vis[p.f][p.s]]++;
    }
    
    int tot = 0;
    for(auto e : vec) {
        k -= e;
        tot += e * k;
    }
    printf("%d", tot);
}
