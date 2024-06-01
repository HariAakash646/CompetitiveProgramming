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

    vii vec(n+1);
    frange(i, n+1) {
        scd(vec[i].f);
        vec[i].s = i;
    }
    sort(all(vec));

    vi sz(n);
    frange(i, n) scd(sz[i]);
    sort(all(sz));

    int ma = 0;
    mseti st;

    frange(i, n) {
        st.insert(vec[i+1].f - sz[i]);
    }

    vi out(n+1);
    out[vec[0].s] = max(0, *prev(st.end()));

    forr(i, 1, n+1) {
        st.erase(st.find(vec[i].f - sz[i-1]));
        st.insert(vec[i-1].f-sz[i-1]);
        out[vec[i].s] = max(0, *prev(st.end()));
    }

    for(auto e : out) printf("%d ", e);
}