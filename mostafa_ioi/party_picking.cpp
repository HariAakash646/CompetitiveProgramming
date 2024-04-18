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

vi disset;
int findf(int x) {
    if(x == disset[x]) return x;
    disset[x] = findf(disset[x]);
    return disset[x];
}

void unionf(int x, int y) {
    x = findf(x);
    y = findf(y);
    if(x == y) return;
    disset[x] = y;
}

vvi graph;
vvi revg;

vb vis;
vi order;

void dfs(int x) {
    vis[x] = true;
    for(auto e : graph[x]) {
        if(!vis[e]) dfs(e);
    }
    order.pb(x);
}

vi comp;

void dfs2(int x) {
    vis[x] = true;
    comp.pb(x);
    for(auto e : revg[x]) {
        if(!vis[e]) dfs2(e);
    }
}

int main() {
    usaco();
    int n, r;
    scd(n);
    scd(r);

    graph = vvi(2*n+1);
    revg = vvi(2*n+1);

    vi pick;

    disset = vi(2*n+1);
    forr(i, 1, 2*n+1) disset[i] = i;

    frange(_, r) {
        int t, k;
        scd(t);
        scd(k);
        int u, v;
        scd(u);
        if(k == 2)
        {
            scd(v);
            if(t == 1) {
                graph[u].pb(v+n);
                graph[u+n].pb(v);
                graph[v].pb(u+n);
                graph[v+n].pb(u);

                revg[u].pb(v+n);
                revg[u+n].pb(v);
                revg[v].pb(u+n);
                revg[v+n].pb(u);

                unionf(u, v+n);
                unionf(u+n, v);
                // unionf(v, u+n);
                // unionf(v+n, u);
            }
        }
        else {
            if(t == 1) pick.pb(u);
        }
    }

    vis = vb(2*n+1);

    forr(i, 1, 2*n+1) {
        if(!vis[i]) dfs(i);
    }

    vis = vb(2*n+1);
    reverse(all(order));

    vi pos(2*n+1);
    int id = 1;
    for(auto e : order) {
        if(!vis[e]) {
            comp = {};
            dfs2(e);
            for(auto x : comp) pos[x] = id;
            id++;
        }
    }

    // vb use(id, true);
    // forr(e, 1, n+1) {
    //     if((pos[e+n] <= pos[e]) && findf(e) == findf(e+n)) use[pos[e+n]] = false;
    //     if((pos[e] <= pos[e+n]) && findf(e) == findf(e+n)) use[pos[e]] = false;
    // }

    bool out = true;
    seti outv;
    forr(i, 1, n+1) {
        if(findf(i) == findf(i+n)) out = false;
        else outv.insert(i);
    }

    // queue<int> q;

    // for(auto e : pick) {
    //     if(pos[e] <= pos[e+n] && findf(e) == findf(e+n)) out = false;
    //     // else q.push(e);
    // }

    // vis = vb(2*n+1);
    // while(q.size()) {
    //     int x = q.front();
    //     q.pop();
    //     if(vis[x]) continue;
    //     vis[x] = true;
    //     if(x <= n) outv.pb(x);
        
    //     for(auto e : graph[x]) {
    //         q.push(e);
    //     }
    // }

    if(out) {
        printf("Yes\n");

        printf("%d\n", (int)outv.size());
        for(auto e : outv) printf("%d\n", e);
    }
    else printf("No\n");



    

}