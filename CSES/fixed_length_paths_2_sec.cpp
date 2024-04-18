#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}



vvi graph;
vi depth;

lli tot = 0;
int k1, k2;

ordered_set dfs(int x, int p, int d) {
    depth[x] = d;
    ordered_set out;
    out.insert(depth[x]);

    for(auto e : graph[x]) {
        if(e != p) {
            ordered_set mv = dfs(e, x, d+1);
            if(out.size() <= mv.size()) out.swap(mv);
            
            for(auto v : mv) {
                int kt1 = k1 - v + 2 * depth[x];
                int kt2 = k2 - v + 2 * depth[x];

                tot += out.order_of_key(kt2+1) - out.order_of_key(kt1);
            }
            for(auto v : mv) out.insert(v);

        }

    }
    // printf("%d\n", x);
    //     for(auto p : out) printf("%d %lld\n", p.f, p.s);
    return out;
}

int main() {
    // usaco();
    int n;
    scd(n);
    
    scd(k1);
    scd(k2);

    graph = vvi(n+1);

    frange(I, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    depth = vi(n+1);
    dfs(1, 0, 0);

    printf("%lld", tot);
}