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
vb vis;

vi out;

void dfs(int x) {
    while(graph[x].size()) {
        auto e = graph[x].back();
        graph[x].pop_back();
        if(!vis[e.s]) {
            vis[e.s] = true;
            dfs(e.f);
        }
    }
    out.pb(x);
}

vb vnd;

void dfs2(int x) {
    vnd[x] = true;
    for(auto e : graph[x]) {
        if(!vnd[e.f]) dfs2(e.f);
    }
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    graph = vector<vii>(n+1);
    vis = vb(m);

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(mp(b, i));
        graph[b].pb(mp(a, i));
    }

    forr(i, 1, n+1) {
        if(graph[i].size() % 2) {
            printf("IMPOSSIBLE");
            return 0;
        }
    }

    // vnd = vb(n+1);
    // dfs2(1);
    // forr(i, 1, n+1) {
    //     if(!vnd[i]) {
    //         printf("%d IMPOSSIBLE", i);
    //         return 0;
    //     }
    // }

    dfs(1);

    frange(i, m) {
        if(!vis[i]) {
            printf("IMPOSSIBLE");
            return 0;
        }
    }

    for(auto e : out) printf("%d ", e);

}