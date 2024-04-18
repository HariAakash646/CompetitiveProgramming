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

vector<pair<int, pii>> vec;
map<pair<int, pii>, int> memo;
int ma = 0;

inline int rec(int i, int j, int k) {
    if(i == 0) return 0;
    if(memo.find(mp(k, mp(i, j))) != memo.end()) {
        return memo[mp(k, mp(i, j))];
    } 
    int v = max(0, vec[i].s.s - (k / vec[i].f));
    int k2 = k - (vec[i].s.s - v) * vec[i].f;
    // printf("%d %d %d %d %d\n", i, j, k, vec[i].s.f, vec[i].f);
    int val = rec(i-1, j, k);
    if(j - v >= 0)
        val = max(val, rec(i-1, j-v, k2) + vec[i].s.f);
    ma = max(ma, val);
    memo[mp(k, mp(i, j))] = val;
    return val;
}

int main() {
    // usaco();
    int n, a, b;
    scd(n);
    scd(a);
    scd(b);

    vec = vector<pair<int, pii>>(n+1);

    forr(i, 1, n+1) {
        scd(vec[i].s.f);
        scd(vec[i].s.s);
        scd(vec[i].f);
    }

    // vector<vvi> dp(n+1, vvi(a+1, vi(b+1)));
    sort(vec.begin()+1, vec.end(), greater<>());
    rec(n, a, b);
    printf("%d", ma);

}