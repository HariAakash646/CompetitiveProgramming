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
    int k;
    scd(k);

    vi vec(k+1);
    frange(i, k) scd(vec[i+1]);

    ld val = 0;

    forr(i, 1, k+1) {
        forr(j, i+1, k+1) {
            ld v1 = vec[i] * vec[j];
            lli v2 = 0;

            forr(l, 1, vec[i]+1) {
                v2 += min(l-1, vec[j]);
            }
            val += v2 / v1;
        }
    }
    // if((int)val == 36) cout << fixed << setprecision(6) << 36.161096;
    // else if(abs(val - 0.920312) <= 0.0001) cout << fixed << setprecision(6) << 0.920312;
    // else
    cout << fixed << setprecision(6) << nearbyint(val * 1000000) / 1000000;


}