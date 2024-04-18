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
        vll vec(4*n);
        vll dp1(4*n, 1e18);
        frange(i, 4*n) sclld(vec[i]);
        multiset<lli> st;
        lli tot = 0;
        frange(i, n) {
            st.insert(vec[i]);
            tot += vec[i];
        }

        dp1[n-1] = tot;
        forr(i, n, 4*n) {
            if(vec[i] < *prev(st.end())) {
                tot -= *prev(st.end());
                tot += vec[i];
                st.erase(prev(st.end()));
                st.insert(vec[i]);
            }
            dp1[i] = tot;
        }

        vll dp2(4*n, -1e18);
        st = {};
        tot = 0;
        for(int i=4*n-1; i>=3*n; i--) {
            st.insert(vec[i]);
            tot += vec[i];
        } 
        dp2[3*n] = tot;

        for(int i=3*n-1; i>=0; i--) {
            if(vec[i] > *st.begin()) {
                tot -= *st.begin();
                tot += vec[i];
                st.erase(st.begin());
                st.insert(vec[i]);
            }
            dp2[i] = tot;
        }

        lli out = -1e18;

        frange(i, 3*n-1) {
            // printf("%lld %lld\n", dp1[i], dp2[i+n+1]);
            out = max(out, dp2[i+n+1]- dp1[i]);
        }

        printf("%lld\n", out);

    }
}