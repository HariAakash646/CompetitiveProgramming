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
    int t;
    scd(t);

    frange(_, t) {
        int n, q;
        scd(n);
        scd(q);
        vi vec(n);

        int tot = 0;
        frange(i, n) {
            scd(vec[i]);
            tot += vec[i];
        }
        vi po(tot+1, 1);
        forr(i, 1, tot+1) po[i] = 3 *po[i-1];

        vvi dp(n, vi(po[tot], -1));

        frange(i, tot-vec[0]+1) {
            int v = 0;
            forr(j, i, i+vec[0]) v += po[j];
            dp[0][v] = vec[0];
        }

        forr(i, 1, n) {
            frange(j, po[tot]) {
                if(dp[i-1][j] != -1) {
                    int v = j;

                    frange(k, tot - vec[i] + 1) {
                        int vt = v;
                        int vt2 = v;
                        int c = 0;
                        frange(l, k) vt2 /= 3;
                        forr(l, k, k+vec[i]) {
                            if(vt2 % 3 == 0) {
                                vt += po[l];
                                // c++;
                            }
                            else if(vt2 % 3 == 1) {
                                vt += po[l];
                                // c--;
                            }
                            vt2 /= 3;
                        }
                        vt2 = vt;
                        frange(l, tot) {
                            if(vt2%3==1) c++;
                            vt2/=3;
                        }
                        dp[i][vt] = c;
                    }
                }
            }
        }
        // frange(i, po[tot]) {
        //     int v = i;
        //     frange(j, tot) {
        //         printf("%d ", v%3);
        //         v /= 3;
        //     }
        //     printf(": %d\n", dp[n-1][i]);
        // }
        vi out(tot+1, 1e9);
        frange(i, po[tot]) {
            if(dp[n-1][i] != -1) {
                int c = tot;
                int v = i;
                while(v%3==0 && c > 0) {
                    c--;
                    v/=3;
                }
                out[dp[n-1][i]] = min(out[dp[n-1][i]], c);
            }
        }

        frange(_, q) {
            lli r, k;
            sclld(r);
            sclld(k);
            if(out[k] <= r) printf("YES\n");
            else printf("NO\n");
        }
    }
}