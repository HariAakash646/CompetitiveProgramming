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
        ld v = ld(vec[i]) / val;
        tot += lli(v) + lli(1 * (v - ld(lli(v)) > 0.01));
    }
    return tot <= k;
}

int main() {
    // usaco();
    // fastio();
    scd(n);
    sclld(k);
    vec = vll(n);
    frange(i, n) sclld(vec[i]);

    ld lo = 0.1;
    ld hi = 1e12;

    while(hi - lo > 0.1) {
        ld mid = (hi + lo)/2;
        if(check(mid)) {
            lo = mid;
        }
        else hi = mid;
    }
    vll out(n);
    lli tot = 0;
    priority_queue<pair<ld, int>> pq;
    ld val = lo;
    frange(i, n) {
        ld v = ld(vec[i]) / val;
        out[i] = lli(v) + lli(1 * (v - ld(lli(v)) > 0.001));
        tot += out[i];
        
    }
    lli d = k - tot;
    frange(i, n) {
        out[i] += d / n;
    }
    d %= n;
    frange(i, n) {
        pq.push(mp(ld(vec[i])/ld(out[i]) - ld(vec[i])/ ld(out[i]+1), i));
    }
    frange(_, d) {
        auto p = pq.top();
        pq.pop();
        int i = p.s;
        out[p.s]++;
        pq.push(mp(ld(vec[i])/ld(out[i]) - ld(vec[i])/ ld(out[i]+1), i));
    }
    ld ans = 0;
    frange(i, n) {
        ans += ld(vec[i]) / ld(out[i]);
    }
    cout << lli(ans) + lli(ans - ld(lli(ans)) > 0.5);
}