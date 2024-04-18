#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
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

lli mod = 998244353;

typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main() {
    // usaco();
    int n;
    scd(n);
    vi vec(n);
    vb vis(1e5+1);
    frange(i, n) {
        scd(vec[i]);
        vis[vec[i]] = true;
    }
    vi val(1e5+1);
    vi cnt(1e5+1);

    forr(e, 1, n+1) {

        for(int i=2*e; i<=n; i+=e) {
            vec[e-1] = max(vec[e-1], vec[i-1]); 
        }
    }

    // frange(i, n) {
    //     vec[i] = max(vec[i], val[i+1]);
    // }
    sort(all(vec));
    vll pow2(n+1);
    pow2[0] = 1;
    forr(i, 1, n+1) pow2[i] = (2 * pow2[i-1]) % mod;

    priority_queue<int> pq;
    vector<lli> dp(n);
    lli tot = 0;
    // frange(i, n) st.pb(val[vec[i]]);
    // sort(all(st));
    vis = vb(1e5+1);
    frange(i, n) {
        // while(pq.size() && -pq.top() <= vec[i]) pq.pop();
        tot += vec[i] * pow2[i];
        tot %= mod;
        // pq.push(-vec[i]);
    }
    
    // forr(i, 0, n) {
    //     tot += dp[i] * vec[i];
    //     tot %= mod;
    // }
    printf("%lld", tot);
}