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

struct line {
    lli m, c;

    lli eval(lli x) {return m * x + c;}

    ld intersect(line l) {return ld(c - l.c) / ld(l.m - m);}
};


int main() {
    // usaco();
    int n, q, p, m;
    scd(n);
    scd(q);
    scd(p);
    scd(m);

    vector<vii> graph(n+1), gr2(n+1);

    frange(i, m) {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        graph[a].pb(mp(b, c));
        gr2[b].pb(mp(a, c));
    }

    vll d1(n+1, 1e18), d2(n+1, 1e18);
    d1[q+1] = 0;

    priority_queue<pair<lli, int>> pq;
    pq.push(mp(0, q+1));
    vb vis(n+1);
    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        if(vis[p.s]) continue;
        vis[p.s] = true;

        for(auto e : graph[p.s]) {
            if(d1[p.s] + e.s < d1[e.f]) {
                d1[e.f] = d1[p.s] + e.s;
                pq.push(mp(-d1[e.f], e.f));
            }
        }
    }

    d2[q+1] = 0;
    pq.push(mp(0, q+1));
    vis = vb(n+1);

    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        if(vis[p.s]) continue;
        vis[p.s] = true;

        for(auto e : gr2[p.s]) {
            if(d2[p.s] + e.s < d2[e.f]) {
                d2[e.f] = d2[p.s] + e.s;
                pq.push(mp(-d2[e.f], e.f));
            }
        }
    }

    vll val;
    forr(i, 1, q+1) {
        val.pb(d1[i] + d2[i]);
        // printf("%lld ", d1[i] + d2[i]);
    }

    sort(all(val));
    vll pref(q+1);

    forr(i, 1, q+1) pref[i] = pref[i-1] + val[i-1];

    vector<vll> dp(q+1, vll(p+1, 1e18));
    dp[0][0] = 0;

    forr(i, 1, q+1) {
        
        forr(j, 1, p+1) {
            forr(k, 0, i) {
                lli v = k * (pref[i] - pref[i-k-1]);
                dp[i][j] = min(dp[i][j], dp[i-k-1][j-1] + v);
            }
        }
    }

    forr(j, 1, p+1) {
        deque<line> dq;
        line curr = {0, 0};
        dq.pb(curr);

        forr(i, 1, q+1) {
            while(dq.size() >= 2 && dq[1].eval(i) >= dq[0].eval(i)) dq.pop_front();
            lli v = dq.eval(i) + i * pref[i];
            dp[i][j] = v;

            line curr = {-pref[i], v + pref[i] }
        }
    }

    printf("%lld", dp[q][p]);

}