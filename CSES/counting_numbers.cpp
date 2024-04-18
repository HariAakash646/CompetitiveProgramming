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

lli dp[19][10][2];

lli fun(lli v) {
    frange(i, 19) {
        frange(j, 10) {
            frange(k, 2) dp[i][j][k] = 0;
        }
    }
    if(v < 0) return 0;
    if(v == 0) return 1;
    vi vec;
    frange(i, 19) {
        vec.pb((v%10));
        v /= 10;
    }
    reverse(all(vec));
    int zer = 0;
    frange(i, 19) {
        if(vec[i] != 0) {
            zer = i;
            break;
        }
    }

    dp[zer][vec[zer]][0] = 1;
    frange(i, vec[zer]) dp[zer][i][1] = 1;
    forr(i, zer, 19) dp[i][0][1] = 1;

    forr(i, zer+1, 19) {
        frange(j, 10) {
            lli tot0 = 0;
            lli tot1 = 0;
            frange(k, 10) {
                if(j != k) tot0 += dp[i-1][k][0];
                if(j != k) tot1 += dp[i-1][k][1];
            }
            if(j == vec[i]) {
                
                dp[i][j][0] += tot0;
            }
            if(j < vec[i]) dp[i][j][1] += tot0 + tot1;
            else dp[i][j][1] += tot1;
        }
    }
    lli tot = 0;
    frange(j, 10) tot += dp[18][j][0] + dp[18][j][1];
    return tot;
}

int main() {
    lli l, r;
    sclld(l);
    sclld(r);

    printf("%lld", fun(r) - fun(l-1));


}