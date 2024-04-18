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

int n, k1, k2;
vvi graph;
vi depth, mvd;

void dfs(int x, int p, int d) {
    depth[x] = d;
    mvd[x] = d;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x, d+1);
            mvd[x] = max(mvd[x], mvd[e]);
        }
    }
}

lli tot = 0;

bool cmp(int x, int y) {
    return mvd[x] < mvd[y];
}

pair<map<int, lli>, map<int, lli>> dfs2(int x, int p, int k) {
    map<int, lli> out1, out2;
    out1[depth[x]] = 1;
    out2[depth[x]] = 1;

    sort(all(graph[x]), cmp);

    for(auto e : graph[x]) {
        if(e != p) {
            auto ou = dfs2(e, x, k);
            auto mv1 = ou.f;
            auto mv2 = ou.s;
            if(mv1.size() > out1.size()) {
                swap(mv1, out1);
                swap(mv2, out2);
            }

            for(auto pi : mv1) {
                auto it = out2.find(k-(pi.f - depth[x]) + depth[x]);
                if(it != out2.end()) {
                    tot += (*it).s * pi.s;
                }
            }
            for(auto pi : mv1) {
                out1[pi.f] += pi.s;
            }
            for(auto pi : mv2) {
                out2[pi.f] += pi.s;
            }
        }
    }
    return mp(out1, out2);
}

int main() {
    usaco();
    
    scd(n);
    scd(k1);
    scd(k2);

    graph = vvi(n+1);
    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    mvd = depth = vi(n+1);
    dfs(1, 0, 0);

    dfs2(1, 0, k2);
    lli v = tot;
    tot = 0;
    dfs2(1, 0, k1-1);

    printf("%lld", v-tot);
}