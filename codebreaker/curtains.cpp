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

int n, m, q;
vvi vec, vec2;

vector<pair<int, pii>> quer;
vb out;
vi lef, rig;

void dnc(int l, int r, vector<pair<int, pii>> quer) {
    if(l == r) {
        for(auto p : quer) {
            if(binary_search(all(vec[l]), r)) out[p.f] = true;
        }
        return;
    }
    int mid = (l+r)/2;
    forr(i, l, mid+1) lef[i] = r+1;
    forr(i, mid+1, r+1) rig[i] = l-1;
    deque<int> stk;
    for(int i=mid; i>=l; i--) {
        auto it = lower_bound(all(vec[i]), mid);
        int v1 = -1;
        if(it != vec[i].end()) {
            v1 = *it;
        }
        int v2 = -1;
        if(it != vec[i].begin()) {
            v2 = *prev(it);
        }
        if(v1 != -1)
            lef[i] = v1;
        if(v2 != -1) {
            while(stk.size() && stk.back() <= v2+1) {
                lef[i] = min(lef[i], lef[stk.back()]);
                stk.pop_back();
            }
        }
        stk.push_back(i);
    } 

    stk = {};

    for(int i=mid+1; i<=r; i++) {
        auto it = upper_bound(all(vec2[i]), mid+1);
        int v2 = -1;
        if(it != vec2[i].end()) {
            v2 = *it;
        }
        int v1 = -1;
        if(it != vec2[i].begin()) {
            v1 = *prev(it);
        }
        
        if(v1 != -1)
            rig[i] = v1;
        if(v2 != -1) {
            while(stk.size() && stk.back() >= v2-1) {
                rig[i] = max(rig[i], rig[stk.back()]);
                stk.pop_back();
            }
        }
        stk.push_back(i);
    } 

    vector<pair<int, pii>> lv1, rv1;

    for(auto p : quer) {
        if(p.s.f <= mid && p.s.s > mid) {
            // printf("%d %d %d %d\n", p.s.f, p.s.s, lef[p.s.f], rig[p.s.s]);
            if(lef[p.s.f] <= p.s.s && rig[p.s.s] >= p.s.f) out[p.f] = true;
        }
        else {
            if(p.s.s <= mid) lv1.pb(p);
            else rv1.pb(p);
        }
    }
    if(l <= mid)
        if(lv1.size()) dnc(l, mid, lv1);
    if(r >= mid+1)
        if(rv1.size()) dnc(mid+1, r, rv1);

}

int main() {
    // usaco();
    scd(n);
    scd(m);
    scd(q);

    vec2 = vec = vvi(n+1);

    frange(i, m) {
        int l, r;
        scd(l);
        scd(r);
        vec[l].pb(r);
        vec2[r].pb(l);
    }

    forr(i, 1, n+1) {sort(all(vec[i])); sort(all(vec2[i]));}

    quer = vector<pair<int, pii>>(q);
    frange(i, q) {
        quer[i].f = i;
        scd(quer[i].s.f);
        scd(quer[i].s.s);
    }
    out = vb(q);
    lef = rig = vi(n+1);
    dnc(1, n, quer);

    frange(i, q) {
        if(out[i]) printf("YES\n");
        else printf("NO\n");
    }

}