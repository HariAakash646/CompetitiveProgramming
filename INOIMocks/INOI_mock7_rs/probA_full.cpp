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
    int n;
    scd(n);

    vi vec(n+1);
    vi pos(n+1);

    forr(i, 1, n+1) {
        scd(vec[i]);
        pos[vec[i]] = i;
    }

    vector<vll> val(n+1, vll(n+1));
    vector<vll> val2(n+1, vll(n+1));
    vll pref(n+1);

    forr(i, 1, n+1) {
        forr(j, 1, n+1) {
            val[i][j] = val[i][j-1];
            // val2[i][j] = val2[i-1][j];
            if(pos[j] > pos[i]) {
                val[i][j]++;
                val2[i][j]++;
            }
        }
        pref[i] = pref[i-1] + val[i][i];
    }

    forr(i, 1, n+1) {
        forr(j, 1, n+1) {
            val2[i][j] = val2[i-1][j] + val[i][j];
        }
    }

    vvi cost(n+1, vi(n+1));
    forr(i, 1, n+1) {
        forr(j, i, n+1) {
            // forr(k, i, j+1) {
            //     cost[i][j] += val[k][i-1] + val[k][j] - val[k][k];
            // }
            cost[i][j] = val2[j][j] - val2[i-1][j] + val2[j][i-1] - val2[i-1][i-1] - (pref[j] - pref[i-1]); 
        }
    }

    vll dp(n+1, 1e17);
    dp[0] = 0;

    forr(i, 1, n+1) {
        frange(j, i) {
            dp[i] = min(dp[i], dp[j] + cost[j+1][i]);
        }
    }
    printf("%lld", dp[n]);
}