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
        map<int, vi> col;

        frange(i, m) {
            int a, b, c;
            scd(a);
            scd(b);
            scd(c);
            col[c].pb(a);
            col[c].pb(b);
            graph[a].pb(c);
            graph[b].pb(c);
        }

        int st, en;
        scd(st);
        scd(en);
        if(st == en) {
            printf("0\n");
            continue;
        }

        queue<pair<int, int>> q;
        for(auto e : graph[st]) {
            q.push(mp(e, 1));
        }   

        vb vis(n+1);
        map<int, bool> visc;

        while(q.size()) {
            auto p = q.front();
            q.pop();
            if(visc[p.f]) continue;
            visc[p.f] = true;
            for(auto e : col[p.f]) {
                if(e == en) {
                    printf("%d\n", p.s);
                    q = {};
                    break;
                }
                if(!vis[e]) {
                    vis[e] = true;
                    for(auto x : graph[e]) q.push(mp(x, p.s+1));
                }
            }
        }

    }
}