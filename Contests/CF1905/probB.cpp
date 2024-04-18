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
vi dist;

void dfs(int x, int p) {
    if(graph[x].size() == 1) dist[x]=1;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
            dist[x] += dist[e];
        }
    }
}

vi sze;
int n;
 
void dfs_sz(int x, int pre)
{
    for (auto e : graph[x])
    {
        if (e != pre)
        {
            dfs_sz(e, x);
            sze[x] += sze[e];
        }
    }
}
 
int dfs_cent(int x, int pre)
{
    int out = x;
    for (auto e : graph[x])
    {
        if (e != pre)
        {
            if (sze[e] > n / 2)
                out = dfs_cent(e, x);
        }
    }
    return out;
}


int main() {
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        scd(n);

        int c = 0;

        vi deg(n+1);
        graph = vvi(n+1);

        frange(i, n-1) {
            int a, b;
            scd(a);
            scd(b);
            deg[a]++;
            deg[b]++;
            graph[a].pb(b);
            graph[b].pb(a);
        }

        forr(i, 1, n+1) {
            if(deg[i] == 1) c++;
        }
        // sze = vi(n+1);
        // dfs_sz(1, 0);

        // dist = vi(n+1);
        // int id = dfs_cent(1, 0);
        // int diff = 0;
        // dfs(id, 0);
        // mseti st;
        // int tot = 0;
        // for(auto e : graph[id]) {st.insert(dist[e]);}
        // tot = dist[id];

        // if(*prev(st.end()) > tot/2) {
        //     diff = tot-*prev(st.end());
        // }
        // else diff = tot/2;



        printf("%d\n", (c+1)/2);
    }
}