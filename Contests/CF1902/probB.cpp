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

int n, l, t;
lli p;

bool check(int x) {
    x = n-x;
    lli tot = x * lli(l);

    int v = (n+6)/7;
    tot += min(2*x, v) * lli(t);

    return tot >= p;
}

int main() {
    // usaco();
    int tc;
    scd(tc);

    frange(_, tc) {
        scd(n);
        sclld(p);
        scd(l);
        scd(t);
        

        int lo = 0;
        int hi = n;

        while(lo != hi) {
            int mid = (lo+hi+1)/2;

            if(check(mid)) {
                lo = mid;
            }
            else {
                hi = mid-1;
            }
        }

        printf("%d\n", lo);

    }
}