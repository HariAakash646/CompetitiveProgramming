#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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
    usaco();
    fastio();
    int t;
    cin >> t;
    frange(_, t) {
        string str;
        cin >> str;
        int n = str.size();
        vvi dp(n, vi(3, -1e9));
        
        dp[0][str[0]-'A'] = 0;

        forr(i, 1, n) {
            dp[i][str[i]-'A'] = *max_element(all(dp[i-1]));
            if(str[i] == 'B') {
                dp[i][2] = max(dp[i][2], dp[i-1][0] + 1);
            }
            if(str[i] == 'A') {
                dp[i][1] = max(dp[i][1], dp[i-1][1]+1);
            }
        }
        printf("%d\n", *max_element(all(dp[n-1])));
    }
}