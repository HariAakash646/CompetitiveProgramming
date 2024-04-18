#include <bits/stdc++.h>

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
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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
vb cyc;
vb vis;

int dfs(int x, int p) {
    if(vis[x]) {
        return x;
    }
    vis[x] = true;
    for(auto e : graph[x]) {
        if(e != p) {
            int v = dfs(e, x);
            if(v) {
                cyc[x] = true;
                if(v == x) return 0;
                else return v;
            }
        }
    }
    return 0;
}

int main() {
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n, a, b;
        scd(n);
        scd(a);
        scd(b);
        graph=vvi(n+1);
        cyc = vis = vb(n+1);
        frange(i, n) {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }
        dfs(1, 0);
        queue<pii> q;
        vi distb(n+1, 1e9);
        vi dista(n+1, 1e9);

        q.push(mp(b, 0));
        vis = vb(n+1);
        while(q.size()) {
            auto p = q.front();
            q.pop();
            if(vis[p.f]) {
                continue;
            }
            distb[p.f] = p.s;
            vis[p.f] = true;
            for(auto e : graph[p.f]) {
                q.push(mp(e, p.s+1));
            }
        }
        q.push(mp(a, 0));
        vis = vb(n+1);
        while(q.size()) {
            auto p = q.front();
            q.pop();
            if(vis[p.f]) {
                continue;
            }
            dista[p.f] = p.s;
            vis[p.f] = true;
            for(auto e : graph[p.f]) {
                q.push(mp(e, p.s+1));
            }
        }
        bool done = false;
        forr(i, 1, n+1) {
            if(cyc[i]) {
                // printf("%d ", i);
                if(distb[i] < dista[i]) done = true;
            }
        }
        if(done) printf("YES\n");
        else printf("NO\n");
    }
}