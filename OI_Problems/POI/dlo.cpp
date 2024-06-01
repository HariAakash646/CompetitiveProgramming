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

int n, m, p;
vvi graph;

vi bfs(int x) {
    vi dist(n+1, 1e9);
    queue<pii> q;
    q.push(mp(x, 0));

    while(q.size()) {
        auto p = q.front();
        q.pop();
        if(dist[p.f]<=p.s) continue;
        dist[p.f] = p.s;
        for(auto e : graph[p.f]) {
            q.push(mp(e, p.s+1));
        }
    }
    return dist;
}

int rand(int l, int r) {
    return rand() % (r-l+1) + l;
}

int main() {
    // usaco();
    srand(time(0));
    scd(n);
    scd(m);
    scd(p);

    graph = vvi(n+1);
    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vi vec(n);
    frange(i, n) vec[i] = i+1;
    int lim = 200;
    frange(i, n) {
        int i1 = rand(0, n-1);
        swap(vec[i], vec[i1]);
    }
    vi val(min(n, lim));
    vvi dist(min(n, lim));

    frange(i, min(n, lim)) {
        val[i] = vec[i];
        dist[i] = bfs(vec[i]);
    }

    frange(_, p) {
        int u, v;
        scd(u);
        scd(v);
        int mi = 1e9;
        frange(i, min(n, lim)) {
            mi = min(mi, dist[i][u] + dist[i][v]);
        }
        printf("%d\n", mi);
    }
}