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
    freopen("input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

vvi graph;
vi out;
vi vec;
vector<mpii> val;

int dfs(int x, int par) {
    int ma = 1;
    val[x][vec[x]] = 1;
    out[x] = vec[x];
    for(auto e : graph[x]) {
        if(e != par) {
            int v = dfs(e, x);
            if(v > ma) {
                ma = v;
                out[x] = out[e];
            }
            else if(v == ma) {
                out[x] += out[e];
            }
            if(val[x].size() < val[e].size()) swap(val[x], val[e]);
            for(auto p : val[e]) {
                val[x][p.f] += p.f * p.s;
                if(p.s == ma) continue;
                if(val[x][p.f]/p.f >= ma) {
                    ma = val[x][p.f];
                    out[x] = val[x][p.f];
                }
                else if(val[x][p.f] == ma) {
                    out[x] += p.f;
                }
            }
        }
    }
    return ma;
} 

int main() {
    usaco();
    int n;
    scd(n);
    vec = vi(n+1);
    forr(i, 1, n+1) scd(vec[i]);
    graph = vvi(n+1);
    forr(i, 1, n+1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    val = vector<mpii>(n+1);
    out = vi(n+1);
    dfs(1, 0);
    forr(i, 1, n+1) printf("%d ", out[i]);
}