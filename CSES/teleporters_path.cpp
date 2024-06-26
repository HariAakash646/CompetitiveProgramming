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
vi out;
vb vis;

void dfs(int x) {
    while(graph[x].size()) {
        auto p = graph[x].back();
        graph[x].pop_back();
        if(vis[p.s]) continue;
        vis[p.s] = true;
        dfs(p.f);
    }
    out.pb(x);
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);
    vi indeg(n+1), outdeg(n+1);

    graph = vector<vii>(n+1);

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(mp(b, i));
        indeg[b]++;
        outdeg[a]++;
    }

    indeg[1]++;
    outdeg[n]++;

    forr(i, 1, n+1) {
        if(indeg[i] != outdeg[i]) {
            printf("IMPOSSIBLE");
            return 0;
        }
    }

    vis = vb(m+1);
    dfs(1);

    frange(i, m) {
        if(!vis[i]) {
            printf("IMPOSSIBLE");
            return 0;
        }
    }

    reverse(all(out));

    if(out.back() != n) {
        printf("IMPOSSIBLE");
        return 0;
    }

    for(auto e : out) {
        printf("%d ", e);
    }

    

}