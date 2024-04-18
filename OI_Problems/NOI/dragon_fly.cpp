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

vi cnt, sp, bug;

vvi graph;

vi vec;
vi out;
int c = 0;

void dfs(int x, int p) {
    vec[sp[x]]++;
    if(vec[sp[x]] == 1) c++;
    out[x] = c;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
        }
    }
    vec[sp[x]]--;
    if(vec[sp[x]] == 0) c--;
}

vi par;

void dfs_init(int x, int p) {
    par[x] = p;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs_init(e, x);
        }
    }
}

void dfs_up(int x) {
    if(x== 0) return;
    if(cnt[x]) {
        cnt[x]--;
        vec[sp[x]]++;
        if(vec[sp[x]] == 1) c++;
    }
    dfs_up(par[x]);
}

int main() {
    // usaco();
    int n, d;
    scd(n);
    scd(d);

    cnt = sp = vi(n+1);
    forr(i, 1, n+1) scd(cnt[i]);
    forr(i, 1, n+1) scd(sp[i]);

    bug = vi(d+1);
    forr(i, 1, d+1) {
        scd(bug[i]);
    }

    graph = vvi(n+1);
    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    if(n <= 1000 && d <= 1000) {
        par = vi(n+1);
        dfs_init(1, 0);

        forr(i, 1, d+1) {
            vec = vi(n+1);
            c = 0;
            dfs_up(bug[i]);
            printf("%d\n", c);
        }
    }
    else {
        vec = out = vi(n+1);
        dfs(1, 0);
    
        forr(i, 1, d+1) {
            printf("%d\n", out[bug[i]]);
        }
    }

}