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

int n;
lli m;
vvi vec;
set<pii> st;

bool check(int x) {
    lli tot = 0;
    lli v = n;
    frange(i, n) {
        for(auto e : vec[i]) {
            auto it = st.upper_bound(mp(e, 1e9));
            if(it != st.begin()) {
                it--;
                pii p = *it;
                if(p.s - p.f + 1 >= x) v -= (p.s - p.f + 1);
                pii p1 = mp(p.f, e-1);
                pii p2 = mp(e+1, p.s);
                if(p1.s - p1.f + 1 >= x) v += p1.s - p1.f + 1;
                if(p2.s - p2.f + 1 >= x) v += p2.s - p2.f + 1;
                st.erase(it);
                if(p1.s >= p1.f)
                    st.insert(p1);
                if(p2.s >= p2.f)
                    st.insert(p2);
            }
        }
        tot += v;
    }
    return tot >= m;
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        
        scd(n);
        vec = vvi(n+1);

        forr(i, 1, n+1) {
            int a;
            scd(a);
            vec[n-a].pb(i);
        }

        sclld(m);

        int lo = 1;
        int hi = n;

        while(lo != hi) {
            int mid = (lo + hi+1)/2;
            st = {};
            st.insert(mp(1, n));

            if(check(mid)) lo = mid;
            else hi = mid-1;
        }

        st = {};
        st.insert(mp(1, n));
        int x = lo;
        lli tot = 0;
        lli v = n;
        lli ck = 0;
        int cv = 0;
        int cnt = 1;
        frange(i, n) {
            for(auto e : vec[i]) {
                auto it = st.upper_bound(mp(e, 1e9));
                if(it != st.begin()) {
                    it--;
                    pii p = *it;
                    if(p.s - p.f + 1 >= x) {v -= (p.s - p.f + 1);cnt--;}
                    pii p1 = mp(p.f, e-1);
                    pii p2 = mp(e+1, p.s);
                    if(p1.s - p1.f + 1 > x) {v += p1.s - p1.f + 1; cnt++;}
                    if(p2.s - p2.f + 1 > x) {v += p2.s - p2.f + 1; cnt++;}
                    if(p1.s - p1.f + 1 == x) cv++;
                    if(p2.s - p2.f + 1 == x) cv++;
                    st.erase(it);
                    if(p1.s >= p1.f)
                        st.insert(p1);
                    if(p2.s >= p2.f)
                        st.insert(p2);
                }
            }
            if(ck + v <= m)
                tot += v-cnt;
            else {
                auto it = prev(st.end());
                while(ck < m) {
                    if((*it).s - (*it).f + 1 <= x) break;
                    tot += min(m - ck, lli((*it).s - (*it).f + 1)) - 1;
                    ck += lli((*it).s - (*it).f + 1);
                    it--;
                }
                break;
            }
            ck += v;
        }
        tot += (m - ck) - (m - ck + x - 1) / x; 
        printf("%lld\n", tot);

    }
}