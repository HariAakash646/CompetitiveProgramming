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

vvi gr2;
vb vis;
vi comp;

void dfs(int x) {
    vis[x] = true;
    comp.pb(x);
    for(auto e : gr2[x]) {
        if(!vis[e]) dfs(e);
    }
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    vvi graph(n+1);
    vi indeg(n+1);

    gr2 = vvi(n+1);

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        indeg[b]++;
        gr2[a].pb(b);
        gr2[b].pb(a);
    }

    vis = vb(n+1);

    int edg = 0;

    forr(i, 1, n+1) {
        if(!vis[i]) {
            comp = {};
            dfs(i);
            queue<int> q;

            for(auto e : comp) {
                if(!indeg[e]) q.push(e);
            }

            while(q.size()) {
                auto x = q.front();
                q.pop();
                for(auto e : graph[x]) {
                    indeg[e]--;
                    if(!indeg[e]) q.push(e);
                }
            }

            bool done = false;
            for(auto e : comp) {
                if(indeg[e]) done = true;
            }
            edg += (int)comp.size() + (int)done - 1;
        }
    }
    printf("%d", edg);
    
}