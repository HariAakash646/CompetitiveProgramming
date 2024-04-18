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
    // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
   freopen("int", "r", stdin);
}

int main() {
    usaco();
    int n, q;
    scd(n);
    scd(q);
    lli d, a, b;
    sclld(d);
    sclld(a);
    sclld(b);

    vector<pair<lli, lli>> vec(n);

    frange(i, n) {
        lli l, r;
        sclld(l);
        sclld(r);
        vec[i] = mp(l, r);
        
    }

    vec.pb(mp(1e13, 1e13));
    vb vis(n+1);
    vll dist(n+1);

    priority_queue<pair<lli, int>> qu;
    qu.push(mp(0, 0));

    while(qu.size()) {
        auto p1 = qu.top();
        pair<int, lli> p = mp(p1.s, -p1.f);
        qu.pop();
        if(vis[p.f]) continue;
        vis[p.f] = true;
        dist[p.f] = p.s;
        if(p.f == n) continue;
        lli l = p.s + d;
        lli r = vec[p.f].f - 1 + d;
        auto it1 = lower_bound(all(vec), mp(l+1, 0LL));
        // auto it2 = lower_bound(all(vec))
        // printf("%d %lld : ", p.f, p.s);
        while(r > (*prev(it1)).s && it1 < vec.end()) {
            // printf("%d ", int(it1 - vec.begin()));
            qu.push(mp(-max(l, (*prev(it1)).s+1), int(it1 - vec.begin())));
            it1++;
        }
        // printf("\n");
    }

    
    frange(i, q) {
        lli x;
        sclld(x);
        auto it = lower_bound(all(vec), mp(x+1, 0LL));
        if(it == vec.begin()) {
            printf("%lld\n", x);
            continue;
        }
        int id = it - vec.begin();
        it--;

        if(!vis[id] || (*it).s >= x || dist[id] > x) printf("-1\n");
        else printf("%lld\n", x);
        
    }

}