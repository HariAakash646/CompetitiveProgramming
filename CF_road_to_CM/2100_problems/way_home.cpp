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

struct Dat {
    lli perf = 0;
    lli cost = 0;
    int x = 0;
    int ma = 0;

    bool operator<(const Dat &y) const {
        if(perf < y.perf) return false;
        else if(perf == y.perf) return cost < y.cost;
        else return true;
    }
};

int main() {
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n, m;
        lli p;
        scd(n);
        scd(m);
        sclld(p);
        vll val(n+1);
        forr(i, 1, n+1) sclld(val[i]);

        vector<vector<pair<int, lli>>> graph(n+1);

        frange(i, m) {
            int a, b;
            lli c;
            scd(a);
            scd(b);
            sclld(c);
            graph[a].pb(mp(b, c));
        }
        vector<vector<pair<lli, lli>>> dist(n+1, vector<pair<lli, lli>>(n+1, mp(1e18, -1)));

        dist[1][1] = mp(0, p);

        priority_queue<Dat, vector<Dat>> pq;

        Dat tmp;
        tmp.perf = 0;
        tmp.cost = p;
        tmp.x = 1;
        tmp.ma = 1;

        pq.push(tmp);

        vector<vb> vis(n+1, vb(n+1));

        while(pq.size()) {
            auto p = pq.top();
            pq.pop();
            if(vis[p.x][p.ma]) continue;
            vis[p.x][p.ma] = true;

            // printf("%d %d %lld %lld\n", p.x, p.ma, dist[p.x][p.ma].f, dist[p.x][p.ma].s);

            for(auto e : graph[p.x]) {
                Dat tmp = p;
                tmp.cost -= e.s;
                if(tmp.cost < 0) {
                    lli v = (abs(tmp.cost) + val[p.ma] - 1) / val[p.ma];
                    tmp.cost += v * val[p.ma];
                    tmp.perf += v;
                }
                tmp.x = e.f;
                if(val[e.f] > val[tmp.ma]) tmp.ma = e.f;

                if(tmp.perf < dist[e.f][tmp.ma].f) {
                    dist[e.f][tmp.ma] = mp(tmp.perf, tmp.cost);
                    pq.push(tmp);
                }
                else if(tmp.perf == dist[e.f][tmp.ma].f && tmp.cost > dist[e.f][tmp.ma].s) {
                    dist[e.f][tmp.ma] = mp(tmp.perf, tmp.cost);
                    pq.push(tmp);
                }
            }
        }
        pair<lli, lli> p1 = mp(1e18, -1);
        forr(i, 1, n+1) {
            if(dist[n][i].s >= 0 && dist[n][i].f < p1.f) p1 = dist[n][i];
        }
        if(p1.s >= 0) printf("%lld\n", p1.f);
        else printf("-1\n");
    }
}