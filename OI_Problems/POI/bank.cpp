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
    vi val(n+1);
    vi cnt(n+1);
    forr(i, 1, n+1) scd(val[i]);
    forr(i, 1, n+1) scd(cnt[i]);
    int k;
    scd(k);
    vi dp(20001, 1e9);
    dp[0] = 0;
    vvi dpc(20001, vi(n+1, 0));

    forr(i, 1, 20001) {
        int id = -1;
        forr(j, 1, n+1) {
            int v = val[j];
            int c = cnt[j];
            if(i - v >= 0) {
                if(dpc[i-v][j] < c && dp[i-v] + 1 < dp[i]) {
                    id = j;
                    dp[i] = dp[i-v] + 1;
                }
            }
        }
        if(id != -1)
        {   dpc[i] = dpc[i-val[id]];
            dpc[i][id]++;
        }
    }
    cout << dp[k] << "\n";
    forr(i, 1, n+1) cout << dpc[k][i] << " ";
}