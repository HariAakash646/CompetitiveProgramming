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

const lli mod = 1e9 + 9;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const lli p = uniform_int_distribution<lli>(0, mod - 1)(rng);

int main() {
    // usaco();
    int n;

    string str1;
    cin >> str1;

    n = str1.size();

    vll po(n+1);

    po[0] = 1;

    forr(i, 1, n+1) po[i] = (po[i-1] * p) % mod;

    vll hash(n+1);

    forr(i, 1, n+1) {
        hash[i] = hash[i-1] * p + (str1[i-1] - 'a' + 1);
        hash[i] %= mod;
    }
    forr(i, 1, n) {
        lli v1 = hash[i];
        lli v2 = (hash[n] - (hash[n-i] * po[i] % mod) + mod) % mod;
        if(v1 == v2) printf("%d ", i);
    }



}