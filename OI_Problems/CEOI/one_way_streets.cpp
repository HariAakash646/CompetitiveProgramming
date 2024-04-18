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

vector<vii> graph;
vii edge;
vb dfstree;
vb vis;

void dfs(int x) {
    vis[x] = true;
    for(auto e : graph[x]) {
        if(!vis[e.f] && e.f != x) {
            dfstree[e.s] = true;
            dfs(e.f);
        }
    }
} 

vb bridg;
vector<vii> tree;
vb on;
vi dp;
vi pos;
int c = 0;

void dfs2(int x, int p) {
    vis[x] = true;
    for(auto e : graph[x]) {
        if(!dfstree[e.s] && e.f != x) {
            if(!vis[e.f]) {
                dp[x]--;
            }
            else {
                dp[x]++;
            }
        }
    }

    for(auto e : tree[x]) {
        if(e.f != p && e.f != x) {
            dfs2(e.f, x);
            dp[x] += dp[e.f];
            pos[e.f] = e.s;
        }
    }
}

vi out;

vii val;
vi en, st;

void assg(int a, int b, int id) {
    if(edge[id].f == a) out[id] = 1;
    else out[id] = -1;
}

int dfs3(int x, int p) {
    vis[x] = true;
    int c1 = 0;
    c1 += st[x];
    c1 -= en[x];

    for(auto e : tree[x]) {
        if(e.f != p && e.f != x) {
            int v = dfs3(e.f, x);

            if(bridg[e.s]) {if(v > 0) {
                            assg(e.f, x, e.s);
                        }
                        else if(v < 0) assg(x, e.f, e.s);}
            c1 += v;
        }
    }
    return c1;
}

int main() {
    // usaco();
    int n, m, p;
    scd(n);
    scd(m);
    
    graph = vector<vii>(n+1);
    dfstree = vb(m);
    edge = vii(m);

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(mp(b, i));
        graph[b].pb(mp(a, i));
        edge[i] = mp(a, b);
    }

    vis = vb(n+1);
    forr(i, 1, n+1) {
        if(!vis[i]) dfs(i);
    }

    bridg = vb(m);
    tree = vector<vii>(n+1);
    frange(i, m) {
        if(dfstree[i]) {
            int a= edge[i].f;
            int b = edge[i].s;
            tree[a].pb(mp(b, i));
            tree[b].pb(mp(a, i));
            bridg[i] = true;
        }
    }

    on = vb(m);
    vis = vb(n+1);
    pos = dp = vi(n+1);
    forr(i, 1, n+1) {
        c = 0;
        if(!vis[i]) dfs2(i, 0);
    }



    forr(i, 1, n+1) {
        // printf("%d ", dp[i]);
        if(dp[i]) bridg[pos[i]] = false;
    }

    // frange(i, m) {
    //     if(bridg[i]) printf("%d %d\n", edge[i].f, edge[i].s);
    // }

    
    st = en = vi(n+1);
    scd(p);
    val = vii(p);
    frange(i, p) {
        scd(val[i].f);
        scd(val[i].s);
        // printf("%d %d\n", val[i].f, val[i].s);
        st[val[i].f]++;
        en[val[i].s]++;
    }

    out = vi(m);
    vis = vb(n+1);
    forr(i, 1, n+1) {
        if(!vis[i]) {
            dfs3(i, 0);
        }
    }
    for(auto e : out) {
        if(e == 1) printf("R");
        else if(e == -1) printf("L");
        else printf("B");
    }
}