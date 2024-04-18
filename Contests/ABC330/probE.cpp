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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);

    seti st;
    vi cnt(n+2);

    forr(i, 0, n+1) st.insert(i);
    vi vec(n);
    frange(i, n) {
        int a;
        scd(a);
        vec[i] = a;
        if(a <= n+1) cnt[a]++;
    }

    frange(i, n+2) {
        if(cnt[i]) st.erase(i);
    }

    frange(_, q) {
        int id, v;
        scd(id);
        scd(v);
        id--;
        if(vec[id] <= n+1) {
            cnt[vec[id]]--;
            if(cnt[vec[id]] == 0) st.insert(vec[id]);
        }
        vec[id] = v;
        if(v <= n+1) {
            cnt[v]++;
            if(cnt[v] == 1) st.erase(v);
        }
        printf("%d\n", *st.begin());
    }
}