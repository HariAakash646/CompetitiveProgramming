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

vector<vii> graph;
vb vis;
vb curr;
vvi rings;
stack<int> stk;

void dfs(int x) {
    
    if(curr[x]) {
        vi vec;
        vec.pb(x);
        while(stk.top() != x) {
            int e = stk.top();
            stk.pop();
            curr[e] = false;
            vec.pb(e);
        }
        int e = stk.top();
        stk.pop();
        curr[e] = false;
        vec.pb(e);
        rings.pb(vec);
    }
    
    while(graph[x].size()) {
        auto e = graph[x].back();
        graph[x].pop_back();
        if(!vis[e.s]) {
            curr[x] = true;
            stk.push(x);
            vis[e.s] = true;
            dfs(e.f);
        }
    }
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);
    graph = vector<vii>(n+1);
    int id = 0;

    frange(i, m) {
        int a, b;
        int v1, v2;
        scd(a);
        scd(b);
        scd(v1);
        scd(v2);
        if(v1 != v2) {
            id++;
            graph[a].pb(mp(b, id));
            graph[b].pb(mp(a, id));
        }
    }
    m = id;
    forr(i, 1, n+1) {
        if(graph[i].size() % 2) {
            printf("NIE");
            return 0;
        }
    }

    vis = vb(m+1);
    curr = vb(n+1);

    forr(i, 1, n+1) {
        dfs(i);
    }

    printf("%d\n", (int)rings.size());
    for(auto v : rings) {
        printf("%d ", (int)v.size()-1);
        for(auto e : v) printf("%d ", e);
        printf("\n");
    }

} 