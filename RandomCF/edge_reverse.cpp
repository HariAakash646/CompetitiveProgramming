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
vector<vector<pii>> graph;
vvi cong;
vvi ing;
vb vis;
vi tout;
vii out;
int timer;

void con_dfs(int x) {
    if(vis[x]) return;
    vis[x] = true;
    for(auto e : cong[x]) con_dfs(e);
}

void dfs1(int x) {
    if(vis[x]) return;
    vis[x] = true;
    for(auto e : graph[x]) {
        dfs1(e.f);
    }
    out.pb(mp(timer, x));
    tout[x] = timer;
    timer++;
}

vvi comps;
vi comp;

void dfs2(int x) {
    if(vis[x]) return;
    vis[x] = true;
    for(auto e : ing[x]) {
        dfs2(e);
    }
    comp.pb(x);
}

vector<pair<pii, int>> edg;
vector<seti> tree;

void dfs3(int x) {
    if(vis[x]) return;
    vis[x] = true;
    for(auto e : tree[x]) dfs3(e);
}

bool check(int x) {
    graph = vector<vii>(n+1);
    ing = vvi(n+1);

    frange(i, m) {
        auto p = edg[i];
        if(i < x) {
            ing[p.f.s].pb(p.s);
            graph[p.s].pb(mp(p.f.s, p.f.f));
        }
        graph[p.f.s].pb(mp(p.s, p.f.f));
        ing[p.s].pb(p.f.s);
    }
    vis = vb(n+1);
    timer = 0;
    out = {};
    tout = vi(n+1);
    forr(i, 1, n+1) {
        if(!vis[i]) dfs1(i);
    }
    vis = vb(n+1);
    comps = {};
    sort(all(out), greater<>());
    for(auto p : out) {
        if(vis[p.s]) continue;
        comp = {};
        dfs2(p.s);
        comps.pb(comp);
    }
    
    vi pos(n+1);
    tree = vector<seti>(comps.size());
    frange(i, comps.size()) {
        for(auto e : comps[i]) pos[e] = i;
    }

    frange(i, comps.size()) {
        for(auto e : comps[i]) {
            for(auto x : graph[e]) {
                if(pos[e] != pos[x.f]) tree[pos[e]].insert(pos[x.f]);
            }
        }
    }
    vis = vb(comps.size());
    dfs3(0);

    bool done = true;

    frange(i, comps.size()) done = done && vis[i];
    return done;


}

int main() {
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        scd(n);
        scd(m);

        graph = vector<vector<pii>>(n+1);
        cong = ing = vvi(n+1);
        edg = {};

        frange(_, m) {
            int a, b;
            int w;
            scd(a);
            scd(b);
            scd(w);
            edg.pb(mp(mp(w, a), b));
            cong[a].pb(b);
            cong[b].pb(a);
        }
        sort(all(edg));

        vis = vb(n+1);
        con_dfs(1);
        bool done = true;
        forr(i, 1, n+1) {
            if(!vis[i]) done = false;
        }
        if(!done) {
            printf("-1\n");
            continue;
        }

        

        
        // printf("%d ", comps.size());
        // for(auto e : comps[0]) printf("%d ", e);
        int lo = 0;
        int hi = m;

        while(lo != hi) {
            int mid = (lo+hi)/2;
            if(check(mid)) hi = mid;
            else lo = mid+1;
        }

        if(lo == 0) printf("0\n");
        else
        printf("%d\n", edg[lo-1].f.f);
    }
}