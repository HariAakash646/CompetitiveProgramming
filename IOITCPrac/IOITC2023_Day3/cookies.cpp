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

vii v2;


int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, q;
        scd(n);
        vii v1
        v2={};

        frange(i, n) {
            int x, y;
            scd(x);
            scd(y);
            if(x <= y) v1.pb(mp(x, y));
            else v2.pb(mp(y, x));

        }

        sort(all(v1));
        sort(all(v2), greater<>());
        


        scd(q);
        frange(i, q) {
            lli e;
            int k;
            sclld(e);
            scd(k);
            bool yes = true;
            for(auto p : v1) {
                if(p.f <= e) {e += p.s - p.f;k--;}
            }
            if(k<=0) {
                printf("YES\n");
                continue;
            }
            int sz = v2.size();


            forr(i, 1, sz+1) {
                frange(j, k+1) {
                    dp[i][j] = dp[i-1][j];
                    if(j > 0 && dp[i-1][j-1] >= v2[i-1].s) {
                        dp[i][j] = max(dp[i][j], dp[i-1][j-1] + v2[i-1].f - v2[i-1].s);
                    }
                }
            }

            if(dp[sz][k] >= 0) printf("YES\n");
            else printf("NO\n");
        }
    }
}