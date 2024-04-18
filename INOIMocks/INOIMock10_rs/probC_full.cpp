#include <bits/stdc++.h>
 
using namespace std;
 
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;
 
void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}
 
int n, m;
 
vector<vector<pair<int, lli>>> graph;
// vll dp;
 
struct Data {

    lli a = 0;
    lli b = 0;

    priority_queue<lli> pq;

};

Data dfs(int x, lli c) {
    if(x > n) {
        Data out;
        out.pq.push(c);
        out.pq.push(c);
        out.a = 1;
        out.b = -c;
        return out;
    }
    Data out;
    for(auto e : graph[x]) {
        auto v = dfs(e.f, e.s);
        out.a += v.a;
        out.b += v.b;
        if(out.pq.size() < v.pq.size()) swap(out.pq, v.pq);
        while(v.pq.size()) {
            lli x = v.pq.top();
            v.pq.pop();
            out.pq.push(x);
        }
    }
    while(out.a > 1) {
        out.a--;
        out.b += out.pq.top();
        out.pq.pop();
    }

    lli v1 = out.pq.top();
    out.pq.pop();
    lli v0 = out.pq.top();
    out.pq.pop();
    out.pq.push(v1 + c);
    out.pq.push(v0 + c);
    out.b -= c;
    return out;
}
 
int main() {
    // usaco();
    
    scd(n);
    scd(m);
 
    graph = vector<vector<pair<int, lli>>>(n+1);
 
    forr(i, 2, n+m+1) {
        int pa;
        lli c;
        scd(pa);
        sclld(c);
        graph[pa].pb(mp(i, c));
    }
    Data out = dfs(1, 0);
 
    while(out.a > 0) {
        out.a--;
        out.b += out.pq.top();
        out.pq.pop();
    }

    printf("%lld", out.b);

}
