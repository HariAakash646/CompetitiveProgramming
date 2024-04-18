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

int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x%y);
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        vi vec(n);

        frange(i, n) scd(vec[i]);

        sort(all(vec));

        int g = 0;
        frange(i, n-1) {
            int v = vec[n-1] - vec[i];
            g = gcd(v, g);
        }

        lli tot = 0;

        frange(i, n-1) {
            int v = vec[n-1] - vec[i];
            tot += v / g;
        }
        lli ad = n;
        for(int i=1; i<=n; i++) {
            if(!binary_search(all(vec), vec[n-1] - i * (lli)g)) {
                ad = i;
                break;
            }
        }

        printf("%lld\n", tot+ad);
    }
}