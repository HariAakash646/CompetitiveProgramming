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
 
map<int, seti> mv;
vi prime;
 
void dfs(int x, int d) {
    if(mv.find(x) != mv.end()) return;
    mv[x].insert(x-1);
 
    // if(d >= 4) return;
 
    for(auto i : prime) {
        if(i*i > x) break;
        if(x % i == 0) {
            dfs(i, d+1);
            // if(x == 12) printf("%d\n", i);
            for(auto e : mv[i]) {
                mv[x].insert(e+x/i-1);
            }
            if(i *i != x) {
                dfs(x/i, d+1);
                for(auto e : mv[x/i]) {
                    mv[x].insert(e+i-1);
                }
            }
        }
    }
}
 
int main() {
    vb sieve(4e4);
    sieve[1] = true;
    for(int i=2; i<4e4; i++) {
        if(!sieve[i]) {
            prime.pb(i);
            for(int j=i*i; j<4e4; j++) {
                sieve[j] = false;
            }
        }
    }
    // usaco();
    int n;
    scd(n);
    dfs(n, 1);
    printf("%d\n", (int)mv[n].size());
    for(auto e : mv[n]) printf("%d ", e);
    // forr(i, 1, n+1) {
    //     printf("%d: ", i);
    //     for(auto e : mv[i]) printf("%d ", e);
    //     printf("\n");
    // }
}