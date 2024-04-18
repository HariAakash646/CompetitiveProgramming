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

const lli mod = 998244353;

int main() {
    // usaco();
    int n;
    scd(n);
    vll vec(n);
    frange(i, n) sclld(vec[i]);

    vll pow10(21, 1);

    forr(i, 1, 21) pow10[i] = pow10[i-1] * 10 % mod;
    lli tot = 0;
    frange(j, n) {
        lli x = vec[j];
        for(int i=1; i<=20; i+=2) {
            lli v = x % 10;
            v *= (n);
            v %= mod;
            x /= 10;
            tot += v * pow10[i];
            tot %= mod;
        }
        // printf("%lld\n", tot);
        x = vec[j];
        for(int i=0; i<=20; i+=2) {
            lli v = x % 10;
            v *= (n);
            v %= mod;
            x /= 10;
            tot += v * pow10[i];
            tot %= mod;
        }
        // printf("%lld\n", tot);
    }
    printf("%lld", tot);


}