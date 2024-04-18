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
    lli l;
    scd(n);
    sclld(l);
    vector<lli> vec(n+1), tim(n+1);
    frange(i, n) {
        sclld(vec[i+1]);
    }
    frange(i, n) {
        sclld(tim[i+1]);
    }
    tim[0] = -1;

    vector<vector<vll>> dp1(n+1, vector<vll>(n+1, vll(n+1, 2e18+5))), dp2(n+1, vector<vll>(n+1, vll(n+1, 2e18+5)));
    dp1[0][0][0] = dp2[0][0][0] = 0;
    forr(le, 1, n+1) {
        forr(j, 0, n+1) {
            int k = (j + le) % (n+1);
            int i = 0;
            dp1[j][k][i] = min(dp1[(j+1)%(n+1)][k][i] + (vec[(j+1) % (n+1)] - vec[j] + l) % l, dp2[(j+1) % (n+1)][k][i] + (vec[k] + l - vec[j]) % l);
            dp2[j][k][i] = min(dp1[j][(k-1+n+1)%(n+1)][i] + (l - vec[j] + vec[k]) % l, dp2[j][(k-1+n+1)%(n+1)][i] + (vec[k] + l - vec[(k-1+n+1)%(n+1)]) % l);

        }
    }

    forr(i, 1, n+1) {
        forr(le, 1, n+1) {
            forr(j, 0, n+1) {
                int k = (j + le) % (n+1);
                
                dp1[j][k][i] = min(dp1[(j+1)%(n+1)][k][i] + (vec[(j+1) % (n+1)] - vec[j] + l) % l, dp2[(j+1) % (n+1)][k][i] + (vec[k] + l - vec[j]) % l);
                if(dp1[(j+1)%(n+1)][k][i-1] + (vec[(j+1) % (n+1)] - vec[j] + l) % l <= tim[j]) {
                    dp1[j][k][i] = min(dp1[j][k][i], dp1[(j+1)%(n+1)][k][i-1] + (vec[(j+1) % (n+1)] - vec[j] + l) % l);
                }
                if(dp2[(j+1) % (n+1)][k][i-1] + (vec[k] + l - vec[j]) % l <= tim[j]) {
                    dp1[j][k][i] = min(dp1[j][k][i], dp2[(j+1) % (n+1)][k][i-1] + (vec[k] + l - vec[j]) % l);
                }

                dp2[j][k][i] = min(dp1[j][(k-1+n+1)%(n+1)][i] + (l - vec[j] + vec[k]) % l, dp2[j][(k-1+n+1)%(n+1)][i] + (vec[k] + l - vec[(k-1+n+1)%(n+1)]) % l);

                if(dp1[j][(k-1+n+1)%(n+1)][i-1] + (l - vec[j] + vec[k]) % l <= tim[k]) {
                    dp2[j][k][i] = min(dp2[j][k][i], dp1[j][(k-1+n+1)%(n+1)][i-1] + (l - vec[j] + vec[k]) % l);
                }
                if(dp2[j][(k-1+n+1)%(n+1)][i-1] + (vec[k] + l - vec[(k-1+n+1)%(n+1)]) % l <= tim[k]) {
                    dp2[j][k][i] = min(dp2[j][k][i], dp2[j][(k-1+n+1)%(n+1)][i-1] + (vec[k] + l - vec[(k-1+n+1)%(n+1)]) % l);
                }
            }
        }
    }
    for(int v=n; v>= 0; v--) {
        frange(i, n+1) {
            frange(j, n+1) {
                if(dp1[i][j][v] < 2e18+5 || dp2[i][j][v] < 2e18+5) {
                    printf("%d\n", v);
                    return 0;
                }
            }
        }
    }
}