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
    vb sieve(1e4+1);
    vi prime;
    sieve[0] = true;
    sieve[1] = true;

    forr(i, 2, (int)1e4+1) {
        if(!sieve[i]) {
            prime.pb(i);
            for(int j=i*i; j<=1e4; j+=i) {
                sieve[j] = true;
            }
        }
    }

    int t;
    scd(t);

    frange(_, t) {
        int a, k;
        scd(a);
        scd(k);
        lli c = 0;
        while(a >= k) {
            // c++;
            bool done = false;
            for(auto e : prime) {
                if(a % e == 0) {
                    c += e;
                    a /= e;
                    done = true;
                    break;
                }
            }
            if(!done) { c+= e;a = 1;}
        }
        printf("%d\n", c);
    }
}