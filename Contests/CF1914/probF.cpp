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
lli out = 0;
vi subsz;

void dfs2(int x, int p) {
    subsz[x] = 1;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs2(e, x);
            subsz[x] += subsz[e];
        }
    }
}

void dfs(int x, int p, lli val) {
    vector<pair<lli, int>> vec;
    lli tot = 0;
    for(auto e : graph[x]) {
        if(e != p) {
            lli v = subsz[e];
            vec.pb(mp(v, e));
            tot += v;
            // printf("%lld %d %d\n", v, e, x);
            // printf("%d %d %d\n", x, e, v);
        }
    }
    if(!vec.size()) return;
    sort(all(vec), greater<>());
    if(vec[0].f-val > (tot-val)/2) {
        out += (tot - val - (vec[0].f-val));
        // printf("%lld %d\n", (tot - val - (vec[0].f-val)), x);
        // int d = 0;
        // if((tot - val - (vec[0].f-val))) d = 1;
        dfs(vec[0].s, x, max(0LL, val+(tot - val - (vec[0].f-val))-1));
    }
    else {
        // printf("%d %lld %lld %lld\n", x, tot, val, out);
        out += (tot-val)/2;
        
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

        forr(i,2, n+1) {
            int pa;
            scd(pa);
            graph[pa].pb(i);
            graph[i].pb(pa);
        }
        out = 0;
        subsz = vi(n+1);
        dfs2(1, 0);
        dfs(1, 0, 0);
        printf("%lld\n", out);
    }
}