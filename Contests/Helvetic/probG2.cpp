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
typedef vector<vll> vvll;


void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

lli c;
int n, m;
vvi graph;
vi pos;

bool dfs(int x, int p, int v) {
    if(pos[x]) {
        if(pos[x] == v) return true;
        else return false;
    }
    pos[x] = v;
    for(auto e : graph[x]) {
        if(e != p) {
            bool o = dfs(e, 0, v);
            if(!o) return o;
        }
    }
    return true;
}

lli val(int u, int v) {
    
    int a = 1;
    for(auto e : graph[u]) {
        if(e == v) a = 0;
    }
    pos = vi(n+1);
    dfs(u, v, 1);
    bool o = dfs(v, u, 2);
    if(!o) return 1e18;

    lli v1 = 0, v2=0, v3=0;
    int id = 3;
    forr(i, 1, n+1) {
        if(pos[i] == 1) v1++;
        if(pos[i] == 2) v2++;
        if(pos[i] == 0) {
            v3++;
            dfs(i, 0, id);
            id++;
        }
    }
    vi sze(id-3);
    forr(i, 1, n+1) {
        if(pos[i] > 2)
            sze[pos[i]-3]++;
    }
    a += v3;
    sort(all(sze), greater<>());

    for(auto e : sze) {
        if(v1 <= v2) v1+=e;
        else v2+=e;
    }

    return v1*v1 + v2*v2 + c*a;
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        scd(n);
        scd(m);
        sclld(c);

        graph = vvi(n+1);

        frange(i, m) {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }

        lli mi = 1e18;
        forr(i, 1, n+1) {
            forr(j, i+1, n+1) {
                // if(i != j)
                // printf("%d %d %lld\n", i, j, val(i, j));
                mi = min(mi, val(i, j));
            }
        }
        if(mi == 1e18) printf("-1\n");
        else
        printf("%lld\n", mi);
    }
}