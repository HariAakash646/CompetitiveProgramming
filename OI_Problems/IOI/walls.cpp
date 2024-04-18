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

int main() {
    // usaco();
    int m, n, l;
    scd(m);
    scd(n);
    scd(l);
    vi vec(l);
    frange(i, l) scd(vec[i]);

    vvi graph(m+1);
    vvi edge(n+1, vi(n+1));
    vvi reg(n+1);
    forr(i, 1, m+1) {
        int k;
        scd(k);
        int fi;
        scd(fi);
        int pre = fi;
        reg[fi].pb(i);
        int a;
        frange(j, k-1) {
            scd(a);
            reg[a].pb(i);
            if(edge[pre][a]) {
                graph[i].pb(edge[pre][a]);
                graph[edge[pre][a]].pb(i);
            }
            edge[pre][a] = i;
            edge[a][pre] = i;
            pre = a;
        }
        if(edge[fi][a]) {
            graph[edge[fi][a]].pb(i);
            graph[i].pb(edge[fi][a]);
        }
        edge[fi][a] = i;
        edge[a][fi] = i;
    }
    pii mi = {1e6, 1e6};
    forr(i, 1, m+1) {
        queue<pii> q;
        vi dist(m+1, 1e5);
        q.push(mp(i, 0));
        vb vis(m+1);
        while(q.size()) {
            auto p = q.front();
            q.pop();
            if(vis[p.f]) continue;
            vis[p.f] = true;
            dist[p.f] = p.s;

            for(auto e : graph[p.f]) {
                q.push(mp(e, p.s+1));
            }
        }
        int tot = 0;
        frange(k, l) {
            int mv = 1e5;
            for(auto e : reg[vec[k]]) {
                mv = min(mv, dist[e]);
            }
            tot += mv;
        }
        mi = min(mi, {tot, i});
    }
    printf("%d\n%d", mi.f, mi.s);


}