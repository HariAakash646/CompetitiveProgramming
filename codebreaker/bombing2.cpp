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

vvi graph;
vi num, lowpt;
int timer = 0;
stack<pii> stk;
vi cnt;
vb curr;

void dfs(int x, int y) {
    num[y] = ++timer;
    lowpt[y] = num[y];
    for(auto e : graph[y]) {
        if(e == x) continue;
        if(num[e] && num[e] < num[y]) {
            lowpt[y] = min(lowpt[y], num[e]);
            stk.push(mp(y, e));
        }
        else if(!num[e]) {
            stk.push(mp(y, e));
            dfs(y, e);
            lowpt[y] = min(lowpt[y], lowpt[e]);
        }
    }

    if(x != -1 && lowpt[y] >= num[x]) {
        vi vert;
        while(stk.top() != mp(x, y)) {
            // printf("%d %d\n", stk.top().f, stk.top().s);
            vert.pb(stk.top().f);
            vert.pb(stk.top().s);
            stk.pop();
        }
        // printf("%d %d\n", stk.top().f, stk.top().s);
        vert.pb(stk.top().f);
        vert.pb(stk.top().s);
        stk.pop();
        // printf("*******************\n");
        for(auto e : vert) {
            if(!curr[e]) cnt[e]++;
            curr[e] = true;
        }
        for(auto e : vert) curr[e] = false;
    }
}

int main() {
    // usaco();
    int n, e;
    scd(n);
    scd(e);
    graph = vvi(n);

    frange(i, e) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    curr = vb(n);
    cnt = num = lowpt = vi(n);
    dfs(-1, 0);
    printf("%d", *max_element(all(cnt)));
}