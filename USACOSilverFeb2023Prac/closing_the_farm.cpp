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

vvi graph;
vb vis;

void dfs(int n) {
    vis[n] = true;
    for(auto e : graph[n]) {
        if(!vis[e]) {
            dfs(e);
        }
    }
}

int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int n, m;
    scd(n); scd(m);
    graph = vvi(n+1);
    frange(i,m) {
        int a, b;
        scd(a); scd(b);
        graph[a].pb(b); graph[b].pb(a);
    }
    vis = vb(n+1);
    int c = 0;
    forr(i, 1, n+1) {
        if(!vis[i]) {
            c++;
            dfs(i);
        }
    }
    if(c <= 1) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    seti rem;
    frange(_, n-1) {
        int a;
        scd(a);
        
        vis = vb(n+1, false);
        rem.insert(a);
        graph[a] = {};
        int c = 0;
        forr(i, 1, n+1) {
            if(!vis[i] && rem.find(i) == rem.end()) {
                c++;
                dfs(i);
            }
        }
        if(c <= 1) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
        
    }
}
