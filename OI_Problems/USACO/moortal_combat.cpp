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
    // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
    freopen("cowmbat.in", "r", stdin);
   freopen("cowmbat.out", "w", stdout);
}

int main() {
    usaco();
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);
    string str;
    cin >> str;
    vvi dist(m, vi(m));
    frange(i, m) {
        frange(j, m) scd(dist[i][j]);
    }

    frange(k, m) {
        frange(i, m) {
            frange(j, m) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vvi pref(m, vi(n+1));

    frange(i, m) {
        frange(j, n) {
            pref[i][j+1] = pref[i][j] + dist[int(str[j]-'a')][i];
        }
    }

    vector<int> stk(m, 1e9);
    vi dp(n+1,1e9);
    dp[0] = 0;

    forr(i, k, n+1) {
        frange(j, m) {
            int v = dp[i-k] - pref[j][i-k];
            stk[j] = min(stk[j], v);
            dp[i] = min(dp[i], stk[j]+pref[j][i]);
        }
    }
    printf("%d", dp[n]);
}