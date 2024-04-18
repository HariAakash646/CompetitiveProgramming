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
    int n, m, q;
    scd(n);
    scd(m);
    scd(q);

    map<lli, lli> cnt;

    map<pii, lli> act;
    lli curr = 0;

    frange(i, m) {
        int l, r;
        scd(l);
        scd(r);
        auto it1 = act.lower_bound(mp(l+1, 0));
        if(it1 != act.begin()) {
            it1--;
            auto p = (*it1).f;
            if(!(p.f <= l && l <= p.s)) it1++;
        }
        auto it2 = act.lower_bound(mp(r+1, 0));
        // if(it2 != act.begin()) it2--;
        lli pre = curr;
        vii rem;
        // printf("%d %d %d: \n", i, l, r);
        while(it1 != it2) {
            pii p = (*it1).f;
            lli t = (*it1).s;
            
            if(p.f < l) {
                t += l- p.f;
            }
            curr = pre + (max(p.f, l) - l + 1);
            // printf("%d %d %lld %lld\n", p.f, p.s, t, curr);
            cnt[curr-t] += min(r, p.s) - max(l, p.f) + 1;
            // printf("%lld %d\n", curr-t, min(r, p.s) - max(l, p.f) + 1);
            rem.pb(p);
            it1++;
        }
        curr = pre + (r - l + 1);
        it1 = act.lower_bound(mp(l+1, 0));
        if(it1 != act.begin()) {
            it1--;
            pii p = (*it1).f;
            if(p.f < l && l <= p.s) {
                act[mp(p.f, l-1)] = (*it1).s;
            }
        }

        it2 = act.lower_bound(mp(r+1, 0));
        if(it2 != act.begin()) {
            it2--;
            pii p = (*it2).f;
            if(p.f <= r && r < p.s) {
                act[mp(r+1, p.s)] = (*it2).s + (r+1 - p.f);
            }
        }

        for(auto e : rem) act.erase(e);
        act[mp(l, r)] = pre+1;
    }

    vll val;
    val.pb(0);

    for(auto p : cnt) {
        val.pb(p.f);
    }

    vll pref(val.size());
    forr(i, 1, val.size()) {
        pref[i] = pref[i-1] + cnt[val[i]];
    }

    frange(_, q) {
        lli v;
        sclld(v);
        v++;
        int id = lower_bound(all(val), v) - val.begin();
        printf("%lld\n", pref.back() - pref[id-1]);
    }
}