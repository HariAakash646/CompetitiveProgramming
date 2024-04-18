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

lli mod = 998244353;

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    vll vec(n+1);
    forr(i, 1, n+1) sclld(vec[i]);

    vvi graph(n+1);
    vii edges(m);
    vi deg(n+1);
    frange(i, m) {
        int a, b;

        scd(a);
        scd(b);
        a++;
        b++;
        graph[a].pb(b);
        graph[b].pb(a);
        edges[i] = mp(a, b);
        deg[a]++;
        deg[b]++;
    }

    vvi gr2(n+1);
    for(auto &p : edges) {
        int u = p.f;
        int v = p.s;
        if(mp(deg[u], u) > mp(deg[v], v)) swap(u, v);
        gr2[u].pb(v);
    } 

    vi adj(n+1);
    lli tot = 0;
    for(auto p : edges) {
        for(auto e : gr2[p.f]) {
            adj[e]++;
        }
        for(auto e : gr2[p.s]) {
            if(adj[e]) {
                tot += (vec[p.f] * vec[p.s]) % mod * vec[e];
                tot %= mod;
            }
        }
        for(auto e : gr2[p.f]) adj[e]--;
    }
    printf("%lld", tot);


}