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
    usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, k;
        lli p;
        scd(n);
        scd(k);
        sclld(p);

        vector<vector<vll>> dp1(n, vector<vll>(k+1, vll(k+1)));
        vector<vector<vll>> prf1(n, vector<vll>(k+1, vll(k+1)));
        frange(i, k+1) {
            dp1[0][i][0] = 1;
            prf1[0][i][0] = 1;
            forr(j, 1, k+1) {
                prf1[0][i][j] = 1;
            }
        }

        forr(i, 1, n) {
            forr(j, 0, k+1) {
                forr(l, 0, k+1) {
                    // if(j == l) {
                    //     if(l > 0) {
                    //         prf1[i][j][l] = prf1[i][j][l-1];
                    //     }
                    //     continue;
                    // }
                    int li = max(0, l-j);
                    int ri = k;
                    dp1[i][j][l] = prf1[i-1][l][ri];
                    if(li > 0) {
                        dp1[i][j][l] -= prf1[i-1][l][li-1];
                        dp1[i][j][l] +=p;
                        dp1[i][j][l] %= p;
                    }
                    prf1[i][j][l] = dp1[i][j][l];
                    if(l > 0) {
                        prf1[i][j][l] += prf1[i][j][l-1];
                        prf1[i][j][l] %= p;
                    }
                }
            }
        }

        vector<vector<vll>> dp2(n, vector<vll>(k+1, vll(k+1)));
        vector<vector<vll>> prf2(n, vector<vll>(k+1, vll(k+1)));
        frange(i, k+1) {
            dp2[n-1][i][0] = 1;
            prf2[n-1][i][0] = 1;
            forr(j, 1, k+1) {
                prf2[n-1][i][j] = 1;
            }
        }

        for(int i=n-2; i>=0; i--) {
            forr(j, 0, k+1) {
                forr(l, 0, k+1) {
                    int li = max(0, l-j);
                    int ri = k;
                    dp2[i][j][l] = prf2[i+1][l][ri];
                    if(li > 0) {
                        dp2[i][j][l] -= prf2[i+1][l][li-1];
                        dp2[i][j][l] +=p;
                        dp2[i][j][l] %= p;
                    }
                    prf2[i][j][l] = dp2[i][j][l];
                    if(l > 0) {
                        prf2[i][j][l] += prf2[i][j][l-1];
                        prf2[i][j][l] %= p;
                    }
                }
            }
        }

        lli tot = 0;
        frange(i, n-1) {
            frange(j, k+1) {
                lli v1 = 0;
                frange(l, k+1) {
                    v1 += dp1[i][j][l];
                    v1 %= p;
                }
                lli v2 = 0;
                frange(l, k+1) {
                    v2 += dp2[i+1][j][l];
                    v2 %= p;
                }
                // tot += (prf1[i][j][k] * prf2[i+1][j][k]) % p;
                tot += (v1 * v2);
                tot %= p;
            }
        }
        frange(j, k+1) {
            frange(l, k+1) {
                tot += prf1[n-1][j][l];
                tot %= p;
            }
        }
        printf("%lld\n", tot);
    }
}