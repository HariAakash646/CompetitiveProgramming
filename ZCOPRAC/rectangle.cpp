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

    vii vec(n);

    frange(i, n) {
        scd(vec[i].s);
        scd(vec[i].f);
    }

    sort(all(vec));

    seti st;
    mseti ma;
    st.insert(0);
    st.insert(1e5);
    ma.insert(1e5);

    int mav = 0;
    int id = 0;
    forr(i, 1, 501) {
        while(id < n && vec[id].f < i) {
            auto it = st.upper_bound(vec[id].s);
            int v = *it - *prev(it);
            ma.erase(ma.find(v));
            ma.insert(*it - vec[id].s);
            ma.insert(vec[id].s - *prev(it));
            st.insert(vec[id].s);
            id++;
        }
        mav = max(mav, i * *prev(ma.end()));

    }
    printf("%d", mav);

}