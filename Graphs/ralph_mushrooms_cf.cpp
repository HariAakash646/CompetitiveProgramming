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

vector<vii> graph, gr2;
vi order;
vb vis;

void dfs(int x) {
    vis[x] = true;
    for(auto e : graph[x]) {
        if(!vis[e.f]) dfs(e.f);
    }
    order.pb(x);
}

seti comp;

void dfs2(int x) {
    vis[x] = true;
    for(auto e : gr2[x]) {
        if(!vis[e.f]) dfs2(e.f);
    }
    comp.insert(x);
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    
    vll val;

    val.pb(0);
    
    lli id = 0;
    forr(i, 1, 1e5) {
        id+=i;
        val.pb(id);
    }
    vll vec(val.size());
    forr(i, 1, val.size()) vec[i] = vec[i-1] + val[i];

    graph = gr2 = vector<vii>(n+1);

    frange(i, m) {
        int a, b, w;
        scd(a);
        scd(b);
        scd(w);
        graph[a].pb(mp(b, w));
        gr2[b].pb(mp(a, w));
    }

    vis = vb(n+1);

    forr(i, 1, n+1) {
        if(!vis[i]) dfs(i);
    }

    reverse(all(order));

    vis = vb(n+1);
    vll tot;
    int c = 0;
    vector<seti> comps;
    vi pos(n+1);
    for(auto e : order) {
        if(!vis[e]) {
            dfs2(e);
            
            lli v1 = 0;
            for(auto x : comp) {
                pos[x] = c;
                for(auto p : graph[x]) {
                    if(comp.find(p.f) != comp.end()) {
                        lli v = p.s;
                        int id = prev(upper_bound(all(val), v)) - val.begin();

                        v1 += v * lli(id+1);
                        v1 -= vec[id];
                        // printf("%lld %lld %d\n", v1, vec[id], id);
                    }
                }
            }
            c++;
            tot.pb(v1);
            // printf("%lld ", v1);
            comps.pb(comp);
            // for(auto e : comp) printf("%d ", e);
            //     printf("\n");
            comp = {};
        }
    }

    vll dp(c);

    for(int i=c-1; i>=0; i--) {
        dp[i] = tot[i];
        for(auto e : comps[i]) {
            for(auto p : graph[e]) {
                if(comps[i].find(p.f) == comps[i].end()) {
                    dp[i] = max(dp[i], tot[i] + dp[pos[p.f]] + p.s);
                }
            }
        }
    }

    int si;
    scd(si);
    
    printf("%lld", dp[pos[si]]);



}