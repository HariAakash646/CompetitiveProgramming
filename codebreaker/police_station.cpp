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

vvi graph;
vvi revg;
vii order;
vb vis;
int timer=0;

void dfs(int x) {
    vis[x] = true;
    for(auto e : graph[x]) {
        if(!vis[e]) dfs(e);
    }
    timer++;
    order.pb(mp(timer, x));
}

vi comp;
vvi comps;

void dfs2(int x) {
    vis[x] = true;
    for(auto e : revg[x]) {
        if(!vis[e]) dfs2(e);
    }
    comp.pb(x);
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);
    revg = graph = vvi(n+1);

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        revg[b].pb(a);
    }

    vis = vb(n+1);
    forr(i, 1, n+1) {
        if(!vis[i]) dfs(i);
    }
    sort(all(order), greater<>());
    vis = vb(n+1);

    vi pos(n+1);
    for(auto p : order) {
        int i = p.s;
        if(!vis[i]) {
            comp = {};
            dfs2(i);
            for(auto e : comp) pos[e] = comps.size();
            comps.pb(comp);
        }
    }

    vector<seti> dagr(comps.size());
    frange(i, comps.size()) {
        for(auto e : comps[i]) {
            for(auto x : graph[e]) {
                if(i != pos[x]) dagr[i].insert(pos[x]);
            }
        }
    }
    vi deg(comps.size());

    for(auto st : dagr) {
        for(auto e : st) deg[e]++;
    }
    vi st;
    frange(i, comps.size()) {
        if(deg[i]==0) st.pb(i);
    }
    if(st.size() == 1) {
        int id = st[0];
        printf("%d\n", (int)comps[id].size());
        sort(all(comps[id]));
        for(auto e : comps[id]) printf("%d ", e);
    }
    else {
        printf("0");
    }
}