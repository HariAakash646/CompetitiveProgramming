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

vvi lift;
vvi graph;

int binlift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) x = lift[i][x];
    }
    return x;
}

int main() {
    // usaco();
    int n, qu;
    scd(n);
    scd(qu);

    graph = vvi(n+1);
    lift = vvi(20, vi(n+1));

    vi indeg(n+1);

    forr(i, 1, n+1) {
        int a;
        scd(a);
        lift[0][i] = a;
        graph[a].pb(i);
        indeg[a]++;
    }

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    queue<int> q;

    forr(i, 1, n+1) {
        if(indeg[i] == 0) q.push(i);
    }

    vb cyc(n+1, true);

    while(q.size()) {
        int x = q.front();
        q.pop();
        cyc[x] = false;

        indeg[lift[0][x]]--;
        if(indeg[lift[0][x]] == 0) q.push(lift[0][x]);
    }

    int idx = 1;
    vi pos(n+1);
    vi sze(n+1);

    vi depth(n+1);

    forr(i, 1, n+1) {
        if(cyc[i] && !pos[i]) {
            pos[i] = idx;
            depth[i] = 0;
            int d = 1;
            int p = i;
            while(lift[0][p] != i) {
                p = lift[0][p];
                pos[p] = idx;
                depth[p] = d++;
            }
            sze[idx] = d;
            idx++;
        }
    }

    forr(i, 1, n+1) {
        if(!cyc[i] && cyc[lift[0][i]]) {
            queue<int> q;
            q.push(i);

            int p = pos[lift[0][i]];

            depth[i] = 0;
            while(q.size()) {
                int x = q.front();
                q.pop();
                pos[x] = p;
                
                for(auto e : graph[x]) {
                    q.push(e);
                    depth[e] = depth[x] + 1;
                }
            }
        }
    }

    frange(_, qu) {
        int a, b;
        scd(a);
        scd(b);

        if(cyc[a] && !cyc[b] || pos[a] != pos[b]) {
            printf("-1\n");continue;
        }
        if(cyc[a] && cyc[b]) {
            if(depth[b] >= depth[a]) printf("%d\n", depth[b] - depth[a]);
            else {
                printf("%d\n", depth[b] + sze[pos[a]] - depth[a]);
            }
        }
        else if(!cyc[a] && cyc[b]) {
            int a2 = binlift(a, depth[a]+1);
            int v = depth[a]+1;
            if(depth[b] >= depth[a2]) printf("%d\n", v + depth[b] - depth[a2]);
            else {
                printf("%d\n", v + depth[b] + sze[pos[a2]] - depth[a2]);
            }
        }
        else {
            int a2 = binlift(a, depth[a] - depth[b]);
            // printf("%d %d %d %d\n", a, b, a2, depth[a] - depth[b]);
            if(depth[a] - depth[b] >= 0 && a2 == b) {
                printf("%d\n", depth[a] - depth[b]);
            }
            else printf("-1\n");
        }
    }



}