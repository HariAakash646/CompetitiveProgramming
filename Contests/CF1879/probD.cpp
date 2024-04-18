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

const lli mod = 998244353;

int main() {
    // usaco();
    
        int n;
        scd(n);
        vi vec(n);
        frange(i, n) scd(vec[i]);
        lli val = 0;
        vi xv(n);
        xv[0] = vec[0];
        forr(i, 1, n) {
            xv[i] = xv[i-1] ^ vec[i];
        }
        frange(i, 31) {
            vll tot1(n+1), tot2(n+1), cnt1(n+1), cnt2(n+1);
            for(int j=n-1; j>=0 ; j--) {
                tot1[j] = tot1[j+1];
                tot2[j] = tot2[j+1];
                cnt1[j] = cnt1[j+1];
                cnt2[j] = cnt2[j+1];
                if(xv[j] & (1<<i)) {
                    tot1[j] += j;
                    cnt1[j]++;
                }
                else {
                    tot2[j] += j;
                    cnt2[j]++;
                }
                tot1[j] %= mod;
                tot2[j] %= mod;
            }
            int curr = 1;

            frange(j, n) {
                if(curr) {
                    val += ((tot1[j] - cnt1[j] * (j-1)) * (1<<i)) % mod;
                }
                else {
                    val += ((tot2[j] - cnt2[j] * (j-1)) * (1<<i)) % mod;
                }
                val %= mod;
                if(vec[j] & (1<<i)) curr = !curr;
            }
        }
        printf("%lld\n", val);
    
}