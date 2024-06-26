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

const lli mod = 1e9 + 7;

int main() {
    // usaco();
    int t;
    scd(t);

    vll fact(3e5+1, 1);
    forr(i, 1, 3e5+1) fact[i] = (fact[i-1] * i) % mod;

    frange(_, t) {
        int n;
        scd(n);

        forr(k, 1, n+1)  {
            int n1 = n - (k-1);
            lli tot = fact[n1/k];
            tot *= fact[n-(n1+k-1)/k];
            tot %= mod;
            if(n1 % k) {
                int x = n1 % k;
                tot *= k-1+x - 2*(x-1);
                tot %= mod;
                tot *= (n1/k+1);
                tot %= mod;
            }
            printf("%lld ", tot);
        }
        printf("\n");
    }
}