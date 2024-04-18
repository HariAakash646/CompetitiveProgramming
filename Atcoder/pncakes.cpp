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
    // freopen("disrupt.in", "r", stdin);
    // freopen("disrupt.out", "w", stdout);
}

int main() {
    usaco();
    int n;
    scd(n);
    int pre;
    scd(pre);
    vii vec(n-1);
    lli tot = 0;
    frange(i, n-1) {
        int a;
        scd(a);
        tot += abs(a - pre);
        vec[i] = mp(pre, a);
        pre = a;
    }
    sort(all(vec));
    mseti st;
    int ma = 0;
    for(auto p : vec) {
        // while(st.size() && (*st.begin()) < p.f) {
        //     st.erase(st.begin());
        // }
        if(st.size()) {
            int v = *prev(st.end());
            ma = max(ma, abs(v -p.f));
        }
        st.insert(p.s);
    }
    printf("%lld", tot - 2 * ma);
}