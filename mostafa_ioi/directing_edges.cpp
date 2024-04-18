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
    int t;
    scd(t);

    frange(_, t) {
        int n, m;
        scd(n);
        scd(m);
        vvi graph(n+1);
        vii edg;
        vi indeg(n+1);

        frange(i, m) {
            int t, a, b;
            scd(t);
            scd(a);
            scd(b);
            if(t) {
                graph[a].pb(b);
                indeg[b]++;
            }
            edg.pb(mp(a, b));
        }
        vi topo;
        queue<int> q;

        forr(i, 1, n+1) {
            if(!indeg[i]) q.push(i);
        }

        while(q.size()) {
            auto x = q.front();
            q.pop();
            topo.pb(x);

            for(auto e : graph[x]) {
                indeg[e]--;
                if(!indeg[e]) q.push(e);
            }
        }

        if(topo.size() < n) {
            printf("NO\n");
            continue;
        }

        vi pos(n+1);
        frange(i, n) pos[topo[i]] = i;

        printf("YES\n");
        for(auto p :edg) {
            if(pos[p.f] > pos[p.s]) swap(p.f, p.s);
            printf("%d %d\n", p.f, p.s);
        }

    }
}