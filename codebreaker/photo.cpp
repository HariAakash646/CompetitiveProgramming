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
    int n, c;
    scd(n);
    scd(c);
    if(n == 1) {
        printf("0");
        return 0;
    }
    int out = 1e9;
    vvi vec(n, vi(c));

    frange(i, n) {
        frange(j, c) scd(vec[i][j]);
        sort(all(vec[i]));
    }
    vi idx(n);
    set<pii> st;
    frange(i, n) st.insert(mp(vec[i][0], i));

    while(true) {
        auto p = *st.begin();
        st.erase(st.begin());
        out = min(out, (*prev(st.end())).f - p.f);
        if(idx[p.s] == c-1) break;
        idx[p.s]++;
        st.insert(mp(vec[p.s][idx[p.s]], p.s));
    }

    printf("%d", out);
}