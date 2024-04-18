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

lli mod = 1e9 + 7;

int main() {
    usaco();
    vector<vll> vec(60, vll(20));

    forr(i, 2, 60) {
        int k2 = 31 - __builtin_clz(i);
        forr(j, 1, 20) {
            lli lo = (1LL<<i) - 1;
            lli hi = (1LL<<(i+1)) - 1;
            
            while(lo != hi) {
                lli mid = (lo + hi)/2;
                int k = 63 - __builtin_clzll(mid);
                if(k / k2 >= j) hi = mid;
                else lo = mid+1;
            }

            vec[i][j] = lo - (1LL<<i) + 1;
        }
    }

    vll val(60);
    forr(i, 2, 60) {
        forr(j, 1, 20)
            val[i] = (val[i] + vec[i][j] * j) % mod;
    }

    int t;
    scd(t);

    frange(_, t) {
        lli l, r;
        sclld(l);
        sclld(r);

        int k = 63 - __builtin_clzll(l);

        int k2 = 63 - __builtin_clzll(r);

        lli tot = 0;
        lli tot1 = 0;
        forr(i, 2, k) {
            tot1 += val[i];
            tot1 %= mod;
        }
        lli v = 1LL<<k;
        forr(i, 1, 20) {
            v += vec[k][i];
            if(v > l) {
                v -= vec[k][i];
                tot1 += (l - v) * i;
                tot1 %= mod;
                break;
            }
            tot1 += vec[k][i] * i;
            tot1 %= mod;
        }

        forr(i, 2, k2) {
            tot += val[i];
            tot %= mod;
        }
        v = 1LL<<k2;
        forr(i, 1, 20) {
            v += vec[k2][i];
            if(v > r) {
                v -= vec[k2][i];
                tot += (r - v) * i;
                tot %= mod;
                break;
            }
            tot += vec[k2][i] * i;
            tot %= mod;
        }
        printf("%lld\n", tot-tot1);
    }
}