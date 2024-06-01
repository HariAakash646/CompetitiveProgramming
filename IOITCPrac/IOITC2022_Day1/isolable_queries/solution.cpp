#include <bits/stdc++.h>
using namespace std;

pair<int, int> query(vector<int> S);

// DO NOT CHANGE ANYTHING ABOVE THIS LINE

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

vii edg;
vi rem;

void rec(int x, vi vec, int id) {
    if(vec.size() == 0) return;
    if(vec.size() <= 1) {
        for(auto e : vec) {
            pii p1 = query({x, e, id});
            // printf("vec: %d %d %d %d\n", x, vec[0], id, p1.s);
            if(p1.s == id + e) {
                edg.pb(mp(x, e));
                rem.pb(e);
            }
        }
        
        return;
    }
    vec.pb(x);
    pii p = query(vec);
    vec.pop_back();
    int tot = 0;
    // printf("%d:\n", x);
    for(auto e : vec) {tot += e; }
    // printf("\nv: %d %d\n", tot, p.s);
    if(p.s == tot) {
        int mid = int(vec.size())/2;
        vi lv, rv;
        frange(i, mid) lv.pb(vec[i]);
        forr(i, mid, vec.size()) rv.pb(vec[i]);
        rec(x, lv, id);
        rec(x, rv, id);
    }
}


vector<pair<int, int>> getEdges(int n){
    vb act(n+1, true);

    pii pre = mp(0, 0);
    
    seti leav;
    edg = {};
    frange(i, n-1) {
        vi quer;
        forr(i, 1, n+1) {
            if(act[i]) quer.pb(i);
        }
        pii p = query(quer);
        int a = p.f;
        act[a] = false;
        int id;
        forr(i, 1, n+1) if(act[i]) id = i;
        rem={};
        vi val;
        for(auto e : leav) {
            val.pb(e);
        }
        shuffle(all(val), default_random_engine(time(0)));
        rec(a, val, id);
        for(auto e : rem) leav.erase(e);
        leav.insert(a);
    }
    int id;
    forr(i, 1, n+1) if(act[i]) id = i;
    for(auto e : leav) edg.pb(mp(id, e));
    // for(auto p : edg) {
    //     printf("%d %d\n", p.f, p.s);
    // }
    return edg;
}