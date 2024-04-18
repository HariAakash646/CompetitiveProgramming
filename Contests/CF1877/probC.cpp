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

vi graph;
vi val;
vb vis, circle;

int dfs_sz(int x, int v) {
    if(graph[x] == v) return 1;
    return dfs_sz(graph[x], v) + 1;
}

void dfs(int x, int v) {
    int e = graph[x];
    // if(vis[e]) return;
    vis[x] = true;
    circle[e] = true;
    val[x] = e;

    if(graph[e] == v) return;
    dfs(graph[e], v);

} 

int main() {
    usaco();
    int n;
    scd(n);
    vi vec(n+1);
    forr(i, 1, n+1) scd(vec[i]);

    graph = vi(n+1);
    vi indeg(n+1);

    forr(i, 1, n+1) {
        graph[i] = vec[i];
        indeg[vec[i]]++;
    }

    queue<int> q;
    forr(i, 1, n+1) {
        if(indeg[i] == 0) q.push(i);
    }

    circle = vb(n+1);
    vis = vb(n+1);

    val = vi(n+1);

    while(q.size()) {
        int e = q.front();
        q.pop();
        if(vis[e] || circle[e]) continue;
        int c = graph[e];
        val[e] = c;
        circle[c] = true;
        vis[e] = true;
        indeg[vec[c]]--;
        if(indeg[vec[c]] == 0) q.push(vec[c]);
    }

    forr(i, 1, n+1) {
        if(!vis[i] && !circle[i]) {
            int c = dfs_sz(i, i);
            if(c % 2) {
                printf("-1\n");
                return 0;
            }

            dfs(i, i);
        }
    }
    vi out;
    forr(i, 1, n+1) {
        if(val[i]) out.pb(val[i]);
    }
    printf("%d\n", (int)out.size());
    for(auto e : out) printf("%d ", e);
}