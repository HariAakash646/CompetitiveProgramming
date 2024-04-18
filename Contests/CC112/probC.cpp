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
    int t, s1;
    scd(t);
    scd(s1);

    frange(_, t) {
        int n;
        scd(n);
        vi vec(n);

        frange(i, n) scd(vec[i]);
        sort(all(vec));
        if(s1 == 0) {
            lli tot = 0;
            frange(i, (n+1)/2) {
                tot += vec[i];
            }
            if(n % 2 == 0) {
                tot -= vec[0];
                tot += vec[n/2];
            }
            printf("%lld\n", tot);
        }
        else {
            lli ma = 0;
            vll pref(n+1);
            forr(i, 1, n+1) pref[i] = pref[i-1] + vec[i-1];

            forr(i, 1, n+1) {
                lli tot = pref[n-i + (i+1)/2] - pref[n-i];
                if(i % 2 == 0) {
                    tot -= vec[n-i+1-1];
                    tot += vec[n-i + (i+1)/2 + 1-1];
                }
                ma = max(ma, tot);
            }
            printf("%lld\n", ma);
        }
    }
}