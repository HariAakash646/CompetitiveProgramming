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
vi dp1, dp2, dp3, dp4;

void dfs(int x, int p) {
    int c = 0;
    mseti st, st1, st2, st3;
    int val1 = 0;
    for(auto e : graph[x]) {
        if(e != p) {
            c++;
            dfs(e, x);
            dp1[x] += max({dp1[e], dp2[e], dp3[e]});
            dp2[x] += dp2[e]-1;
            dp3[x] += dp2[e]-1;
            dp4[x] += dp2[e]-1;
            st.insert(max(dp1[e] - (dp2[e]-1), (dp3[e]-1) - (dp2[e]-1)));            
            st1.insert((dp4[e]-1) - (dp2[e]-1));            
            val1 += dp1[e];
        }
    }
    if(st.size()) dp3[x] += *prev(st.end());
    else dp3[x] = -1e9;

    lli v1 = -1e9;
    lli v2 = -1e9;
    if(st.size() >= 2) {
        v1 = *prev(st.end()) + *prev(prev(st.end()));
    }
    if(st1.size()) {
        v2 = *prev(st1.end());
    }
    // if(c == 1) dp3[x] = max(dp3[x], val1);
    // if(c == 2) dp4[x] = max(dp4[x], val1);
    dp3[x]++;
    dp4[x] += max(v1, v2);
    dp4[x]++;
    // if(c == 0) dp2[x] = 1;
    dp2[x]++;
}

int main() {
    // usaco();
    int t, x;
    scd(t);
    scd(x);

    frange(_, t) {
        int n;
        scd(n);

        n++;

        graph = vvi(n+1);

        forr(i, 2, n+1) {
            int a, b;
            scd(a);
            graph[a].pb(i);
            graph[i].pb(a);
        }

        dp1 = dp2 = dp3 = dp4 = vi(n+1);
        dfs(1, 0);

        printf("%d\n", max({dp1[1], dp2[1], dp3[1], dp4[1]}));
    }
}