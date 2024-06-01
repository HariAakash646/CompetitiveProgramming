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

int msb(lli x) {
    return 63 - __builtin_clzll(x);
}

int main() {

    lli l, r;
    int k;
    sclld(l);
    sclld(r);
    scd(k);

    if(k == 1) {
        printf("%lld\n", l);
        printf("1\n%lld\n", l);
        return 0;
    }

    if(r - l <= 4) {
        vll vec;
        for(lli i=l; i<=r; i++) vec.pb(i);
        int sz = vec.size();
        pair<lli, int> mi = mp(l, 1);
        forr(i, 1, 1<<sz) {
            if(__builtin_popcount(i) > k) continue;
            lli v = 0;
            frange(j, sz) {
                
                if(i & (1<<j)) {
                    v = v ^ vec[j];
                }

            }
            // printf("%lld %d\n", v, i);
            mi = min(mi, mp(v, i));
        }
        printf("%lld\n", mi.f);
        printf("%d\n", __builtin_popcount(mi.s));
        frange(j, sz) {
            if(mi.s & (1<<j)) {
                printf("%lld ", vec[j]);
            }
        }
        return 0;
    }

    if(k == 2) {
        lli v = l;
        if(l%2) v++;
        printf("1\n2\n");
        printf("%lld %lld", v, v+1);
    }
    else if(k == 3) {
        lli z = l;
        int c = msb(l);
        lli x = 1LL<<(c+1);
        x = x | (1LL<<c);
        if(x <= r) {
            lli y = 1LL<<(c+1);
            y = y | l;
            y = y ^ (1LL<<c);
            printf("0\n3\n");
            printf("%lld %lld %lld", x, y, z);
        }
        else {
            lli v = l;
            if(l%2) v++;
            printf("1\n2\n");
            printf("%lld %lld", v, v+1);
        }
    }
    else {
        lli v = l;
        if(l%2) v++;
        printf("0\n4\n");
        printf("%lld %lld %lld %lld", v, v+1, v+2, v+3);
    }
}