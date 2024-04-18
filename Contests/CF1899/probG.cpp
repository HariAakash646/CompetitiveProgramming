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
int timer=0;
vi pos;
vector<vector<pair<int, pii>>> quer;
vb out;

seti dfs(int x, int p) {
    seti ou;
    ou.insert(pos[x]);
    for(auto e : graph[x]) {
        if(e != p) {
            seti st = dfs(e, x);
            if(ou.size() < st.size()) swap(ou, st);
            for(auto e : st) ou.insert(e);
        }
    }
    for(auto e : quer[x]) {
        auto it1 = ou.lower_bound(e.s.f);
        auto it2 = ou.upper_bound(e.s.s);
        // printf("%d ", e.f);
        // for(auto e : ou) printf("%d ", e);
        // printf("\n");
        if(it1 != it2) out[e.f] = true;
    }
    return ou;
}


int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
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
        
        pos = vi(n+1);
        forr(i, 1, n+1) {
            int x;
            scd(x);
            pos[x] = i;
        }

        quer = vector<vector<pair<int, pii>>>(n+1);
        out = vb(q);

        frange(i, q) {
            int l, r, x;
            scd(l);
            scd(r);
            scd(x);
            quer[x].pb(mp(i, mp(l, r)));
        }

        dfs(1, 0);
        frange(i, q) {
            if(out[i]) printf("YES\n");
            else printf("NO\n");
        }

        

    }
}