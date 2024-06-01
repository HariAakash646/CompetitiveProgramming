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

vi vec;
vvi graph;
lli tot = 0;
vector<map<int, int>> val;

void dfs(int x, int p) {
    val[x][vec[x]] = 1;

    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
            if(val[e].size() > val[x].size()) swap(val[x], val[e]);
            for(auto p : val[e]) {
                tot += p.s * lli(val[x][p.f]);
                val[x][p.f] += p.s;
            }
            val[x][vec[x]] = 1;
        }
    }
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        graph = vvi(n+1);
        vec = vi(n+1);
        forr(i,1 , n+1) scd(vec[i]);
        frange(i, n-1) {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }
        tot = 0;
        val = vector<map<int, int>>(n+1);
        dfs(1, 0);

        printf("%lld\n", tot);
    }
}