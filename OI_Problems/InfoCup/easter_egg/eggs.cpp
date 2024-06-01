#include <bits/stdc++.h>
#include "grader.h"

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

vi order;
vvi graph; 

void dfs(int x, int p) {
    order.pb(x);
    for(auto e : graph[x]) {
        if(e != p) dfs(e, x);
    }
}

vi slic(vi &vec, int r) {
    vi out;
    frange(i, r+1) {
        out.pb(vec[i]);
    }
    return out;
}

int findEgg (int n, vector < pair < int, int > > bridges)
{
    graph = vvi(n+1);
    for(auto p : bridges) {
        graph[p.f].pb(p.s);
        graph[p.s].pb(p.f);
    }
    dfs(1, 0);
    int lo = 0;
    int hi = n-1;
    while(lo != hi) {
        int mid = (lo+hi)/2;
        if(!query(slic(order, mid))) lo = mid+1;
        else hi = mid;
    }
    return order[lo];
}
