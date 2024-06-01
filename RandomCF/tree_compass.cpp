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

pii dfs(int x, int p) {
    pii pi = mp(0, x);
    for(auto e : graph[x]) {
        if(e != p) {
            pii p1 = dfs(e, x);
            pi = max(pi, mp(p1.f+1, p1.s));
        }
    }
    return pi;
}

vi vec;

bool dfs2(int x, int p, int v) {
    if(x == v) {
        vec.pb(x);
        return true;
    }
    for(auto e : graph[x]) {
        if(e != p) {
            if(dfs2(e, x, v)) {
                vec.pb(x);
                return true;
            }
        }
    }
    return false;
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        graph = vvi(n+1);

        frange(i, n-1) {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }

        int a = dfs(1, 0).s;
        int b = dfs(a, 0).s;
        vec = {};
        dfs2(a, 0, b);
        int sz= vec.size();
        if(sz % 2) {
            printf("%d\n", sz/2+1);
            frange(i, sz/2+1) {
                printf("%d %d\n", vec[sz/2], i);
            }
        }
        else {
            printf("%d\n", sz/2 + (sz%4==2));
            for(int i=1; i<=sz/2; i+=2) {
                printf("%d %d\n", vec[sz/2-1], i);
            }
            for(int i=1; i<=sz/2; i+=2) {
                printf("%d %d\n", vec[sz/2], i);
            }

        }

    }
}