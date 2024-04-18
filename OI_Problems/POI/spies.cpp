#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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

vi graph;
vb vis;

int main() {
    // usaco();
    int n;
    scd(n);

    graph = vi(n+1);
    vi indeg(n+1);

    forr(i, 1, n+1) {
        int v;
        scd(v);
        graph[i] = v;
        indeg[v]++;
    }

    queue<int> q;
    forr(i, 1, n+1) {
        if(indeg[i] == 0) q.push(i);
    }
    vb dead(n+1);
    vis = vb(n+1);
    int mi = 0;

    while(q.size()) {
        auto x = q.front();
        q.pop();
        if(!vis[x] && !dead[x]) {
            if(!dead[graph[x]]) {
                mi++;
                dead[graph[x]] = true;
                indeg[graph[graph[x]]]--;
                if(indeg[graph[graph[x]]] == 0) q.push(graph[graph[x]]);
            }

        }
        vis[x] = true;
    }
    forr(i, 1, n+1) {
        if(!vis[i] && !dead[i]) {
            q.push(i);
            while(q.size()) {
                auto x = q.front();
                q.pop();
                if(!vis[x] && !dead[x]) {
                    if(!dead[graph[x]]) {
                        mi++;
                        dead[graph[x]] = true;
                        indeg[graph[graph[x]]]--;
                        if(indeg[graph[graph[x]]] == 0) q.push(graph[graph[x]]);
                    }

                }
                vis[x] = true;
            }

        }
    }
    printf("%d", mi);
}