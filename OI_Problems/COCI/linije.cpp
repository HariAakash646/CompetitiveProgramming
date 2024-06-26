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

vvi graph(1001);
vb vis(1001);

bool dfs(int x) {
    if(vis[x]) return false;
    vis[x] = true;
    bool done = true;
    for(auto e : graph[x]) {
        bool out = dfs(e);
        if(out) done = false;
    }
    return done;
}

int main() {
    // usaco();
    int n;
    scd(n);
    vii vec(n);
    

    frange(i, n) {
        scd(vec[i].f);
        scd(vec[i].s);
        graph[vec[i].f].pb(500+vec[i].s);
        graph[500+vec[i].s].pb(vec[i].f);
    }

    bool done = false;
    forr(i, 1, 1001) {
        if(graph[i].size()) {vis = vb(1001);
                bool out = dfs(i);
                if(out) done = true;}
    }
    if(done) printf("Mirko");
    else printf("Slavko");
}