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

int n, k;
vvi graph;
vi depth;

void dfs(int x, int p, int d) {
    depth[x] = d;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x, d+1);
        }
    }
}

lli tot = 0;

map<int, lli> dfs2(int x, int p) {
    map<int, lli> out;
    out[depth[x]] = 1;

    for(auto e : graph[x]) {
        if(e != p) {
            map<int, lli> mv = dfs2(e, x);
            if(mv.size() > out.size()) swap(mv, out);

            for(auto pi : mv) {
                auto it = out.find(k-(pi.f - depth[x]) + depth[x]);
                if(it != out.end()) {
                    tot += (*it).s * pi.s;
                }
            }
            for(auto pi : mv) {
                out[pi.f] += pi.s;
            }
        }
    }
    return out;
}

int main() {
    // usaco();
    
    scd(n);
    scd(k);

    graph = vvi(n+1);
    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    depth = vi(n+1);
    dfs(1, 0, 0);
    dfs2(1, 0);

    printf("%lld", tot);
}