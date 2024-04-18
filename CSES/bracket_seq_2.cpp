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

lli inv(lli a) {
  return a <= 1 ? a : mod - (mod/a) * inv(mod % a) % mod;
}

lli fact(lli n) {
    lli v = 1;
    forr(i, 1, n+1) v = (v * i) % mod;
    return v;
}

lli combi(int n, int r) {
    return fact(n) * inv(fact(r)) % mod * inv(fact(n-r)) % mod;
}

int main() {
    int n;
    string str;
    cin >> n >> str;

    stack<int> stk;

    n -= str.size();

    for(auto e : str) {
        if(e == '(') stk.push(1);
        else {
            if(stk.size() == 0) {
                printf("0");
                return 0;
            }
            else stk.pop();
        }
    }

    int k = stk.size();
    n -= k;

    if(n % 2 || n < 0) {
        printf("0");
        return 0;
    }

    n /= 2;

    lli v = ((k+1) *  inv(n+k+1) % mod) * combi(2*n+k, n) % mod;
    printf("%lld", v);
}