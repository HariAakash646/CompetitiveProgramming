#include <bits/stdc++.h>
// #pragma GCC optimize("O3","unroll-loops")

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
vi st, depth, en;
int lift[20][500005];

int timer = 1;
void dfs(int x, int p) {
    st[x] = timer++;
    depth[x] = depth[p]+1;
    sort(all(graph[x]));

    for(auto e : graph[x]) {
        if(e != p) dfs(e, x);
    }
    en[x] = timer;
}

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);

    graph = vvi(n+1);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    en = st = depth = vi(n+1);
    dfs(1, 0);
    vi vec(n+1);
    
    forr(i, 1, n+1) {
        lift[0][st[i]] = en[i];
    }
    lift[0][n+1] = n+1;

    forr(i, 1, 20) {
        forr(j, 1, n+2) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }
    
    frange(_, q) {
        int k;
        scd(k);
        int l, r;
        scd(l);
        scd(r);
        
        int c = 0;
        for(int i=19; i>=0; i--) {
            int lt = lift[i][l];
            if(lt <= r) {
                c += (1<<i);
                l = lt;
            }
        }
        printf("%d\n", c+1);
    }

}   