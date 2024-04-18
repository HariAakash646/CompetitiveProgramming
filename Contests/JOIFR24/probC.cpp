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
    int n, l;
    scd(n);
    scd(l);

    map<int, int> mv;

    frange(i, n) {
        int x;
        scd(x);
        mv[x]++;
    }

    int q;
    scd(q);

    frange(_, q) {
        int st, en;
        lli t;
        scd(st);
        scd(en);
        sclld(t);

        auto it = mv.lower_bound(en);
        auto curr = mv.begin();
        vii lv, rv;
        while(curr != it) {
            lv.pb(*curr);
            curr++;
        } 

        curr = mv.end();
        while(curr != it) {
            curr--;
            rv.pb(*curr);
        }

        int sz = lv.size() + rv.size();

        

        bool done = false;

        frange(i, 1<<sz) {
            if(__builtin_popcount(i) != lv.size()) continue;
            lli tot = 0;
            lli c = 1;
            int i1 = 0;
            int i2 = 0;
            int pos = st;
            frange(j, sz) {
                if(i & (1<<j)) {
                    auto p = lv[i1];
                    tot += abs(pos - p.f) * c + p.s;
                    c += p.s;
                    pos = p.f;
                    i1++;
                }
                else {
                    auto p = rv[i2];
                    tot += abs(pos - p.f) * c + p.s;
                    c += p.s;
                    pos = p.f;
                    i2++;
                }
            }
            tot += abs(pos - en) * c;
            if(tot <= t) {
                done = true;
                break;
            }
        }
        if(done) printf("Yes\n");
        else printf("No\n");
    }
}