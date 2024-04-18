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

int n, m;
vvi graph, gr2;

vi ord;
vb vis;

void dfs(int x) {
    vis[x] = true;
    for(auto e : graph[x]) {
        if(!vis[e]) dfs(e);
    }
    ord.pb(x);
}

vi comp;
void dfs2(int x) {
    vis[x] = true;
    comp.pb(x);
    for(auto e : gr2[x]) {
        if(!vis[e]) dfs2(e);
    }
}

pair<int, lli> cmp(pair<int, lli> x, pair<int, lli> y) {
    if(x.f > y.f) return x;
    else if(y.f > x.f) return y;
    else {
        if(x.s < y.s) return x;
        else return y;
    }
}

int main() {   
    // usaco(); 
    int t;
    scd(t);

    frange(_, t) {
        int n, m;
        scd(n);
        scd(m);

        graph = gr2 = vvi(n+1);

        vll val(n+1);

        forr(i, 1, n+1) sclld(val[i]);

        frange(i, m) {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            gr2[b].pb(a);
        }

        vis = vb(n+1);
        forr(i, 1, n+1) {
            if(!vis[i]) dfs(i);
        }

        reverse(all(ord));

        vvi comps;
        vll tot;
        vi pos(n+1);
        vi sze;
        int id = 0;

        vis = vb(n+1);

        for(auto e : ord) {
            if(!vis[e]) {
                comp = {};
                dfs2(e);
                comps.pb(comp);
                sze.pb(comp.size());
                lli v = 0;
                for(auto e : comp) {
                    v += val[e];
                    pos[e] = id;
                    // printf("%d ", e);
                }
                id++;
                tot.pb(v);
                // printf("%lld\n", v);
            }
        }

        vector<seti> topg(id);

        frange(i, id) {
            for(auto x : comps[i]) {
                for(auto e : graph[x]) {
                    if(pos[e] != i)
                        topg[i].insert(pos[e]);
                }
            }
        }

        vector<pair<int, lli>> dp(id);
        for(int i=id-1; i>=0; i--) {
            pair<int, lli> v = mp(sze[i], tot[i]);
            dp[i] = v;
            for(auto e : topg[i]) {
                dp[i] = cmp(dp[i], mp(v.f + dp[e].f, v.s + dp[e].s));
            }
        }

        pair<int, lli> v = mp(0, 0);
        frange(i, id) v = cmp(v, dp[i]);
        printf("%d %lld\n", v.f, v.s);
    }
}