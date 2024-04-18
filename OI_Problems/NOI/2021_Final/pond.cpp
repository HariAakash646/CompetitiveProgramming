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
    usaco();
    int n, k;
    scd(n);
    scd(k);
    vll vec(n);

    forr(i, 1, n) {
        lli v;
        sclld(v);
        vec[i] = vec[i-1] + v;
    }
    if(n <= 2000){
    
        vector<vll> dp1(n, vll(n, 1e18));
        vector<vll> dp2(n, vll(n, 1e18));
        k--;
        dp1[k][k] = dp2[k][k] = 0;
        forr(i, 1, n) {
            for(int j=0; j+i<n; j++) {
                int k = j + i;
                dp1[j][k] = min(dp1[j+1][k] + (n - (k - j)) * (vec[j+1] - vec[j]), dp2[j+1][k] + (n - (k - j)) * (vec[k] - vec[j]));
                dp2[j][k] = min(dp1[j][k-1] + (n - (k - j)) * (vec[k] - vec[j]), dp2[j][k-1] + (n - (k - j)) * (vec[k] - vec[k-1]));
            }
        }
        printf("%lld", min(dp1[0][n-1], dp2[0][n-1]));}
    else {
        
        lli v1 = 0;
        forr(i, k, n) {
            v1 += vec[i] - vec[k-1];
        }
        for(int i=k-2; i>=0; i--) {
            v1 += vec[n-1] - vec[i] + vec[n-1] - vec[i];
        }
        lli v2 = 0;
        for(int i=k-2; i>=0; i--) {
            v2 += vec[k-1] - vec[i];
        }
        forr(i, k, n) {
            v2 += vec[k-1] - vec[0] + vec[i] - vec[0];
        }
        printf("%lld", min(v1, v2));
    }
}