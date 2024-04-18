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
    lli a, b, c, d;
    sclld(a);
    sclld(b);
    sclld(c);
    sclld(d);

    lli tot = 0;

    // forr(x, a, b+1) {
    //     forr(y, b, c+1) {
    //         int mi = max(c, max(a, b) - min(a, b) + 1);
    //         int ma = min(d, x+y-1);
    //         if(ma >= mi) tot += ma - mi + 1;
    //     }
    // }

    forr(y, b, c+1) {
        lli l = c - y + 1;
        lli r = d - y + 1;
        // printf("%lld %lld %lld\n", l, r, y);
        // if(l > r) continue;
        lli x = r - l + 1;
        tot += x * (x+1)/2;
        if(b < l && b < r) {
            tot -= x * (x+1)/2;
        }
        else if(b < r) {
            lli x2 = b - l+1;
            tot -= (x * (x+1)/2 - x2 * (x2+1)/2);
        }
        if(l < a  && r < a) {
            tot -= x * (x+1)/2;
            r = a - 1;
        }
        else if(l < a) {
            lli x1 = a - l;
            tot -= x1 * (x1+1)/2;
        }

        if(r < b) {
            tot += (b - r) * (d-c+1);
        }

    }
    printf("%lld", tot);
}