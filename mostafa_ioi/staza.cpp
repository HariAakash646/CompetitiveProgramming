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

vvi rings;
vvi graph;
vb vis;
stack<int> stk;
vi pos, val;
vi sze;


void dfs(int x, int p) {
    vi curr;
    if(vis[x]) {
        // printf("%d %d\n", x, p);
        while(stk.size() && stk.top() != x) {
            // printf("%d\n", stk.top());
            pos[stk.top()] = rings.size();
            curr.pb(stk.top());
            stk.pop();
        }
        pos[stk.top()] = rings.size();
        curr.pb(stk.top());
        stk.pop();
        rings.pb(curr);
        return;
    }
    vis[x] = true;
    stk.push(x);
    for(auto e : graph[x]) {
        if(e != p && pos[e] == -1) dfs(e, x);
    }
    if(stk.size() && stk.top() == x)
        stk.pop();    
}


int dfs2(int x, int p) {
    // printf("%d %d\n", x, p);
    if(pos[x] != -1) {
        vi rn = rings[pos[x]];
        int sz = sze[pos[x]];
        int ma = 0;
        for(auto e : rn) {
            int ma2 = 0;
            for(auto nx : graph[e]) {
                if(nx != p && pos[nx] != pos[e]) {
                    int v = dfs2(nx, e);
                    ma2 = max(ma2, v+1);
                }
            }
            int v1 = max(val[x], val[e]);
            int v2 = min(val[x], val[e]);
            ma2 += max(v1-v2, sz - v1 + v2);
            printf("%d %d %d %d\n", v1, v2, sz, ma2);
            ma = max(ma, ma2);
        }
        return ma;
    }
    int ma = 0;
    for(auto e : graph[x]) {
        if(e != p) {
            int v = dfs2(e, x);
            ma = max(ma, v+1);
        }
    }
    return ma;
}

int main() {
    usaco();
    int n, m;
    scd(n);
    scd(m);

    graph = vvi(n+1);

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    vis = vb(n+1);
    val = pos = vi(n+1, -1);
    dfs(1, 0);

    
    sze = vi(rings.size());

    frange(i, rings.size()) {
        sze[i] = rings[i].size();
        int id = 0;
        for(auto e : rings[i]) {
            val[e] = id++;
        }
    }

    printf("%d", dfs2(1, 0));
}