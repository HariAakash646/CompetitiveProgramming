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
    int t ;
    scd(t);

    frange(_, t) {
        int n, k;
        scd(n);
        scd(k);

        vector<char> str(n);
        frange(i, n) cin >> str[i];

        vvi prefx(3, vi(n+1)), prefz(3, vi(n+1));

        forr(i, 1, n+1) {
            frange(j, 3) 
            {
                prefx[j][i] = prefx[j][i-1];
                prefz[j][i] = prefz[j][i-1];
            }
            if(str[i-1] == 'X') prefx[i%3][i]++;
            if(str[i-1] == 'Z') prefz[i%3][i]++;
        }

        lli curr = 0;

        forr(i, 1, k+1) {
            if(str[i-1] == 'Z') curr += prefx[(i+1)%3][i];
        }

        lli ma = curr + lli(prefz[0][n] - prefz[0][k]) * prefx[1][k] + lli(prefz[1][n] - prefz[1][k]) * prefx[2][k] + lli(prefz[2][n] - prefz[2][k]) * prefx[0][k];

        forr(i, k+1, n+1) {
            if(str[i-1] == 'Z') curr += prefx[(i+1)%3][i];
            if(str[i-k-1] =='Z') curr -= prefx[(i-k+1)%3][i-k];
            // printf("%d %lld\n", curr, lli(prefz[0][n] - prefz[0][i]) * prefx[0][i] + lli(prefz[1][n] - prefz[1][i]) * prefx[1][i] + lli(prefz[2][n] - prefz[2][i]) * prefx[2][i]);
            ma = min(ma, curr + lli(prefz[0][n] - prefz[0][i]) * prefx[1][i] + lli(prefz[1][n] - prefz[1][i]) * prefx[2][i] + lli(prefz[2][n] - prefz[2][i]) * prefx[0][i]);
        }
        printf("%lld\n", ma);
    }

}