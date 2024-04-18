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
    freopen("input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

vvi graph;
vb vis;
vi proc;
int n, k;

bool dfs(int x, int d) {
    if(vis[x]) {
        return true;
    }
    if(proc[x]) {
        if(d - proc[x] == k) return true; 
        else return false;
    }
    proc[x] = d;
    bool out;
    for(auto e : graph[x]) out = dfs(e, d+1);
    vis[x] = true;
    return out;
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        
        scd(n);
        scd(k);
        if(k == 1) {
            bool done = true;
            forr(i, 1, n+1) {
                int a;
                scd(a);
                if(a != i) done = false;
            }
            if(done)
            printf("YES\n");
        else printf("NO\n");
            continue;
        }
        graph = vvi(n+1);
        vii indeg(n);
        frange(i, n) indeg[i] = mp(0, i+1);
        forr(i, 1, n+1) {
            int a;
            scd(a);
            graph[i].pb(a);
            indeg[a-1].f++;
        }


        sort(all(indeg));
        bool out = true;
        vis = vb(n+1);
        proc = vi(n+1);
        for(auto p : indeg) {
            if(vis[p.s]) continue;
            out = out && dfs(p.s, 1);
        }
        if(out) printf("YES\n");
        else printf("NO\n");
    }
}