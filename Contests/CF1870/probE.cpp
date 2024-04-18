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
    freopen("input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int main() {
    usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n;
        scd(n);
        vi vec(n+1);
        frange(i, n) {
            scd(vec[i+1]);
        }
        
        vector<vb> dp(n+1, vb(1<<13));
        dp[0][0] = true;
        vvi mex(n+1, vi(n+1));
        vector<vi> pos(n+1, vi(n+2, 1e9));
        seti val;
        forr(i, 1, n+1) {
            vb pres(n+2, true);
            int me = 0;
            forr(j, i, n+1) {
                pres[vec[j]] = false;
                if(vec[j] == me) {
                    forr(k, me+1, n+2) {
                        if(pres[k]) {
                            me = k;
                            break;
                        }
                    }
                } 
                mex[i][j] = me;
                val.insert(me);
                pos[i][me] = min(pos[i][me], j);
            }
        }
        
        forr(i, 0, n) {
            vi v1;
            frange(j, 1<<13) {
                dp[i+1][j] = dp[i+1][j] || dp[i][j];
                if(dp[i][j]) v1.pb(j);
            } 
            vi rem;
            for(auto e : val) {
                if(pos[i+1][e] != 1e9) {
                    rem.pb(e);
                    for(auto j : v1)
                        dp[pos[i+1][e]][j ^ e] = true;
                }
            }
            for(auto e : rem) {
                val.erase(e);
            }
        }
        int ma = 0;
        frange(i, 1<<13) {
            if(dp[n][i]) ma = i;
        }
        printf("%d\n", ma);
    }
}