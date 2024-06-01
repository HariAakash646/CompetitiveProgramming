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

int main() {
    // usaco();
    int n, k;
    scd(n);
    scd(k);
    vvi graph(n);
    vi deg(n);
    vector<seti> con(n);
    frange(i, n) {
        int c;
        scd(c);
        frange(_, c) {
            int x;
            scd(x);
            graph[i].pb(x);
            con[i].insert(x);
            deg[i]++;
        }
    }

    vb vis(n);
    priority_queue<pii> pq;
    frange(i, n) pq.push(mp(-deg[i], i));
    int ma = 0;
    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        if(vis[p.s]) continue;
        vi vec;
        for(auto e : graph[p.s]) {
            if(!vis[e]) vec.pb(e);
        }

        int c = vec.size();
        frange(i, 1<<c) {
            vi curr;
            frange(j, c) {
                if(i & (1<<j)) curr.pb(vec[j]);
            }
            bool done = true;
            frange(j, curr.size()) {
                forr(k, j+1, curr.size()) {
                    if(con[curr[j]].find(curr[k]) == con[curr[j]].end()) done = false;
                }
            }
            if(done) {
                ma = max(ma, (int)curr.size() + 1);
            }
        }
        vis[p.s] = true;
        for(auto e : graph[p.s]) {
            deg[e]--;
            if(!vis[e]) pq.push(mp(-deg[e], e));
        }
    }
    printf("%d\n", ma);
}