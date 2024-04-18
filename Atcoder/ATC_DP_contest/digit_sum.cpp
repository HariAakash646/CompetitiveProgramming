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

const lli mod = 1e9 + 7;

int main() {
    string str;
    int d;
    cin >> str >> d;

    int n = str.size();

    vector<vll> dp1(n+1, vll(d)), dp2(n+1, vll(d));

    dp1[0][0] = 1;

    frange(i, n) {
        frange(j, d) {
            dp1[i+1][(j+(str[i] - '0')) % d] = dp1[i][j];
            dp1[i+1][(j+(str[i] - '0')) % d] %= mod;
            frange(k, 10) {
                int v = (j+k)%d;
                dp2[i+1][v] += dp2[i][j];
                if(k < (str[i] - '0')) {
                    dp2[i+1][v] += dp1[i][j];
                }
                dp2[i+1][v] %= mod;
            }
            // printf("%d ", dp2[i][j]);
        }
        // printf("\n");
    }

    printf("%lld", (dp2[n][0] + dp1[n][0] - 1 + mod) % mod);

}