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
    lli n;
    sclld(n);
    int k;
    scd(k);

    vll vec(k);
    frange(i, k) sclld(vec[i]);

    lli tot = 0;

    forr(i, 1, 1<<k) {
        lli v = 1;
        bool done = true;
        frange(j, k) {
            if(i & (1<<j)) {
                if(v > (n+vec[j]-1)/vec[j]) {
                    done = false;
                    break;
                }
                else {
                    v *= vec[j];
                }
            }
        }
        if(done) {
            if(__builtin_popcount(i) % 2) {
                tot += n / v;
            }
            else tot -= n / v;
        }
    }
    printf("%lld", tot);
}