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
vb leav;


vi pos;
int timer = 0;

void dfs(int x, int p) {
    if(graph[x].size() == 1) leav[x] = true;
    pos[x] = timer++;
    for(auto e : graph[x]) {
        if(e != p) dfs(e, x);
    }
}



int main() {
    // usaco();
    int n;
    scd(n);

    graph = vvi(n+1);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    
    vii out;

    pos = vi(n+1);
    leav = vb(n+1);
    dfs(1, 0);

    vii nd;

    forr(i, 1, n+1) {
        if(leav[i]) nd.pb(mp(pos[i], i));
    }

    if(nd.size() % 2) nd.pb(mp(pos[1], 1));

    int c = nd.size();
    sort(all(nd));
    frange(i, c/2) {
        out.pb(mp(nd[i].s, nd[i+c/2].s));
    }

    // if(c % 2) out.pb(mp(1, nd[c-1].s));

    printf("%d\n", (int)out.size());
    for(auto e :out) printf("%d %d\n", e.f, e.s);


    
}