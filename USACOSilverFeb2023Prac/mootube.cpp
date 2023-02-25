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

int n, q;
vector<vii> graph;
int tot;

void dfs(int x, int r, int par) {
    
    for(auto e : graph[x]) {
        if(e.f != par && e.s >= r) {
            dfs(e.f, r, x);
            tot++;
        }
    }
}

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    scd(n); scd(q);
    graph = vector<vii>(n+1);
    frange(i, n-1) {
        int a, b, r;
        scd(a); scd(b); scd(r);
        graph[a].pb({b, r});
        graph[b].pb({a, r});
    }
    
    frange(_, q) {
        int k, v;
        scd(k); scd(v);
        tot = 0;
        dfs(v, k, 0);
        printf("%d\n", tot);
    }
    
}
