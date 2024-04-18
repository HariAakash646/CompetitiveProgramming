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

const lli mod = 1000007;

lli dpl[2][10010];

int main() {
    // usaco();
    int n;
    scd(n);

    vi vec(n+1);
    frange(i, n) scd(vec[i+1]);

    frange(i, n+1) {
        dpl[0][i] = dpl[1][i] = 0;
    }

    int ma = 0;

    forr(i, 1, n+1) {
        forr(j, 1, n+1) {
            dpl[1][j] = (dpl[0][j-1] + dpl[0][j] * j) % mod;
        }
        if(vec[i] > ma) {
            dpl[1][ma] += ma;
            dpl[1][ma] %= mod;
            forr(j, ma+1, vec[i]) {
                dpl[1][j]++;
                dpl[1][j] %= mod;
            }
            ma = vec[i];
        }
        else {
            dpl[1][ma] += vec[i]-1;
            dpl[1][ma] %= mod;
        }
        forr(j, 0, n+1) dpl[0][j] = dpl[1][j]; 
    }
    lli tot = 0;

    forr(i, 1, n+1) tot += dpl[0][i];
    tot %= mod;
    printf("%lld", (tot+1)%mod);
}