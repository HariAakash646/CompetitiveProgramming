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
vi wht, blk;

pii i1 = mp(0, 0);
pii i2 = mp(1, 0);

void dfs(int x, int p, bool t) {
    
    
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x, !t);
            if(!t) wht.pb(e);
            else blk.pb(e);
        }
    }
}

bool cmp(vi &x, vi &y) {
    return x.size() > y.size();
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        wht = blk = {};
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

        
        vi val(n);
        frange(i, n) val[i] = i+1;
        

        vi out(n+1);
        dfs(1, 0, true);
        // for(auto e : wht) printf("%d ", e);
        //     printf("\n");
        // for(auto e : blk) printf("%d ", e);
        //     printf("\n");
        frange(i, wht.size()) {
            out[wht[i]] = val[i];
        }

        frange(i, blk.size()) {
            out[blk[i]] = val[wht.size()+i];
        }

        forr(i, 1, n+1) printf("%d ", out[i]);
        printf("\n");

    }
}