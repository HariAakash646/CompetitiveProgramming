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
    int n, q;
    scd(n);
    scd(q);

    vll pos(n+2);
    pos[0] = -3e18;
    pos[n+1] = 3e18;
    frange(i, n) sclld(pos[i+1]);

    vll vec(q);

    frange(i, q) sclld(vec[i]);

    map<lli, int> po, ne;
    po[0] = -1;
    ne[0] = -1;

    lli tot = 0;
    frange(i, q) {
        tot += vec[i];
        if(tot >= 0) {
            if(po.find(tot) == po.end())
                po[tot] = i;
        }
        else {
            if(ne.find(abs(tot)) == ne.end()) 
                ne[abs(tot)] = i;
        } 
    }

    int mi = 1e9;
    auto it = po.end();

    while(it != po.begin()) {
        it--;
        lli v = (*it).f;
        mi = min(mi, (*it).s);
        po[v] = mi;
        it = po.find(v);
    }
    it = ne.end();
    mi = 1e9;
    while(it != ne.begin()) {
        it--;
        lli v = (*it).f;
        mi = min(mi, (*it).s);
        ne[v] = mi;
        it = ne.find(v);
    }

    forr(i, 1, n+1) {
        lli lo = pos[i-1];
        lli hi = pos[i];

        while(lo != hi) {
            lli mid = lo+(hi-lo)/2;
            lli pv = mid - pos[i-1];
            lli nv = pos[i] - mid;
            auto it = po.lower_bound(pv+1);
            int v1 = 1e9;
            if(it != po.end()) {
                v1 = (*it).s;
            }
            it = ne.lower_bound(nv);
            int v2 = 1e9;
            if(it != ne.end()) {
                v2 = (*it).s;
            } 
            if(v2 < v1) {
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }
        lli l = lo;

        lo = pos[i];
        hi = pos[i+1];

        while(lo != hi) {
            lli mid = lo+(hi-lo+1)/2;
            lli pv = mid - pos[i];
            lli nv = pos[i+1] - mid;
            auto it = po.lower_bound(pv);
            int v1 = 1e9;
            if(it != po.end()) {
                v1 = (*it).s;
            }
            it = ne.lower_bound(nv+1);
            int v2 = 1e9;
            if(it != ne.end()) {
                v2 = (*it).s;
            } 
            if(v1 < v2) {
                lo = mid;
            }
            else {
                hi = mid-1;
            }
        }
        lli r = lo;
        printf("%lld\n", r-l);
    }
}