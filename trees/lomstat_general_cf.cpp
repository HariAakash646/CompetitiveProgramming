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
vll out;
vi col;

pair<mpii, pair<lli, int>> dfs(int x, int p) {
    pair<mpii, pair<lli, int>> dom;
    dom.s.f = col[x];
    dom.s.s = 1;
    dom.f[col[x]]++;
    for(auto e : graph[x]) {
        if(e != p) {
            auto out = dfs(e, x);
            if(dom.f.size() < out.f.size()) swap(dom, out);
            for(auto k : out.f) {
                dom.f[k.f] += k.s;
                int v = dom.f[k.f];
                if(v > dom.s.s) {
                    dom.s.s = v;
                    dom.s.f = k.f;
                }
                else if(v == dom.s.s) {
                    dom.s.f += k.f;
                }
            }
        }
    }
    out[x] = dom.s.f;
    return dom;
}

int main() {
    // usaco();
    int n;
    scd(n);
    graph = vvi(n+1);
    out = vll(n+1);
    col = vi(n+1);

    forr(i, 1, n+1) scd(col[i]);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(1, 0);
    forr(i, 1, n+1) printf("%lld ", out[i]);
}