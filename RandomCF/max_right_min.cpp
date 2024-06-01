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
    stack<int> sti, sta;
    vi vec(n+1);

    set<pii> st;
    lli tot = 0;
    lli curr = 0;

    st.insert(mp(0, 0));

    forr(i, 1, n+1) {
        scd(vec[i]);
        st.insert(mp(i, 0));
        st.insert(mp(i, 1));
        while(sta.size() && vec[sta.top()] <= vec[i]) {
            int id = sta.top();
            auto it = st.find(mp(id, 0));
            if((*next(it)).s == 1) curr += id - (*prev(it)).f;
            st.erase(it);
            sta.pop();
        }
        while(sti.size() && vec[sti.top()] >= vec[i]) {
            int id = sti.top();
            auto it = st.find(mp(id, 1));
            if((*next(it)).s == 0) curr -= id - (*prev(it)).f;
            st.erase(it);
            sti.pop();
        }
        sta.push(i);
        sti.push(i);
        tot += curr;
        
    }
    printf("%lld", tot);
}