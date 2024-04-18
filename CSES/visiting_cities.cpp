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

vector<vi> gr2;
vll tot;
vb vis2;

// lli dfs(int x, lli d) {
//     // tot[x] = d;
//     if(x == n) tot[x] = d;
//     for(auto e : gr2[x]) {
//         tot[x] += d*dfs(e, d);
//     }
//     // tot[x] = v;
//     return tot[x];
// }

const lli mod = (rand() % (int)1e9) + 1e9 + 7;

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    vector<vii> graph(n+1), revg(n+1);

    frange(i, m) {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        graph[a].pb(mp(b, c));
        revg[b].pb(mp(a, c));
    }

    vll dist(n+1, 1e18);

    priority_queue<pair<lli, int>> pq;

    dist[1] = 0;
    pq.push(mp(0, 1));

    vb vis(n+1);

    while(pq.size()) {
        auto p = pq.top();
        pq.pop();

        if(vis[p.s]) continue;

        vis[p.s] = true;

        for(auto e : graph[p.s]) {
            if(e.s + dist[p.s] < dist[e.f]) {
                dist[e.f] = e.s + dist[p.s];
                pq.push(mp(-dist[e.f], e.f));
            }
        }
    }

    queue<int> q;
    vis = vb(n+1);

    gr2 = vector<vi>(n+1);
    vvi rg2(n+1);

    int id = 0;

    q.push(n);

    vi indeg(n+1);

    while(q.size()) {
        int x = q.front();
        q.pop();
        if(vis[x]) continue;

        vis[x] = true;

        for(auto e : revg[x]) {
            if(dist[e.f] + e.s == dist[x]) {
                gr2[e.f].pb(x);
                rg2[x].pb(e.f);
                indeg[x]++;
                q.push(e.f);
            }
        } 
    }

    forr(i, 1, n+1) {
        if(!indeg[i]) q.push(i);
    }
    vi out;
    while(q.size()) {
        int x = q.front();
        q.pop();
        out.pb(x);

        for(auto e : gr2[x]) {
            indeg[e]--;
            if(indeg[e] == 0) q.push(e);
        }
    }
    // for(auto e : out) printf("%d ", e);
    vll dp(n+1), dp2(n+1);
    dp2[1] = 1;
    for(auto x : out) {
        if(x == 1) continue;
        for(auto e : rg2[x]) {
            dp2[x] += dp2[e];
            dp2[x] %= mod;
        }
    }
    reverse(all(out));
    dp[n] = 1;
    for(auto x : out) {
        if(x == n) continue;
        for(auto e : gr2[x]) {
            dp[x] += dp[e];
            dp[x] %= mod;
        }
    }
    seti ou;
    forr(i, 1, n+1) {
        // lli to = 0;
        // for(auto e : rg2[i]) to += dp[e];
        // if(i == 1) to = 1;
        // printf("%lld ", dp2[i]+dp[i]);
        if(dp[1] == (dp2[i]*dp[i])%mod) ou.insert(i);
    }
    
    printf("%d\n", (int)ou.size());
    for(auto e : ou) printf("%d ", e);



}