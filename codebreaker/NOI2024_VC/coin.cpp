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

int n, m;

vector<vii> graph, ing;
vb vis;

void dfs1(int x, int v) {
    vis[x] = true;
    for(auto e : graph[x]) {
        if(e.s <= v && !vis[e.f]) dfs1(e.f, v);
    }
}

void dfs2(int x, int v) {
    vis[x] = true;
    for(auto e : ing[x]) {
        if(e.s <= v && !vis[e.f]) dfs2(e.f, v);
    }
}

bool check(int x, int v) {
    vis = vb(n+1);
    dfs1(x, v);
    dfs2(x, v);
    int c = 0;
    forr(i, 1, n+1) c += vis[i];
    return c == n;
}

int main() {
    // usaco();
    
    scd(n);
    scd(m);
    graph = ing = vector<vii>(n+1);

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(mp(b, i+1));
        ing[b].pb(mp(a, i+1));
    }

    forr(i, 1, n+1) {
        int lo = 1;
        int hi = m+1;
        while(lo != hi) {
            int mid = (lo+hi)/2;
            if(check(i, mid)) hi = mid;
            else lo = mid+1;
        }
        if(lo == m+1) lo = -1;
        printf("%d ", lo);
    }
}