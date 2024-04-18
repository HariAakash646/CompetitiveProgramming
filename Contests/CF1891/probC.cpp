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
vi vec;

bool check(int x) {
    lli tot = 0;
    forr(i, n-x, n) tot += vec[i];
    frange(i, n-x) tot -= vec[i];
    return tot <= 0LL;
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        
        scd(n);

        vec = vi(n);
        frange(i, n) scd(vec[i]);

        sort(all(vec));

        int en = n-1;
        lli c = 0;
        lli out = 0;

        // frange(i, n) {
        //     if(i > en) break;
        //     if(i == en) {
                
        //         out += (vec[en] - c + 1)/2;
        //         if(vec[en] > (vec[en] - c + 1)/2)
        //             out++; 
        //         break;
        //     }
        //     else {
        //         c += vec[i];
        //         out += vec[i];
        //         while(c >= vec[en]) {
        //             c -= vec[en];
        //             en--;
        //             out++;
        //         }
        //     }

        // }

        // printf("%lld\n", out);

        int lo = 0;
        int hi = n;

        while(lo != hi) {
            int mid = (lo + hi+1)/2;
            if(check(mid)) {
                lo = mid;
            }
            else hi = mid-1;
        }
        out = lo;
        lli tot = 0;
        forr(i, n-lo, n) tot -= vec[i];
        int id = 0;
        out += -tot;
        while(tot < 0) {
            tot += vec[id];
            id++;
        }
        lli val = 0;
        forr(i, id, n-lo) {
            tot += vec[i];
        }
        out += (tot+1)/2;
        if(tot > 1) out++;
        printf("%lld\n", out);


    }
}