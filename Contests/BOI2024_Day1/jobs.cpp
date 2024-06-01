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
// #define s second
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

int main() {
    // usaco();
    int n;
    lli s;
    scd(n);
    sclld(s);

    vll vec(n+1);
    vvi revg(n+1), graph(n+1);
    vi indeg(n+1);

    forr(i, 1, n+1) {
        int p;
        sclld(vec[i]);
        scd(p);
        if(p) { 
            graph[p].pb(i);
            revg[i].pb(p);
            indeg[i]++;
        }
    } 

    vi topo;
    priority_queue<pair<lli, int>> q;
    forr(i, 1, n+1) {
        if(!indeg[i]) q.push(mp(vec[i], i));
    }
    lli val = s;
    lli ma = s;
    while(q.size()) {
        auto p = q.top();
        q.pop();
        int x = p.second;
        // val += p.f;
        // printf("%d %lld %lld\n", x, p.f, val);
        if(val+p.f < 0) break;
        if(p.f>0) {val += p.f;p.f=0;ma = max(ma, val);}
        
        for(auto e : graph[x]) {
            indeg[e]--;
            if(!indeg[e]) q.push(mp(vec[e]+p.f, e));
        }
    }
    
    printf("%lld", ma-s);
}