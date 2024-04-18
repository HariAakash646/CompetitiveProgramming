#include <bits/stdc++.h>
#include "dreaming.h"
 
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
    // freopen("disrupt.in", "r", stdin);
    // freopen("disrupt.out", "w", stdout);
}
 
vector<vii> graph;
vb vis;
vi dp1, dp2;
 
int mv = 2e9;
 
pii diam1(int x, int p) {
    pii ans = mp(0, x);
    for(auto e : graph[x]) {
        if(e.f != p) {
            auto out = diam1(e.f, x);
            ans = max(ans, mp(out.f+e.s, out.s));
        }
    }
    return ans;
}

void dfs(int x) {
    vis[x] = true;
    for(auto e : graph[x]) {
        if(!vis[e.f]) {
            dfs(e.f);
            dp1[x] = max(dp1[x], e.s + dp1[e.f]);
        }
    }
}
 
void dfs2(int x, int p, int d) {
    if(p) {
        dp2[x] = max(dp2[x], dp2[p] + d);
    }
    mv = min(mv, max(dp1[x], dp2[x]));
    int ma = 0;
    int mid = 0;
    int sma = 0;
    int sid = 0;
    for(auto e : graph[x]) {
        if(e.f != p) {
            if(dp1[e.f]+e.s >= ma) {
                sma = ma;
                sid = mid;
                ma = dp1[e.f]+e.s;
                mid = e.f;
            }
            else if(dp1[e.f]+e.s > sma) {
                sma = dp1[e.f]+e.s;
                sid = e.f;
            }
        }
    }
    for(auto e : graph[x]) {
        if(e.f != p) {
            if(e.f == mid) {
                dp2[e.f] = max(dp2[e.f], sma+e.s);
            }
            else {
                dp2[e.f] = max(dp2[e.f], ma+e.s);
            }
            dfs2(e.f, x, e.s);
        }
    }
 
}
 
int travelTime(int n, int m, int l, int A[], int B[], int T[]) {
    graph = vector<vii>(n+1);
    vis = vb(n+1);
    dp1 = dp2 = vi(n+1);
    frange(i, m) {
        graph[A[i]+1].pb(mp(B[i]+1, T[i]));
        graph[B[i]+1].pb(mp(A[i]+1, T[i]));
    }
    int ma = -l;
    int sma = -2*l;
    int thma = -2*l;
    int md = 0;
    forr(i, 1, n+1) {
        if(!vis[i]) {
            pii p = diam1(i, 0);
            p = diam1(p.s, 0);
            md = max(md, p.f);
            mv = 2e9;
            dfs(i);
            dfs2(i, 0, 0);
            if(mv >= ma) {
                thma = sma;
                sma = ma;
                ma = mv;
            }
            else if(mv >= sma) {
                thma = sma;
                sma = mv;
            }
            else thma = max(thma, mv);
        }
    }
    return max({md, thma + sma + 2*l, ma + l + sma});
 
}