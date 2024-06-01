#include "roads.h"
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

#include <vector>

vll out;
vector<vii> graph;

vector<long long> minimum_closure_costs(int N, vi U, vi V, vi W) {
    graph = vvi(N);
    frange(i, n-1) {
        int u = U[i];
        int v = V[i];
        int w = W[i];
        graph[u].pv(mp(v, w));
        graph[v].pb(mp(u, w));
    } 
    return out;
}
