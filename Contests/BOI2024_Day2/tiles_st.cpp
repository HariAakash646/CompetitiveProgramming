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
    int n, m;
    scd(n);
    scd(m);

    vvi grid(m+1, vi(1001));

    pii pre = mp(-1, -1);
    pii fir;

    frange(i, n) {
        int x, y;
        scd(x);
        scd(y);
        if(i) {
            if(pre.s == y) {
                forr(i, min(pre.f, x), max(pre.f, x)) grid[i][y] = 1;
            }
        }
        else fir = mp(x, y);
        pre = mp(x, y);
    }
    int x = fir.f;
    int y = fir.s;
    if(pre.s == y) {
        forr(i, min(pre.f, x), max(pre.f, x)) grid[i][y] = 1;
    }
    set<pii> prs;
    int out = 0;
    frange(i, m) {
        set<pii> st;
        int curr = -1;
        frange(j, 1001) {
            if(grid[i][j]) {
                if(curr == -1) curr = j;
                else {st.insert(mp(curr, j-1)); curr=-1;}
            }
        }
        // seti st2;
        bool done = true;
        for(auto p : prs) {
            auto it = st.upper_bound(mp(p.f, 1e9));
            if(it == st.begin()) {
                // out = i-1;
                done = false;
                break;
            }
            it--;
            if((*it).s < p.s) {
                // out = i-1;
                done = false;
                break;
            }
            auto p1 = *it;
            st.erase(it);
            if(p1.f < p.f) {
                st.insert(mp(p1.f, p.f-1));
            }
            if(p1.s > p.s) {
                st.insert(mp(p.s+1, p1.s));
            }
        }
        if(!done) break;
        for(auto p : st) {
            // printf("%d %d\n", p.f, p.s);
            if((p.s - p.f + 1) % 2) {
                done = false;
                // out = i - (prs.size() != 0);
                break;
            }
        }
        if(!done) break;
        if(st.size() == 0) out = i+1;
        prs = st;
    }

    printf("%d\n", out);


}