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
vvi graph;
vi dist1, dist2;

vi bfs(int x) {
    vi dist(n+1, 1e9);
    vb vis(n+1);
    queue<pii> q;
    q.push(mp(x, 0));
    while(q.size()) {
        auto p = q.front();
        q.pop();
        if(vis[p.f]) continue;
        // printf("%d\n", p.f);
        vis[p.f] = true;
        dist[p.f] = p.s;
        for(auto e : graph[p.f]) {
            // printf("%d ", e);
            q.push(mp(e, p.s+1));
        }
    }
    return dist;
}

vi dp;

int comp(int x) {
    if(!dp[x]) {
        for(auto e : graph[x]) {
            if(dist1[e] < dist1[x] && dist1[e] == dist2[e]) {
                dp[x] = max(comp(e)+1, dp[x]);
            }
        }
    }
    return dp[x];
}

int main() {
    // usaco();
    scd(n); scd(m);
    int s1, s2, a, b;
    scd(s1);
    scd(s2);
    scd(a);
    scd(b);
    graph = vvi(n+1);

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dist1 = bfs(a);
    dist2 = bfs(b);
    int w1 = dist1[s2] - dist1[s1];
    int w2 = dist2[s2] - dist2[s1]; 
    // printf("%d %d ", w1, w2);
    // printf("%d %d %d %d\n", dist1[a], dist1[b], dist2[a], dist2[b]);
    dp = vi(n+1);
    if(w1 < 0 || w2 < 0) printf("-1");
    else {
        if(w1 != w2)
            printf("%d", min(w1, w2));
        else {
            int c = comp(s1);
            int d = comp(s2);
            int w = w1;
            // c + w is direction deciding time of 007.
            // d is the direction deciding time of Mr Null.
            if(c + w >= d) printf("%d", w);
            else printf("%d", w-1);
        }

    }

}