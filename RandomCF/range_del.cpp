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
    int n, x;
    scd(n);
    scd(x);

    vi vec(n);
    frange(i, n) scd(vec[i]);
    
    seti st;
    vi ma(x+1, -1), mi(x+1, x+1);

    frange(i, n) {
        int v = vec[i];
        if(st.size() && *prev(st.end()) > v) {
            ma[v] = max(ma[v], *prev(st.end()));
            mi[v] = min(mi[v], *st.upper_bound(v));
        }
        st.insert(v);
    }
    
    int id=1;
    int mv = 1e9;
    forr(i, 1, x+1) {
        if(ma[i] != -1) id = i;
    }
    lli tot = 0;
    forr(i, 1, x+1) {
        if(mv < i) break;
        tot += x-id+1;
        mv = min(mv, mi[i]);
        id = max({id, ma[i], i+1});
    }
    printf("%lld", tot);


}