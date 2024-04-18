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

vvi graph, gr2;
vb vis;
vi order;
int timer = 0;
vi inti;

void dfs1(int x) {
    vis[x] = true;
    inti[x] = timer++;
    for(auto e : graph[x]) {
        if(!vis[e]) {
            dfs1(e);
        }
    }
    order.pb(x);
}

vi comp;
void dfs2(int x) {
    vis[x] = true;
    for(auto e : gr2[x]) {
        if(!vis[e]) dfs2(e);
    }
    comp.pb(x);
}

void dfs3(int x) {
    vis[x] = true;
    comp[x] = timer;

    for(auto e : graph[x]) {
        if(!vis[e]) dfs3(e);
    }
}


int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    gr2 = graph = vvi(n+1);

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        if(a == b) continue;
        graph[a].pb(b);
        gr2[b].pb(a);
    }

    vis = vb(n+1);
    inti = vi(n+1);
    forr(i, 1, n+1) {
        if(!vis[i]) dfs1(i);
    }

    vis = vb(n+1);

    reverse(all(order));

    vi pos(n+1);
    vvi comps;

    int id = 0;

    for(auto e : order) {
        if(!vis[e]) {
            comp = {};
            dfs2(e);
            comps.pb(comp);
            for(auto x : comp) pos[x] = id;
            id++;
        }
    }

    vi indeg(id), outdeg(id);
    vvi dirg(id);

    vvi graph2 = graph;
    graph = vvi(id);



    frange(i, id) {
        seti st;
        for(auto e : comps[i]) {
            for(auto x : graph2[e]) st.insert(pos[x]);
        }
        outdeg[i] = st.size();
        for(auto e : st) {
            indeg[e]++;
            dirg[i].pb(e);
            graph[i].pb(e);
            graph[e].pb(i);
        }
    }

    timer = 0;
    vis = vb(id);
    comp = vi(id);

    frange(i, id) {
        if(!vis[i]) {dfs3(i); timer++;}
    }
    vvi comps2 = comps;
    comps = vvi(timer);

    frange(i, id) {
        comps[comp[i]].pb(i);
    }
    seti ind, outd;
    vii out;
    int ov, iv;
    // printf("%d\n", timer);
    frange(i, timer) {
        for(auto e : comps[i]) {
            if(!indeg[e]) ind.insert(e);
            if(!outdeg[e]) outd.insert(e);
        }
    }
    frange(i, timer) {
        if(timer == 1) break;
        ov = -1;
        iv = -1;
        bool od = false;
        bool id = false;
        
        for(auto e : comps[i]) {
            if(outdeg[e]==0) {
                if(!od) {ov = e;od=true; outd.erase(e);}
                // else outd.pb(e);
            }
        }
        int i2 = i+1;
        if(i+1 == timer) i2 = 0;
        for(auto e : comps[i2]) {
            if(indeg[e]==0) {
                if(!id) {iv = e; id=true; ind.erase(e);}
                // else ind.pb(e);
            }
        }
        out.pb(mp(ov, iv));
    }

    auto it1 = ind.begin();
    auto it2 = outd.begin();

    frange(i, min(outd.size(), ind.size())) {
        out.pb(mp(*it2, *it1));
        it1++;
        it2++;
    }

    if(ind.size() > outd.size()) {
        forr(i, outd.size(), ind.size()) {out.pb(mp(!(*it1), *it1)); it1++;}

    }
    else if(outd.size() > ind.size()) {
        forr(i, ind.size(), outd.size()) {out.pb(mp(*it2, !(*it2))); it2++;}
    }
    // for(auto e : outd) printf("%d ", e);
    // printf("\n");
    // for(auto e : ind) printf("%d ", e);
    // printf("\n");


    ov = 0;
    iv = 0;

    comp = vi(id);


    frange(i, id) {
        if(outdeg[i] == 0) ov++;
        if(indeg[i] == 0) iv++;
    }

    printf("%d\n", max(ov, iv));

    for(auto p : out) {
        printf("%d %d\n", comps2[p.f][0], comps2[p.s][0]);
        // printf("%d %d\n", p.f,p.s);
    }


}