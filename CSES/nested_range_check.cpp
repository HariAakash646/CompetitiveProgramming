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
    int n;
    scd(n);

    vii vec(n);

    // vii st(n), en(n);

    vector<pair<pii, pii>> val;

    frange(i, n) {
        scd(vec[i].f);
        scd(vec[i].s);
        // st[i] = mp(vec[i].f, i);
        // en[i] = mp(vec[i].s, i);

        val.pb(mp(mp(vec[i].f, -vec[i].s), mp(0, i)));
        val.pb(mp(mp(vec[i].s, -vec[i].f), mp(1, i)));
    }

    sort(all(val));

    set<pii> st1, st2;
    vi out1(n), out2(n);

    for(auto p : val) {

        if(p.s.f) {
            auto it = st1.find(mp(-p.f.s, p.s.s));
            if(it != st1.end()) st1.erase(it);
            st2.erase(mp(-p.f.s, p.s.s));
            it = st1.upper_bound(mp(-p.f.s, 1e9));
            vii er;
            while(it != st1.begin()) {
                it--;
                out1[(*it).s] = 1;
                er.pb(*it);
                // printf("%d %d\n", p.s.s, (*it).s);
            }
            for(auto e : er) st1.erase(e);
            it = st2.upper_bound(mp(-p.f.s, 1e9));
            if(it != st2.begin()) {
                out2[p.s.s] = 1;
            }
            
            
        }
        else {
            st1.insert(mp(p.f.f, p.s.s));
            st2.insert(mp(p.f.f, p.s.s));
        }
    }

    frange(i, n) printf("%d ", out1[i]);
    printf("\n");
    for(auto e : out2) printf("%d ", e);


}