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

int n, q;
lli d;
vll vec;
vll lef, rig, rig2;
vll suf, sufv;
vll val, out;
vector<pair<int, pii>> quer;

void rec(int l, int r, vector<pair<int, pii>> quer) {
    if(l > r) return;
    if(l == r) {    
        for(auto p : quer) {
            out[p.f] = 0;
        }
        return;
    }
    int mid = (l + r)/2;
    lef[mid] = 0;
    val[mid] = vec[mid];
    sufv[mid] = suf[mid] = 0;
    map<lli, int> mv;
    mv[0] = mid;
    for(int i=mid-1; i>=l; i--) {
        if(vec[i] > val[i+1]) {
            lef[i] = lef[i+1] + ((vec[i] - val[i+1] + d - 1) / d);
            val[i] = vec[i] - ((vec[i] - val[i+1] + d - 1) / d) * d;
        }
        else {
            val[i] = vec[i];
            lef[i] = lef[i+1];
        }
        suf[i] = suf[i+1] + (val[i+1] - val[i])/d;
        sufv[i] = sufv[i+1] + suf[i];
        mv[suf[i]] = i;
    }
    rig[mid] = 0;
    rig[mid+1] = 0;
    rig2[mid+1] = 0;
    val[mid+1] = vec[mid+1];
    for(int i=mid+2; i<=r; i++) {
        if(vec[i] < vec[i-1]) {
            rig2[i] = rig2[i-1] + ((vec[i-1] - vec[i] + d - 1) / d);
            rig[i] = rig[i-1] + ((vec[i-1] - vec[i] + d - 1) / d) * (i - mid - 1);
        }
        else {
            val[i] = vec[i];
            rig[i] = rig[i-1];
            rig2[i] = rig2[i-1];
        }
    }

    vector<pair<int, pii>> lv, rv;

    for(auto p : quer) {
        if(p.s.f <= mid && p.s.s > mid) {
            lli tot = lef[p.s.f] + rig[p.s.s];
            lli v = 0;
            // printf("%d %d:  ", p.s.f, p.s.s);
            // printf("%lld %lld ", lef[p.s.f], rig[p.s.s]);
            lli v1 = vec[mid+1] - d * rig2[p.s.s];
            if(val[mid] > v1) {
                lli dif = (val[mid] - v1 + d - 1) / d;
                auto it = mv.upper_bound(dif);
                it--;
                int id = max(p.s.f, (*it).s);
                if(id == p.s.f) {
                    v = dif - suf[id];
                }
                tot += dif * (mid - id + 1) - sufv[id];
                // printf("%lld %lld %lld ", v, dif, sufv[id]);
            }
            // printf("\n");
            if(val[p.s.f] - v * d >= 0)
                out[p.f] = tot;
            else out[p.f] = -1;
        }
        else if(p.s.s <= mid) {
            lv.pb(p);
        }
        else {
            rv.pb(p);
        }
    }

    if(lv.size()) rec(l, mid, lv);
    if(rv.size()) rec(mid+1, r, rv);

}

int main() {
    // usaco();
    scd(n);
    sclld(d);

    vec = vll(n+1);
    bool zer = true;
    forr(i, 1, n+1) {
        sclld(vec[i]);
        if(vec[i] > 1) zer = false;
    }

    scd(q);
    quer = vector<pair<int, pii>>(q);

    frange(i, q) {
        quer[i].f = i;
        scd(quer[i].s.f);
        scd(quer[i].s.s);
    }

    if(n <= 3000 && q <= 3000) {
        for(auto p : quer) {
            int l = p.s.f;
            int r  = p.s.s;
            lli tot = 0;
            vll val = vec;
            bool done = true;
            for(int i=r-1; i>=l; i--) {
                if(vec[i] > val[i+1]) {
                    tot += (vec[i] - val[i+1] + d-1)/d;
                    val[i] = vec[i] - (vec[i] - val[i+1] + d-1)/d * d;
                    if(val[i] < 0) done = false;
                }
            }
            if(done)
            printf("%lld\n", tot);
            else printf("-1\n");
        }
    }
    else if(zer) {
        vll pref(n+1);
        vll zero(n+1, -1);
        forr(i, 1, n+1) {
            pref[i] = pref[i-1] + vec[i];
            if(vec[i] == 0) zero[i] = i;
            else zero[i] = zero[i-1];
        }

        for(auto p : quer) {
            int l = p.s.f;
            int r  = p.s.s;
            int z = zero[r];
            lli v = 0;
            if(z >= l) v = max(0LL, pref[z] - pref[l-1]);
            if(v && d > 1) printf("-1\n");
            else printf("%lld\n", v);
            
        }
    }
    else {rig2 = sufv = lef = rig = val = suf = vll(n+1);
        out = vll(q);
        rec(1, n, quer);
    
        frange(i, q) printf("%lld\n", out[i]);}
}