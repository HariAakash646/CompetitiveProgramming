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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, k;
        scd(n);
        scd(k);

        vector<vll> vec(n, vll(n));

        frange(i, n) {
            forr(j, i, n) sclld(vec[i][j]);
        }

        vector<vll> dp(n+2, vll(k, -1e16)), pref(n+2, vll(k, -1e16));
        pref[n][0] = pref[n+1][0] = 0;


        for(int i=n-1; i>=0; i--) {
            priority_queue<pair<lli, pii>> st;
            forr(j, i, n) {
                st.push(mp(pref[j+2][0] + vec[i][j], mp(j, 0)));
            }
            frange(j, k) {
                auto p = st.top();
                st.pop();
                dp[i][j] = p.f;
                // printf("%d %d %lld\n", i, j, dp[i][j]);
                if(j < k-1)
                    st.push(mp(pref[p.s.f + 2][p.s.s+1] + vec[i][p.s.f], mp(p.s.f, p.s.s+1)));
            }
            int i1 = 0, i2 = 0;
            frange(j, k) {
                // printf("%lld %lld\n", dp[i][i1], pref[i+1][i2]);
                if(dp[i][i1] > pref[i+1][i2]) {
                    pref[i][j] = dp[i][i1];
                    i1++;
                }
                else {
                    pref[i][j] = pref[i+1][i2];
                    i2++;
                }
            }
        }

        frange(i, k) printf("%lld ", pref[0][i]);
        printf("\n");
    }
}