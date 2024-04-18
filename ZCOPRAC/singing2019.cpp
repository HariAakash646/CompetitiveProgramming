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
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        vii vec;
        vii pow(n);
        frange(i, n) {
            int l, r;
            scd(l);
            scd(r);
            vec.pb(mp(l, i));
            vec.pb(mp(r, i));
            pow[i] = mp(l, r);
        }

        sort(all(vec));

        set<pii> st;
        vi out(n);
        seti rem;
        seti ns;
        for(auto p : pow) ns.insert(p.f);
        frange(i, vec.size()) {
            auto p = vec[i];
            auto it = st.lower_bound(mp(p.s, 0));
            if(it != st.end() && (*it).f == p.s) {
                out[p.s] += i - (*it).s-1;
                out[p.s] += ns.size();
                rem.insert(pow[p.s].s);
                st.erase(it);
            }
            else {
                st.insert(mp(p.s, i));
                out[p.s] += rem.size();
                ns.erase(pow[p.s].f);
            }
        }
        for(auto e : out) printf("%d ", e);
        printf("\n");
    }
}