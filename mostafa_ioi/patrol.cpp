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
int ma = 0;

int dfs1(int x, int p) {
    int v1 = 0;
    int v2 = 0;
    for(auto e : graph[x]) {
        if(e != p) {
            int v = dfs1(e, x) + 1;
            if(v > v1) {
                v2 = v1;
                v1 = v;
            }
            else if(v > v2) {
                v2 = v;
            }
        }
    }
    ma = max(ma, v1 + v2);
    return v1;
}

vi a, b;

int dfs2(int x, int p) {
    priority_queue<pii> pq;
    pii v1 = mp(0, 0);
    int vb = 0;
    pq.push(mp(0, 0));
    
    for(auto e : graph[x]) {
        if(e != p) {
            int v = dfs2(e, x) + 1;
            ma = max(ma, v1.f + a[e]);
            
            ma = max(ma, b[e] + pq.top().f + 1);
            b[x] = max(b[x], a[e] + pq.top().f);
            if(pq.top().s != v1.s)
                ma = max(ma, v1.f + pq.top().f + v);
            else {
                pii tmp = pq.top();
                pq.pop();
                if(pq.size()) ma = max(ma, v1.f + pq.top().f + v);
                pq.push(tmp);
            }
            if(pq.size() >= 2) {
                pii tmp = pq.top();
                pq.pop();
                ma = max(ma, a[e] + tmp.f + pq.top().f);
                pq.push(tmp);
            }
            ma = max(ma, vb + v);
            b[x] = max(b[x], v1.f + v);
            
            a[x] = max(a[x], a[e]);
            b[x] = max(b[x], b[e]+1);
            v1 = max(v1, mp(a[e], e));
            vb = max(vb, b[e]+1);
            pq.push(mp(v, e));
            
        }
    }
    int v1t = 0;
    if(pq.size()) {
        v1t = pq.top().f;
        pq.pop();
        if(pq.size() >= 1) {
            int v2 = pq.top().f;
            pq.pop();
            a[x] = max(a[x], v1t + v2);
            if(pq.size() >= 1) {                
                int v3 = pq.top().f;
                pq.pop();
                b[x] = max(b[x], v1t + v2 + v3);

                if(pq.size()) {
                    int v4 = pq.top().f;
                    pq.pop();
                    ma = max(ma, v1t + v2 + v3 + v4);
                }
            }
        }
        
    }
    return v1t;
}

int main() {
    // usaco();
    int n, k;
    scd(n);
    scd(k);

    graph = vvi(n+1);
    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    if(k == 1) {
        dfs1(1, 0);
        printf("%d\n", 2*(n-1)-ma+1);
    }
    else {
        a = b = vi(n+1);
        dfs2(1, 0);
        printf("%d\n", 2*(n-1) - ma +2);
    }
}