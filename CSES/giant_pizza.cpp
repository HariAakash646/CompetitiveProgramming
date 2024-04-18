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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int n, m;

vvi graph, gr2;

vi order;
vb vis;
void dfs(int x) {
    vis[x] = true;
    for(auto e : graph[x]) {
        if(!vis[e]) dfs(e);
    }
    order.pb(x);
}

vvi comps;
vi comp;

void dfs2(int x) {
    vis[x] = true;
    for(auto e : gr2[x]) {
        if(!vis[e]) dfs2(e);
    }
    comp.pb(x);
}

vi dir;
void dfs3(int x) {
    vis[x] = true;
    if(x > m) dir[x-m] = -1;
    else dir[x] = 1;

    for(auto e : graph[x]) {
        if(!vis[e]) dfs3(e);
    }
}

int main() {
    // usaco();
    fastio();
    
    cin >> n >> m;

    gr2 = graph = vvi(2*m+1);

    frange(i, n) {
        char c;
        int a, b;
        cin >> c >> a;
        if(c == '-') a += m;
        cin >> c >> b;
        if(c == '-') b += m;
        if(a > m) {
            graph[a-m].pb(b);
            gr2[b].pb(a-m);
        }
        else {
            graph[a+m].pb(b);
            gr2[b].pb(a+m);
        }
        if(b > m) {
            graph[b-m].pb(a);
            gr2[a].pb(b-m);
        }
        else {
            graph[b+m].pb(a);
            gr2[a].pb(b+m);
        }
    }

    vis = vb(2*m+1);
    forr(i, 1, 2*m+1) {
        if(!vis[i]) dfs(i);
    }

    reverse(all(order));

    vis = vb(2*m+1);

    vi pos(2*m+1);
    int id = 0;

    for(auto i : order) {
        if(!vis[i]) {
            comp = {};
            dfs2(i);
            comps.pb(comp);
            for(auto e : comp) {
                pos[e] = id; 
                // cout << e << " ";
            }
            id++;
            // cout << "\n";
        }
    }

    forr(i, 1, m+1) {
        if(pos[i] == pos[m+i]) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    // dir = vi(m+1);
    // vis = vb(n+1);
    // for(int i=id-1; i>=0; i--) {
    //     vi vec = comps[i];
    //     bool done = true;
    //     for(auto e : vec) {
    //         if(e > m) e -= m;
    //         if(dir[e]) {
    //             done = false;
    //             break;
    //         }
    //     }
    //     if(!done) continue;
    //     dfs3(vec[0]);
    // }

    forr(i, 1, m+1) {
        if(pos[i] > pos[i+m]) cout << "+ ";
        else cout << "- ";
        // cout << dir[i] << " ";
    }





}