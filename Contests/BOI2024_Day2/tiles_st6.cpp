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
    usaco();
    int n, m;
    scd(n);
    scd(m);

    map<int, set<pii>> mv;

    pii pre = mp(-1, -1);
    pii fir;

    frange(i, n) {
        int x, y;
        scd(x);
        scd(y);
        if(i) {
            if(pre.f == x) {
                mv[x].insert(mp(min(pre.s, y), max(pre.s, y)));
            }
        }
        else fir = mp(x, y);
        pre = mp(x, y);
    }
    int x = fir.f;
    int y = fir.s;
    if(pre.f == x) {
        mv[x].insert(mp(min(pre.s, y), max(pre.s, y)));
    }
    set<pii> act;
    int out = m;
    frange(i, m+1) {
        for(auto p : mv[x]) {
            auto it = act.upper_bound(mp(p.f, 1e9));
            if(it == act.begin()) {
                act.insert(p);
                continue;
            }
            it--;
            if((*it).s <= p.f) {
                act.insert(p);
                continue;
            }
            auto p1 = *it;
            act.erase(it);
            if(p1.f < p.f) {
                act.insert(mp(p1.f, p.f-1));
            }
            if(p1.s > p.s) {
                act.insert(mp(p.s+1, p1.s));
            }
        }
        auto it = act.begin();
        while(it != prev(act.end())) {
            auto p = *it;
            auto p1 = *next(it);
            if(p.s == p1.f-1) {
                act.erase(it);
                act.erase(p1);
                p1 = mp(p.f, p1.s);
                act.insert(p1);
            }
            it = act.find(p1);
        }
        bool done = true;
        for(auto p : act) {
            if((p.s - p.f + 1) % 2) {
                out = i;
                done = false;
                break;
            }
        }
        if(!done) break;
    }

    printf("%d\n", out);


}