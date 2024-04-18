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
    // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
    freopen("gathering.in", "r", stdin);
   freopen("gathering.out", "w", stdout);
}

vvi graph;
vi par, cnt, st, en;
vb fir;
int timer = 0;

void dfs(int x, int p) {
    par[x] = p;
    st[x] = ++timer;
    for(auto e : graph[x]) {
        if(e != p) dfs(e, x);
    }
    en[x] = timer;
}

vi val;

void dfs2(int x, int p, int v) {
    val[x] = v;
    for(auto e : graph[x]) {
        if(e != p) dfs2(e, x, v+cnt[x]);
    }
}

vi out;

void dfs3(int x, int p) {
    out[x] = true;
    for(auto e : graph[x]) {
        if(e != p && !fir[e]) dfs3(e, x);
    }
}

int main() {
    usaco();
    int n, m;
    scd(n);
    scd(m);

    graph = vvi(n+1);
    st = en = cnt = par = vi(n+1);
    vi deg(n+1);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        deg[a]++;
        deg[b]++;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(1, 0);

    int tot = 0;
    vi indeg(n+1);
    vvi gr2(n+1);
    fir = vb(n+1);
    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        fir[a] = true;
        gr2[a].pb(b);
        indeg[b]++;
        if(st[a] <= st[b] && st[b] <= en[a]) {
            tot++;
            cnt[a]--;
        }
        else if(st[b] <= st[a] && st[a] <= en[b]) {
            cnt[par[a]]++;
        }
        else {
            cnt[par[a]]++;
        }
    }

    queue<int> q;
    int r = 0;
    forr(i, 1, n+1) {
        if(deg[i] <= 1 && indeg[i] == 0) q.push(i);
    }
    int c = 0;
    vb vis(n+1);
    while(q.size()) {
        auto x = q.front();
        r = x;
        q.pop();
        if(vis[x]) continue;
        vis[x] = true;
        
        c++;

        for(auto e : graph[x]) {
            deg[e]--;
            if(deg[e] <= 1 && !indeg[e]) q.push(e);
        }

        for(auto e : gr2[x]) {
            indeg[e]--;
            if(deg[e] <= 1 && !indeg[e]) q.push(e);
        }

    }

    if(c != n) {
        forr(i, 1, n+1) printf("0\n");
        return 0;
    }

    val = vi(n+1);
    dfs2(1, 0, 0);  

    out = vi(n+1);

    
    dfs3(r, 0);
    forr(j, 1, n+1) {
        printf("%d\n", out[j]);
    }
    return 0;
        
    


}