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
    set<pii> st;

    forr(i, 1, n+1) {
        int a;
        scd(a);
        if(a > 0)
            st.insert(mp(a, i));
    }
    vii out;
    while(st.size()) {
        auto p = *prev(st.end());
        st.erase(prev(st.end()));

        
        vii er;

        if(st.size() < p.f) {
            printf("IMPOSSIBLE");
            return 0;
        } 
        auto it = prev(st.end());
        frange(i, p.f) {
            out.pb(mp(p.s, (*it).s));
            er.pb(*it);
            it--;

        }

        for(auto p : er) {
            st.erase(p);

            if(p.f - 1 > 0) st.insert(mp(p.f-1, p.s));
        }

    }
    printf("%d\n", (int)out.size());
    for(auto p : out) printf("%d %d\n", p.f, p.s);
}