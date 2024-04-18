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
    int n;
    scd(n);
    vi vec(n);
    frange(i, n) scd(vec[i]);
    int k;
    scd(k);

    vi dist(vec[0], 2e9);
    vb vis(vec[0]);
    priority_queue<pair<int, int>> pq;
    pq.push(mp(0, 0));
    dist[0] = 0;

    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        if(vis[p.s]) continue;
        vis[p.s] = true;
        for(auto e : vec) {
            int v = (e + p.s) % vec[0];
            if(-p.f + e < dist[v]) {
                dist[v] = -p.f + e;
                pq.push(mp(-dist[v], v));
            }
        }
    }


    frange(_, k) {
        int v;
        scd(v);
        int x = v % vec[0];
        if(v >= dist[x]) printf("TAK\n");
        else printf("NIE\n");
    }
}