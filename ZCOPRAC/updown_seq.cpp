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
        int n;
        scd(n);

        vi vec(n);

        frange(i, n) scd(vec[i]);

        vi dph(n), dpl(n);
        dpl[0] = 1;

        forr(i, 1, n) {
            if(vec[i] >= vec[i-1]) {
                dph[i] = dpl[i-1] + 1;
            }
            // else dph[i] = 1;
            if(vec[i] <= vec[i-1]) {
                dpl[i] = dph[i-1] + 1;
            }
            else dpl[i] = 1;
        }

        vi dp2h(n), dp2l(n);
        dp2h[n-1] = 1;
        dp2l[n-1] = 1;

        for(int i=n-2; i>=0; i--) {
            if(vec[i] >= vec[i+1]) {
                dp2h[i] = dp2l[i+1] + 1;
            }
            else dp2h[i] = 1;
            if(vec[i] <= vec[i+1]) {
                dp2l[i] = dp2h[i+1] + 1;
            }
            else dp2l[i] = 1;
        }

        int ma = *max_element(all(dpl));
        ma = max(ma, *max_element(all(dph)));

        frange(i, n-1) {
            ma = max(ma, dpl[i] + dp2l[i+1] + 1);
            ma = max(ma, dph[i] + dp2h[i+1] + 1);
        }
        printf("%d\n", ma);
    }
}