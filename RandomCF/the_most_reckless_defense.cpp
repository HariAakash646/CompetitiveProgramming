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


vii grid;

vll process(lli x, lli y, lli p) {
    lli ma = 0;
    lli h = 1;
    vll out;
    forr(r, 1, 13) {
        h *= 3;
        int c = 0;
        for(auto pi : grid) {
            if((x-pi.f) * (x-pi.f) + (y-pi.s)*(y-pi.s) <= r*r) {
                c++;
            }
        } 
        out.pb(c*p-h);
        // printf("%lld ", ma);
    }
    return out;
}

int main() {
    // usaco();
    fastio();   
    int t;
    cin >> t;

    frange(_, t) {
        int n, m, k;
        cin >> n >> m >> k;
        grid = {};
        forr(i, 1, n+1) {
            string row;
            cin >> row;
            forr(j, 1, m+1) {
                if(row[j-1]=='#') grid.pb(mp(i, j));
            }
        }
        lli tot = 0;
        vector<vll> val;
        frange(_, k) {
            lli x, y, p;
            cin >> x >> y >> p;
            val.pb(process(x, y, p));
            // printf("\n");
        }
        vector<vll> dp(k, vll(1<<12));
        frange(i, 12) {
            dp[0][1<<i] = val[0][i];
            // cout << val[0][i] << "\n";
        }
        forr(i, 1, k) {
            frange(j, 1<<12) {
                dp[i][j] = dp[i-1][j];
                frange(l, 12) {
                    if(j&(1<<l)) {
                        dp[i][j] = max(dp[i][j], dp[i-1][j^(1<<l)] + val[i][l]);
                    }
                }
            }
        }
        cout << *max_element(all(dp[k-1])) << "\n";
    }

}