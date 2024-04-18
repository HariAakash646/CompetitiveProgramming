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
typedef unsigned long long int lli;
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

lli dist(long long x1, long long y1, long long x2, long long y2) {
    return lli((x2 - x1) * (x2 - x1)) + (y2 - y1) * (y2-y1);
}

int main() {
    // usaco();
    int n;
    scd(n);

    map<int, vi> mv;

    frange(i, n) {
        int x, y;
        scd(y);
        scd(x);
        mv[x].pb(y);
    }

    for(auto &p : mv) sort(all(p.s));

    auto it = mv.begin();

    lli d = 8e18;

    for(; it!=mv.end(); it++) {
        int x = (*it).f;
        vi st = (*it).s;

        

        frange(i, st.size()) {
            long long v = sqrtl(d);
            int y = st[i];

            auto it2 = it;

            for(; ; it2--) {   
                
                v = sqrtl(d);
                int x1 = (*it2).f;
                if(x1 <= x - v-1) break;

                auto it1 = lower_bound(all((*it2).s), y);
    
                // for(; it1!=(*it2).s.end(); it1++) {   
                //     int y1 = *it1;

                //     if(x1 == x && y1 == y) continue;
        
                //     if(y1 > y + v) break;
        
                //     d = min(d, dist(x, y, x1, y1));
                //     v = sqrt(d);
                // }
                if(it1 != (*it2).s.begin()) {
                    int y1 = *prev(it1);
                    d = min(d, dist(x, y, x1, y1));
                }
                if(x != x1) {
                    if(it1 != (*it2).s.end()) {
                        int y1 = *(it1);
                        d = min(d, dist(x, y, x1, y1));
                    }
                }
                else {
                    if(it1 < prev((*it2).s.end())) {
                        it1++;
                        int y1 = *(it1);
                        d = min(d, dist(x, y, x1, y1));
                        
                    }
                }
                if(it2==mv.begin()) break;
            }
        }
    }

    cout << d;
}