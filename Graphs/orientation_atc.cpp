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

vvi graph;
vi vec;
vii out;

void dfs(int x, int d, int p, int v) {
    vis[x] = true;
    for(auto e : graph[x]) {
        if(e != p && vec[e] == d) {
            out.pb({x, e});
            if(e != v) dfs(e, d, x, v);
            break;
        }
    }
}

int main() {
    int n, m;
    scd(n);
    scd(m);
    graph = vvi(n+1);
    vii edges(m);
    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
        edges[i] = {a, b};
    }

    vec = vi(n+1);
    forr(i,1, n+1) scd(vec[i]);

    forr(i, 1, n+1) {
        forr(x, 1, n+1) {
            if(vec[x] == i) {
                for(auto e : graph[x]) {
                    if(vec[e] > vec[x]) out.pb({e, x});
                }
                if(!vis[x]) {
                    dfs(x, i, 0, x);
                }
            }
        }
    }
    for(auto p : edges) {
        for(auto x : out) {
            if(p.f == x.f && p.s == x.s) printf("->\n");
            if(p.f == x.s && p.s == x.f) printf("<-\n");
        }
    }
}