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

vi disset, sze;

int findf(int x)
{
    while (x != disset[x])
    {
        x = disset[x];
    }
    return x;
}

void unionf(int x, int y)
{
    x = findf(x);
    y = findf(y);
    if (x == y)
        return;
    if (sze[x] < sze[y])
    {
        swap(x, y);
    }
    disset[y] = x;
    sze[x] = max(sze[x], sze[y] + 1);
}
 
vector<vector<pair<int, lli>>> graph;
vector<set<pair<int, lli>>> gr2;
vb vis;
vll val;
vb def;

void dfs(int x) {
    def[x] = true;
    for(auto e : graph[x]) {
        if(!def[e.f]) {
            val[e.f] = val[x] + e.s;
            dfs(e.f);
        }
    }
}

vb def2;

bool dfs2(int x) {
    def2[x] = true;
    for(auto e : gr2[x]) {
        if(!def2[e.f]) {
            val[e.f] = val[x] + e.s;
            bool out = dfs2(e.f);
            if(!out) return false;
        }
        else {
            if(val[e.f] != val[x] + e.s) {
                // printf("%d %d %d %d\n", x, e.f, val[e.f], val[x]+e.s);
                return false;
            }
        }
    }
    return true;
}

bool dfs3(int x) {
    def2[x] = false;
    for(auto e : gr2[x]) {
        if(def2[e.f]) {
            dfs3(e.f);
        }
        
    }
    return true;
}

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);

    graph  = vector<vector<pair<int, lli>>>(n+1);
    gr2 = vector<set<pair<int, lli>>>(n+1);

    vector<pair<pii, lli>> vec;
    vi out;

    disset = sze = vi(n+1, 1);

    forr(i, 1, n+1) disset[i] = i; 

    vis = def = vb(n+1);
    val = vll(n+1);

    def2 = vb(n+1);

    frange(i, q) {
        int a, b;
        lli w;
        scd(a);
        scd(b);
        sclld(w);
        vec.pb(mp(mp(a, b), w));


        if(def[a] && def[b]) {
            if(val[a] - w == val[b]) {
                graph[a].pb(mp(b, -w));
                graph[b].pb(mp(a, w));
                gr2[a].insert(mp(b, -w));
                gr2[b].insert(mp(a, w));
                unionf(a, b);
                out.pb(i+1);
            }
        }
        else if(def[a]) {
            def[b] = true;
            vis[b] = true;
            val[b] = val[a] - w;
            dfs(b);
            graph[a].pb(mp(b, -w));
            graph[b].pb(mp(a, w));

            gr2[a].insert(mp(b, -w));
            gr2[b].insert(mp(a, w));
            
            unionf(a, b);
            out.pb(i+1);
        }
        else if(def[b]) {
            def[a] = true;
            vis[a] = true;
            val[a] = val[b] + w;
            dfs(a);
            graph[a].pb(mp(b, -w));
            graph[b].pb(mp(a, w));

            gr2[a].insert(mp(b, -w));
            gr2[b].insert(mp(a, w));
            
            unionf(a, b);
            out.pb(i+1);
        }
        else if(findf(a) == findf(b)) {
            val[a] = 0;
            gr2[a].insert(mp(b, -w));
            gr2[b].insert(mp(a, w));
            def2[a] = true;
            bool ou = dfs2(a);

            if(ou) {
                out.pb(i+1);
                graph[a].pb(mp(b, -w));
                graph[b].pb(mp(a, w));
                def[a] = true;
                dfs(a);
                unionf(a, b);
            }
            else {
                dfs3(a);

                gr2[a].erase(mp(b, -w));
                gr2[b].erase(mp(a, w));
            }
            
        }
        else {
            graph[a].pb(mp(b, -w));
            graph[b].pb(mp(a, w));
            gr2[a].insert(mp(b, -w));
            gr2[b].insert(mp(a, w));
            unionf(a, b);
            out.pb(i+1);
        }

    }
    for(auto e : out) printf("%d ", e);

}