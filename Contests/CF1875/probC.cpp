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
    usaco();
    int t;
    scd(t);
    vector<vector<ld>> dp(5001, vector<ld>(5001));
    // vector<vll> dp2(5001, vll(5001));
    
    dp[1][0] = 1;
    dp[2][0] = 0.5;
    dp[2][1] = 0.5;
    forr(i, 3, 5001) {
        // dp[i] = vector<ld>(i);
        dp[i][0] = ld(1)/ld(i);
        // vector<ld> val = dp[i-2];
        forr(j, 1, i) {
            dp[i][j] += (ld(i-j-1)/ld(i)) * dp[i-2][j-1];
            if(j >= 2) {
                dp[i][j] += (ld(j-1)/ld(i)) * dp[i-2][j-2];
            }
        }
    }

    
    // forr(i, 1, 5001) sort(all(dp2[i]), greater<>());
    // lli v = 1;
    // forr(i, 1, 5001) {
    //     forr(j, 0, i) {
    //         dp[i][j] = ld(dp2[i][j]) / (v * i);
    //     }
    //     if(i > 1) v *= (i-1);
    // }

    // frange(i, 10) printf("%Lf ", dp[10][i]);
    frange(_, t) {
        int n, m;
        scd(n);
        scd(m);
        vvi graph(n+1);
        vi indeg(n+1);
        frange(i, m) {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            indeg[b]++;
        }

        queue<int> q;

        forr(i, 1, n+1) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
        vi topo;
        while(q.size()) {
            auto x = q.front();
            q.pop();
            topo.pb(x);
            for(auto e : graph[x]) {
                indeg[e]--;
                if(indeg[e] == 0) q.push(e);
            }
        }
        vector<ld> dpv(n+1);
        dpv[n] = 1;
        for(int i=n-1; i>=1; i--) {
            int x = graph[i].size();
            vector<ld> val(x);
            frange(j, x) {
                val[j] = dpv[graph[i][j]];
            }
            sort(all(val));
            frange(j, x) {
                dpv[i] += val[j] * dp[x][j];
            }
        }
        printf("%Lf\n", dpv[1]);
    }
}