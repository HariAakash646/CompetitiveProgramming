#include <bits/stdc++.h>
 
using namespace std;
 
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;
 
void usaco()
{
    // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
    freopen("tallbarn.in", "r", stdin);
   freopen("tallbarn.out", "w", stdout);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n;
lli k;
vll vec;

bool check(ld val) {
    lli tot = 0;
    frange(i, n) {
        ld v = (sqrt(1 + 4 * ld(vec[i]) / val) - 1) / 2;
        tot += lli(v) + lli(v - ld(lli(v)) > 0.01);
    }
    return tot <= k;
}

int main() {
    usaco();
    // fastio();
    scd(n);
    sclld(k);
    vec = vll(n);
    frange(i, n) sclld(vec[i]);

    ld lo = 0;
    ld hi = 1e18;

    frange(_, 200) {
        ld mid = (hi + lo)/2;
        if(check(mid)) {
            hi = mid;
        }
        else lo = mid;
    }
    vll out(n);
    lli tot = 0;
    ld val = lo;
    // cout << val << "\n";
    frange(i, n) {
        ld v = (sqrt(1 + 4 * ld(vec[i]) / val) - 1) / 2;
        tot += lli(v) + lli(v - ld(lli(v)) > 0.01);
        out[i] = lli(v) + lli(v - ld(lli(v)) > 0.01);
        // printf("%lld ", out[i]);
        
    }
    lli d = k - tot;
    
    ld ans = 0;
    frange(i, n) {
        ans += ld(vec[i]) / ld(out[i]);
    }
    ans -= d * val;
    cout << lli(ans) + lli(ans - ld(lli(ans)) > 0.5);
}