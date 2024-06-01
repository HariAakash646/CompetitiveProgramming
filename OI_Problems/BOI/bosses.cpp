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

vvi graph;
vvi tree;
vb vis;
int tot = 0;

int dfs(int x) {
    int v = 1;
    for(auto e : tree[x]) {
        v += dfs(e);
    }
    tot += v;
    return v;
}

int main() {
    // usaco();
    int n;
    scd(n);

    graph = vvi(n+1);

    forr(i, 1, n+1) {
        int k;
        scd(k);
        frange(_, k) {
            int b;
            scd(b);
            graph[b].pb(i);
        }
    }

    int mi = 2e9;

    forr(i, 1, n+1) {
        // vis = vb(n+1);
        // tree = vvi(n+1);
        queue<pii> q;
        vi depth(n+1);
        q.push(mp(i, 0));
        tot = 0;
        while(q.size()) {
            auto p = q.front();
            q.pop();
            if(depth[p.f]) continue;
            // tree[p.s].pb(p.f);
            depth[p.f] = depth[p.s]+1;
            tot += depth[p.f];
            for(auto e : graph[p.f]) q.push(mp(e, p.f));
        }
        bool done = true;
        forr(j, 1, n+1) done = done && (bool)depth[j];
        if(done) {
            
            mi = min(mi, tot);
        }
    }
    printf("%d", mi);
}