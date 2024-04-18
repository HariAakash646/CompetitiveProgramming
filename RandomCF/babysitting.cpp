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

int sze, n;
vvi graph, gr2;

void build(int x, int l, int r) {
    if(l == r) {
        if(l < n) {    
            graph[x].pb(l+n+2*sze);
            gr2[l+n+2*sze].pb(x);
        }
        return;
    }
    int mid = (l+r)/2;
    build(2*x+1, l, mid);
    build(2*x+2, mid+1, r);
    graph[x].pb(2*x+1);
    graph[x].pb(2*x+2);
    gr2[2*x+1].pb(x);
    gr2[2*x+2].pb(x);
}

void update(int x, int l, int r, int lx, int rx, int id) {
    if(lx > rx) return;
    if(lx > r || rx < l) {
        return;
    }
    if(lx <= l && r <= rx) {
        graph[id+2*sze].pb(x);
        gr2[x].pb(id+2*sze);
        return;
    }
    int mid = (l+r)/2;
    update(2*x+1, l, mid, lx, rx, id);
    update(2*x+2, mid+1, r, lx, rx, id);
}

vb vis;
vi order;

void dfs(int x) {
    vis[x] = true;
    // printf("%d ", x);
    for(auto e : graph[x]) {
        if(!vis[e]) {
            dfs(e);
        }
    }
    order.pb(x);
}

vi pos;

void dfs2(int x, int id) {
    pos[x] = id;
    vis[x] = true;
    
    for(auto e : gr2[x]) {
        if(!vis[e]) {
            dfs2(e, id);
        }
    }
}

bool check(int x) {
    vvi ogr = graph;
    vvi ogr2 = gr2;

    frange(i, n) {
        update(0, 0, sze-1, i+1, min(i+x-1, n-1), i);
        update(0, 0, sze-1, max(0, i-x+1), i-1, i);
        // forr(j, i+1, min(n-1, i+x-1)+1) {
        //     graph[i+2*sze].pb(j+n+2*sze);
        //     gr2[j+n+2*sze].pb(i+2*sze);
        // }
        // forr(j, max(0, i-x+1), i) {
        //     graph[i+2*sze].pb(j+n+2*sze);
        //     gr2[j+n+2*sze].pb(i+2*sze);
        // }
    }

    order = {};
    vis = vb(2*sze+2*n+1);
    frange(i, 2*sze+2*n) {
        if(!vis[i]) {dfs(i);}

    }

    reverse(all(order));

    vis = vb(2*sze+2*n+1);
    pos = vi(2*sze+2*n+1);
    int id = 1;
    for(auto e : order) {
        if(!vis[e]) {
            // printf("%d ", e);
            dfs2(e, id);
            
            id++;
        }
    }

    bool done = true;
    frange(i, n) {
        if(pos[i+2*sze] == pos[i+2*sze+n]) done = false;
    }
    graph = ogr;
    gr2 = ogr2;
    return done;
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int m;
        scd(n);
        scd(m);

        sze = 1;
        while(sze < n) sze *= 2;

        gr2 = graph = vvi(2*sze + 2*n+1);

        frange(i, m) {
            int a, b;
            scd(a);
            scd(b);
            a--;
            b--;
            graph[a+n+2*sze].pb(b + 2*sze);
            graph[b+n+2*sze].pb(a + 2*sze);
            gr2[b+2*sze].pb(a+n+2*sze);
            gr2[a+2*sze].pb(b+n+2*sze);
        }

        build(0, 0, sze-1);

        int lo = 1;
        int hi = n;

        while(lo != hi) {
            int mid = (lo+hi+1)/2;
            if(check(mid)) {
                lo = mid;
            }
            else {
                hi = mid-1;
            }
        }
        printf("%d\n", lo);
    }
}