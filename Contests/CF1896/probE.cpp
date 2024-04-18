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

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main() {
    usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        vi vec(n+1);
        vi pos(n+1);
        frange(i, n) {
            scd(vec[i+1]);
            pos[vec[i+1]] = i+1;
        }

        ordered_set st, st2;
        forr(i, 1, n+1) {
            if(vec[i] < i) {
                st.insert(vec[i]);
                st2.insert(i);
            }
        }

        vi out(n+1);

        for(auto e : st) printf("%d ", e);
        printf("\n");
        for(auto e : st2) printf("%d ", e);
            printf("\n");
        vb vis(n+1);
        forr(i, 1, n+1) {
            st.insert(vec[i]); st2.insert(i);
            if(st.find(i) != st.end()) {
                st.erase(i);
                st2.erase(pos[i]);
                vis[i] = true;
                int v = 0;
                if(i >= pos[i]) {
                    v = st2.order_of_key(i) - st2.order_of_key(pos[i]) + st.order_of_key(i) - st.order_of_key(pos[i]);
                }
                else {
                    v = st2.size() - st2.order_of_key(pos[i]) + st2.order_of_key(i) + st.size() - st.order_of_key(pos[i]-1) + st.order_of_key(i+1);
                }
                out[i] = v;
            }
            for(auto e : st) printf("%d ", e);
            printf("\n");
            for(auto e : st2) printf("%d ", e);
            printf("\n");
        }

        forr(i, 1, n+1) printf("%d ", out[i]);
        printf("\n");
    }
}