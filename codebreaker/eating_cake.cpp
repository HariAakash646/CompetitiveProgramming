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

int n;
lli x, y;

vll vec;

lli rec(int l, int r) {
    if(l > r) return 0;
    if(l == r) return min(vec[l] * x, y);
    lli mi = 1e9+10;
    int mid = 0;

    for(int i=l; i<=r; i++) {
        if(vec[i] < mi) {
            mi = vec[i];
            mid = i;
        }
    }

    lli v1 = (r - l + 1) * y;
    lli v2 = mi * x;
    forr(i, l, r+1) vec[i] -= mi;
    v2 += rec(l, mid-1);
    v2 += rec(mid+1, r);
    return min(v1, v2);
}

int main() {
    // usaco();
    scd(n);
    // sclld(x);
    // sclld(y);
    x = 1, y = 1;

    vec = vll(n);

    frange(i, n) sclld(vec[i]);

    printf("%lld", rec(0, n-1));
}