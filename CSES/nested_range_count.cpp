#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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

typedef tree<
pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main() {
    // usaco();
    int n;
    scd(n);

    vii vec(n);


    vector<pair<pii, pii>> val;

    frange(i, n) {
        scd(vec[i].f);
        scd(vec[i].s);

        val.pb(mp(mp(vec[i].f, -vec[i].s), mp(0, i)));
        val.pb(mp(mp(vec[i].s, -vec[i].f), mp(1, i)));
    }

    sort(all(val));

    ordered_set st1, st2;
    vi out1(n), out2(n);

    for(auto p : val) {
        if(p.s.f) {
            
            st2.erase(mp(-p.f.s, p.s.s));
            out1[p.s.s] = st1.size() - st1.order_of_key(mp(-p.f.s, 0));
            out2[p.s.s] = st2.order_of_key(mp(-p.f.s, 1e9));
            
            st1.insert(mp(-p.f.s, p.s.s));
        }
        else {
            st2.insert(mp(p.f.f, p.s.s));
        }
    }

    for(auto e : out1) printf("%d ", e);
    printf("\n");

    for(auto e : out2) printf("%d ", e);
    printf("\n");



}