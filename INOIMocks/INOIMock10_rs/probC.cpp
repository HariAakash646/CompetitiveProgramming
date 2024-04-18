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

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int n, m;

vector<vector<pair<int, lli>>> graph;
// vll dp;

vector<lli> dfs(int x) {
    if(x > n) {
        vector<lli> vec(301, 1e16);
        vec[0] = 0;
        return vec;
    }
    lli tot = 0;
    vll vec(301, 0);
    for(auto e : graph[x]) {
        auto v = dfs(e.f);
        forr(i, 0, 301) {
            lli mi = 1e16;
            forr(j, 0, i+1) {
                mi = min(mi, abs(j+e.s-i) + v[j]);
            }
            vec[i] += mi;
        }
    }
    return vec;
}

int main() {
    // usaco();
    
    scd(n);
    scd(m);

    // graph = vector<vector<pair<int, lli>>>(n+1);

    vll vec;

    forr(i, 1, m+1) {
        int pa;
        lli c;
        scd(pa);
        sclld(c);
        vec.pb(c);
    }
    sort(all(vec));
    // vll out = dfs(1);

    // lli mi = 1e16;
    // forr(i, 0, 301) mi = min(mi, out[i]);

    // printf("%lld", *min_element(all(dfs(1))));
    lli mi = 0;
    lli v = vec[m/2];

    for(auto e : vec) mi += abs(e-v);
    printf("%lld", mi);
}