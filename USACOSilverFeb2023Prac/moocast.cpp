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
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define pb push_back
#define f first
#define s second
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int n;
vector<vii> graph;
vb vis;

void dfs(int n, int x) {
    vis[n] = true;
    for(auto e : graph[n]) {
        if(!vis[e.f] && e.s <= x) {
            dfs(e.f, x);
        }
    }
}

bool check(int x) {
    int c = 0;
    vis = vb(n);
    frange(i, n) {
        if(!vis[i]) {
            c++;
            dfs(i, x);
        }
    }
    return c <= 1;
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    
    scd(n);
    vii vec(n);
    frange(i, n) {
        scd(vec[i].f);
        scd(vec[i].s);
    }
    graph = vector<vii>(n);
    int h = 0;
    frange(i, n) {
        frange(j, n) {
            if(i == j) continue;
            int v = ((vec[i].f - vec[j].f) * (vec[i].f - vec[j].f)) + ((vec[i].s - vec[j].s) * (vec[i].s - vec[j].s));
            graph[i].pb({j, v});
            graph[j].pb({i, v});
            h = max(v, h);
        }
    }
    
    int l = 0;
    while(l != h) {
        int mid = (l + h) / 2;
        if(check(mid)) {
            h = mid;
        }
        else {
            l = mid + 1;
        }
    }
    printf("%d", l);   
}
