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
    int n, m;
    scd(n);
    scd(m);
    vvi gr(n+1), rg(n+1);
    vi outdeg(n+1);

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        outdeg[a]++;
        gr[a].pb(b);
        rg[b].pb(a);
    }

    vb vis(n+1);
    vb pick(n+1);
    queue<pair<int, bool>> q;

    forr(i, 1, n+1) {
        if(outdeg[i] == 0) q.push(mp(i, true));
    }

    while(q.size()) {
        auto p = q.front();
        q.pop();
        if(vis[p.f]) continue;
        vis[p.f] = true;
        pick[p.f] = p.s;

        if(p.s) {
            for(auto e : gr[p.f]) {
                q.push(mp(e, !p.s));
            }
            for(auto e : rg[p.f]) {
                q.push(mp(e, !p.s));
            }
        }
        else {
            for(auto e : rg[p.f]) {
                outdeg[e]--;
                if(outdeg[e] == 0) q.push(mp(e, !p.s));
            }
        }
    }

    forr(i, 1, n+1) {
        if(!vis[i]) {
            q.push(mp(i, true));
            while(q.size()) {
                auto p = q.front();
                q.pop();
                if(vis[p.f]) continue;
                vis[p.f] = true;
                pick[p.f] = p.s;

                if(p.s) {
                    for(auto e : gr[p.f]) {
                        q.push(mp(e, !p.s));
                    }
                    for(auto e : rg[p.f]) {
                        q.push(mp(e, !p.s));
                    }
                }
                else {
                    for(auto e : rg[p.f]) {
                        outdeg[e]--;
                        if(outdeg[e] == 0) q.push(mp(e, !p.s));
                    }
                }
            }
        }
    }
    vi out;
    forr(i, 1, n+1) {
        if(pick[i]) out.pb(i);
    }
    printf("%d\n", (int)out.size());
    for(auto e : out) printf("%d ", e);
}