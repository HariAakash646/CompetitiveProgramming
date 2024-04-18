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
    cin >> t;

    frange(_, t) {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;

        vvi cnt0(n+1, vi(n+1, 1e9)), cnt1(n+1, vi(n+1, 1e9));
        vi pre(n+1);

        forr(i, 1, n+1) {
            pre[i] = pre[i-1] + (str[i-1] - '0');
        }

        forr(i, 1, n+1) {
            forr(j, i, n+1) {
                cnt0[i][j] = (j - i + 1) - (pre[j] - pre[i-1]);
                cnt1[i][j] = pre[j] - pre[i-1];
            }
        }

        vvi pref(n+2, vi(n+2, 1e9)), suf(n+2, vi(n+2, 1e9));

        forr(i, 0, n+1) {
            pref[0][i] = 0;
            suf[0][i] = 0;
        }

        forr(i, 1, n+1) {
            forr(j, i, n+1) {
                pref[i][j] = min(pref[i][j-1], cnt0[j-i+1][j]);
            }
        }

        forr(i, 1, n+1) {
            for(int j=n-i+1; j>=1; j--) {
                suf[i][j] = min(suf[i][j+1], cnt0[j][j+i-1]);
            }
        }

        vi val(n+1, -1e9);

        forr(i, 1, n+1) {
            forr(j, 1, n+1) {
                if(suf[i][j] <= k) val[0] = i;
                if(pref[i][j] <= k) val[0] = i;
            }
        }

        forr(i, 1, n+1) {
            forr(j, i, n+1) {
                int v = k - cnt1[i][j];
                if(v < 0) continue;
                int lo = 0;
                int hi = n;

                while(lo != hi) {
                    int mid = (lo + hi+1)/2;
                    int x = min(pref[mid][i-1], suf[mid][j+1]);
                    if(x <= v) lo = mid;
                    else hi = mid-1;
                }
                // printf("%d %d %d %d\n", i, j, v, lo);
                val[j-i+1] = max(val[j-i+1], lo);
            }
        }

        forr(j, 1, n+1) {
            lli v = 0;
            forr(i, 0, n+1) {
                if(val[i] >= 0)
                    v = max(v, lli(i)*j + val[i]);
            }
            printf("%lld ", v);
        }
        printf("\n");
        
    }
}