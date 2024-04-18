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
    int n, k, d;
    scd(n);
    scd(k);
    scd(d);

    vector<vii> graph(n+1);

    queue<int> q;
    vii dist(n+1, mp(1e9, 1e9));
    frange(i, k) {
        int a;
        scd(a);
        q.push(a);
        dist[a] = mp(0, a);
    }

    vii edg(n-1);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(mp(b, i));
        graph[b].pb(mp(a, i));
        edg[i] = mp(a, b);
    }

    while(q.size()) {
        auto p = q.front();
        q.pop();

        for(auto e : graph[p]) {
            if(mp(dist[p].f + 1, dist[p].s) < dist[e.f]) {
                dist[e.f] = mp(dist[p].f + 1, dist[p].s);
                q.push(e.f);
            }
        }
    }
    vi out;
    frange(i, n-1) {
        if(dist[edg[i].f].s != dist[edg[i].s].s) {
            out.pb(i+1);
        }
    }
    printf("%d\n", (int)out.size());
    for(auto e : out) printf("%d ", e);
}