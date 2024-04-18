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
 
const lli mod = 2e9 + 9;
 
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
 
    vll rev(n+2);
    for(int i=n; i>=1; i--) {
        rev[i] = rev[i+1] * p + (str1[i-1] - 'a' + 1);
        rev[i] %= mod;
    }
 
    int lo = 0;
    int hi = n/2;
 
    while(lo != hi) {
        int mid = (lo+hi+1)/2;
        bool chk = false;
        int x = 2*mid;
        forr(i, 1, n-x+2) {
            lli v1 = (hash[i+mid-1] - (hash[i-1] * po[mid] % mod) + mod) % mod;
            lli v2 = (rev[i+mid] - (rev[i+x] * po[mid] % mod) + mod) % mod;
            // printf("%d %d %d %d %d %lld %lld\n", i, i+mid-1, i+mid, i+x-1, mid, v1, v2);
            if(v1 == v2) chk = true;
        }
        if(chk) lo = mid;
        else hi = mid-1;
        // printf("%d %d\n", lo, hi);
    }
    int v1 = lo;
    lo = 0;
    hi = (n-1)/2;
 
    while(lo != hi) {
        int mid = (lo+hi+1)/2;
        bool chk = false;
        int x = 2*mid+1;
        forr(i, 1, n-x+2) {
            lli v1 = (hash[i+mid-1] - (hash[i-1] * po[mid] % mod) + mod) % mod;
            lli v2 = (rev[i+mid+1] - (rev[i+x] * po[mid] % mod) + mod) % mod;
            // printf("%d %d %d %d %d %lld %lld\n", i, i+mid-1, i+mid+1, i+x-1, mid, v1, v2);
            if(v1 == v2) chk = true;
        }
        // printf("%d\n", mid);
        if(chk) lo = mid;
        else hi = mid-1;
    }
 
    int v2 = lo;
 
    if(v1 > v2) {
        int x = 2*v1;
        forr(i, 1, n-x+2) {
            lli o1 = (hash[i+v1-1] - (hash[i-1] * po[v1] % mod) + mod) % mod;
            lli o2 = (rev[i+v1] - (rev[i+x] * po[v1] % mod) + mod) % mod;
            if(o1 == o2) {
                forr(j, i, i+x) cout << str1[j-1];
                break;
            }
        }
    }
    else {
        int x = 2 * v2 + 1;
        // printf("%d ", x);
        forr(i, 1, n-x+2) {
            lli o1 = (hash[i+v2-1] - (hash[i-1] * po[v2] % mod) + mod) % mod;
            lli o2 = (rev[i+v2+1] - (rev[i+x] * po[v2] % mod) + mod) % mod;
            if(o1 == o2) {
                forr(j, i, i+x) cout << str1[j-1];
                break;
            }
        }
    }
}