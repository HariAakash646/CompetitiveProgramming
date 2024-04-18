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

vll cnt(1e6+1);
vi sieve(1e6+1, 1);

void fun(int x) {
    int sq;
    for(int i=1; i*i<=x; i++) sq = i; 
    forr(i, 1, sq+1) {
        if(x % i == 0) {
            cnt[i]++;
            int v = x / i;
            if(v > i) cnt[v]++;
        }
    }
}

int main() {
    // usaco();
    int n;
    scd(n);

    forr(i, 1, n+1) {
        int a;
        scd(a);
        fun(a);
    }

    forr(i, 2, 1e6+1) {
        if(sieve[i] == 1) {
            for(int j=2*i; j<=1e6; j+=i) {
                sieve[j]++;
                // if(j % (lli(i)*i) == 0) cnt[j] = 0;
            }
        }
    }

    vll gcdcn(1e6+1);

    for(int i=1e6; i>=1; i--) {
        gcdcn[i] = cnt[i] * (cnt[i] - 1)/2;
        for(int j=2*i; j<=1e6; j+=i) gcdcn[i] -= gcdcn[j];
    }

    printf("%lld", gcdcn[1]);

}