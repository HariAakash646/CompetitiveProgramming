#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vvi graph;
vb visited;
vi seeds;

bool dfs(int node, int seed) {
    visited[node] = true;
    seeds[node] = seed;
    for(auto e : graph[2 * node - 1]) {
        if(visited[e]) {
            if(seeds[e] != seed) return false;
        }
        else {
            bool out = dfs(e, seed);
            if(!out) return false;
        }
        
    }
    for(auto e : graph[2 * node]) {
        if(visited[e]) {
            if(seeds[e] == seed) return false;
        }
        else {
            bool out = dfs(e, abs(seed-1));
            if(!out) return false;
        }
        
    }
    return true;
}

int main()
{

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n, m;
    scd(n);
    scd(m);
    graph = vvi(2 * n + 1);
    visited = vb(n+1);
    seeds = vi(n+1);
    int a, b;
    char c;
    frange(i, m) {
        cin >> c >> a >> b;
        int one = c == 'S';
        graph[2 * a - one].PB(b);
        graph[2 * b - one].PB(a);
    }
    int no_comp = 0;
    forr(i, 1, n+1, 1) {
        if(!visited[i]) {
            no_comp++;
            bool out = dfs(i, 1);
            if(!out) {
                cout << 0;
                return 0;
            }
        }
    }
    cout << 1;
    for (int i = 0; i < no_comp; i++) {
	cout << 0;
    }
    
    
    return 0;
}
