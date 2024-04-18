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
    int t;
    scd(t);

    frange(_, t) {
        int n, k, d;
        scd(n);
        scd(k);
        scd(d);
        vi vec(n);
        frange(i, n) scd(vec[i]);
        vi v2(k);
        frange(i, k) scd(v2[i]);
        frange(i, min(d-1, 3*n)) {
            v2.pb(v2[i%k]);
        }
        int ma = 0;
        frange(i, n) {
            if(vec[i] == i+1) ma++;
        }
        ma += (d-1)/2;
        frange(i, min(d-1, 3*n)) {
            frange(j, v2[i]) vec[j]++;
            int c = 0;
            frange(j, n) {
                if(vec[j]==j+1) c++;
            }
            ma = max(ma, c+(d-i-2)/2);
        }
        printf("%d\n", ma);
    }
}