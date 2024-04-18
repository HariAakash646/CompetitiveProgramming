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
    vll vec(n+1);

    forr(i, 1, n+1) sclld(vec[i]);
    if(m > n) {
        printf("0");
        return 0;
    }
    vector<set<pii>> graph(n+1);
    vi deg(n+1);
    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].insert(mp(b, i));
        graph[b].insert(mp(a, i));
        deg[a]++;
        deg[b]++;
    }
    vll out(m);
    queue<int> q;
    forr(i, 1, n+1) {
        if(deg[i] == 1) q.push(i);
    }

    vb cyc(n+1, true);
    vb vis(n+1);
    while(q.size()) {
        auto x = q.front();
        q.pop();
        cyc[x] = false;
        vis[x] = true;
        for(auto p : graph[x]) {
            graph[p.f].erase(mp(x, p.s));
            deg[p.f]--;
            out[p.s] = 2*vec[x];
            vec[p.f] -= vec[x];
            if(deg[p.f] == 1) q.push(p.f);
        }
    }
    int c = 0;
    forr(i, 1, n+1) {
        if(cyc[i]) c++;
    }
    if(c > 0 && c % 2==0) {
        printf("0");
        return 0;
    }
    forr(i, 1, n+1) {
        if(cyc[i]) {
            pii p = (*graph[i].begin());
            // printf("sz: %d\n", (int)graph[i].size());
            int x = p.f;
            int ed = p.s;
            lli k = 0;
            int par = i;
            while(x != i) {
                k = vec[x] - k;
                int tmp = x;
                if((*graph[x].begin()).f != par)
                    x = (*graph[x].begin()).f;
                else x = (*next(graph[x].begin())).f;
                par = tmp;
            }
            // printf("%lld\n", k);
            lli v = (vec[i] - k)/2;
            out[ed] = 2 * v;
            x = (*graph[i].begin()).f;
            par = i;
            while(x != i) {
                v = vec[x] - v;
                int tmp = x;
                if((*graph[x].begin()).f != par)
                {pii p = *graph[x].begin();
                                out[p.s] = 2*v;
                                x = p.f;}
                else {
                    pii p = *next(graph[x].begin());
                    out[p.s] = 2*v;
                    x = p.f;
                }
                par = tmp;
            }
            break;
        }
    }
    frange(i, m) printf("%lld\n", out[i]);
}