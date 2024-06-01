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

int n, m;
vii vec;
vi sz;

bool check(int x) {
    mseti st;
    int id = 0;
    int ma = 0;
    for(int i=x-1; i>=0; i--) {
        int v = sz[i];
        while(id < n && vec[id].f <= v) {
            if(vec[id].s >= ma)
                st.insert(vec[id].s);
            id++;
        }
        if(!st.size()) return false;
        // printf("%d %d\n", i, *st.begin());
        ma = max(ma, *st.begin());
        st.erase(st.begin());
    }
    return true;

}

int main() {
    // usaco();
    scd(n);
    scd(m);
    vec = vii(n);
    sz = vi(m);

    frange(i, n) {
        scd(vec[i].f);
        scd(vec[i].s);
    }

    frange(i, m) {
        scd(sz[i]);
    }

    sort(all(vec));
    sort(all(sz), greater<>());

    int lo = 0;
    int hi = m;

    while(lo != hi) {
        int mid = (lo+hi+1)/2;
        // printf("%d %d\n", lo, hi);
        if(check(mid)) {
            lo = mid;
        }
        else {
            hi = mid-1;
        }
    }
    printf("%d\n", lo);
}