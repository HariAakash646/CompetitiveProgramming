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
vi dis1, dis2;

int findf(int x, vi &dis) {
    if(x == dis[x]) return x;
    dis[x] = findf(dis[x], dis);
    return dis[x];
}

void unionf(int x, int y, vi &dis) {
    x = findf(x, dis);
    y = findf(y, dis);
    dis[y] = x;
}

vii bridg;
vi num, lowpt;
int timer=0;

void dfs(int x, int p) {
    num[x] = ++timer;
    lowpt[x] = num[x];
    bool c = 0;
    for(auto e : graph[x]) {
        if(e == p) {
            if(!c) {c=true;continue;}

        }
        
        if(num[e]) lowpt[x] = min(lowpt[x], num[e]);
        else {
            dfs(e, x);
            lowpt[x] = min(lowpt[x], lowpt[e]);
            // if(lowpt[e] > num[x]) bridg.pb(mp(x, e));
        } 
        
    }
    if(p && lowpt[x] > num[p]) bridg.pb(mp(p, x));
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);
    graph = vvi(n+1);
    dis1 = dis2 = vi(n+1);

    forr(i, 1, n+1) {
        dis1[i] = dis2[i] = i;
    }
    int a, b;
    frange(i, m) {
        
        scd(a);
        scd(b);
        if(findf(a, dis1) != findf(b, dis1)) {
            unionf(a, b, dis1);
            graph[a].pb(b);
            graph[b].pb(a);
        }
        else if(findf(a, dis2) != findf(b, dis2)) {
            unionf(a, b, dis2);
            graph[a].pb(b);
            graph[b].pb(a);
        }
        // graph[a].pb(b);
        // graph[b].pb(a);
    }

    lowpt = num = vi(n+1);
    forr(i, 1, n+1) {
        if(!num[i]) dfs(i, 0);
    }

    for(auto p : bridg) printf("%d %d\n", p.f, p.s);

}