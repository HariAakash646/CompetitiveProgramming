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
    int n, q;
    scd(n);
    scd(q);

    vii vec(n);
    frange(i, n) {
        scd(vec[i].s);
        scd(vec[i].f);
    }

    sort(all(vec), greater<>());

    vvi lift(21, vi(1e6+2));
    lift[0][1e6+1] = 1e6+1;

    int mi = 1e6+1;
    set<pii> st;
    for(auto p : vec) st.insert(mp(p.s, p.f));
    for(int i=1e6; i>=1; i--) {
        while(st.size() && (*prev(st.end())).f >= i) {
            mi = min(mi, (*prev(st.end())).s);
            st.erase(prev(st.end()));
        }
        lift[0][i] = mi;
        
    }

    forr(i, 1, 21) {
        forr(j, 1, 1e6+2) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    frange(_, q) {
        int a, b;
        scd(a);
        scd(b);
        int c = 0;
        // printf("%d ", a);
        for(int i=20; i>=0; i--) {
            int at = lift[i][a];
            // printf("%d ", at);
            if(at <= b) {
                c += (1<<i);
                a = at;
            }
        } 
        printf("%d\n", c);
    }

}