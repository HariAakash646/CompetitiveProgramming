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
    usaco();
    int n, c;
    scd(n);
    scd(c);

    mpii mv;
    seti v1, v2;
    vii vec;
    vec.pb(mp(0, 0));
    frange(i, n) {
        int a;
        scd(a);
        mv[a] = 1;
        v1.insert(a);
        vec.pb(mp(a, 1));
    }
    frange(i, n) {
        int a;
        scd(a);
        mv[a] = -1;
        v2.insert(a);
        vec.pb(mp(a, -1));
    }  
    sort(all(vec));

    vi pref(2*n+1);
    auto it = mv.begin();
    lli tot = 0;
    forr(i, 1, 2*n) {
        pref[i] = pref[i-1] + (*it).s;
        tot += (abs(pref[i])+c-1)/c * ((*next(it)).f - (*it).f);
        it++;
    }
    printf("%lld\n", tot);
    int ma = 0;
    frange(i, 2*n) ma = max(ma, pref[i]);
    
    

    while(true) {
        int cnt = 0;
        vi out;
        forr(i, 1, 2*n+1) {
            if(pref[i] < 0) continue;
            int id = i;
            
            while(min(pref[i], c) > cnt) {
                while(vec[id].s != 1) {
                    id--;
                }
                out.pb(vec[id].f);
                vec[id].s = 0;
                cnt++;
            }

            while(min(pref[i], c) < cnt) {
                while(vec[id].s != -1) {
                    id--;
                }
                out.pb(vec[id].f);
                vec[id].s = 0;
                cnt--;
            }
        }
        bool done = true;
        forr(i, 1, 2*n+1) {
            if(pref[i]>0) done = false;
        }
        if(done) break;
    }

    // while(true) {
    //     int cnt = 0;
    //     vi out;
    //     for(int i=2*n-1; i>=1; i--) {
    //         if(pref[i] > 0) continue;
    //         int id = i+1;
            
    //         while(min(abs(pref[i]), c) > cnt) {
    //             while(vec[id].s != 1) {
    //                 id++;
    //             }
    //             out.pb(vec[id].f);
    //             vec[id].s = 0;
    //             cnt++;
    //         }

    //         while(min(abs(pref[i]), c) < cnt) {
    //             while(vec[id].s != -1) {
    //                 id++;
    //             }
    //             out.pb(vec[id].f);
    //             vec[id].s = 0;
    //             cnt--;
    //         }
    //     }
    //     bool done = true;
    //     forr(i, 1, 2*n+1) {
    //         if(pref[i]<0) done = false;
    //     }
    //     if(done) break;
    // }
    
}