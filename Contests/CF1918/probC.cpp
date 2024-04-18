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
    int t;
    scd(t);

    frange(_, t) {
        lli a, b, r;
        sclld(a);
        sclld(b);
        sclld(r);

        lli mi = 2e18;

        if(b > a) swap(a, b);

        int d = 61;
        for(int i=61; i>=0; i--) {
            if((a & (1LL<<i)) != (b & (1LL<<i))) {
                d = i;
                break;
            }
        }
        lli c = 0;
        for(int i=d-1; i>=0; i--) {
            if((a & (1LL<<i))) {
                if((b & (1LL<<i)) == 0) {
                    if(c + (1LL<<i) <= r) {
                        a = a ^ (1LL<<i);
                        b = b ^ (1LL<<i);
                        c += (1LL<<i);
                    }
                }
            }
        }

        mi = a - b;

        if((1LL<<d) <= r) {
            c = (1LL<<d);
            swap(a, b);
            b = b ^ (1LL<<d);
            a = a ^ (1LL<<d);
            for(int i=d-1; i>=0; i--) {
                if((a & (1LL<<i))) {
                    if((b & (1LL<<i)) == 0) {
                        if(c + (1LL<<i) <= r) {
                            a = a ^ (1LL<<i);
                            b = b ^ (1LL<<i);
                            c += (1LL<<i);
                        }
                    }
                }
            }
            mi = min(mi, a - b);
        }
        printf("%lld\n", mi);
    }
}