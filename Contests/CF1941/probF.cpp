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
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int main() {
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n, m, k;
        scd(n);
        scd(m);
        scd(k);
        vll vec(n);
        frange(i, n) {
            sclld(vec[i]);
        }
        pair<lli, lli> ma = {0, 0};
        forr(i, 1, n) {
            ma = max(ma, mp(vec[i] - vec[i-1], lli(i)));
        }

        vll dv(m), fv(k);
        frange(i, m) sclld(dv[i]);
        frange(j, k) sclld(fv[j]);
        sort(all(dv));
        sort(all(fv));

        lli v = (vec[ma.s] + (lli)vec[ma.s-1])/2;
        pair<lli, lli> mi = mp(2e9+5, 2e9+10);
        for(auto e : dv) {  
            auto it = upper_bound(all(fv), v-e);
            if(it != fv.end()) {
                mi = min(mi, mp(abs(e+*it - v), e + *it));
            }
            if(it != fv.begin()) {
                it--;
                mi = min(mi, mp(abs(e+*it - v), e + *it));
            }
        }
        lli out = ma.f;
        vll og = vec;
        vec.pb(mi.s);
        sort(all(vec));
        lli ma2 = 0;
        forr(i, 1, n+1) {
            ma2 = max(ma2, vec[i] - vec[i-1]);
        }
        out = min(out, ma2);
        vec = og;
        v = (vec[ma.s] + vec[ma.s-1]+1)/2;
        mi = mp(2e9+5, 2e9+10);
        for(auto e : dv) {  
            auto it = upper_bound(all(fv), v-e);
            if(it != fv.end()) {
                mi = min(mi, mp(abs(e+*it - v), e + *it));
            }
            if(it != fv.begin()) {
                it--;
                mi = min(mi, mp(abs(e+*it - v), e + *it));
            }
        }
        
        vec.pb(mi.s);
        sort(all(vec));
        ma2 = 0;
        forr(i, 1, n+1) {
            ma2 = max(ma2, vec[i] - vec[i-1]);
        }
        out = min(out, ma2);
        printf("%lld\n", out);
    }
}