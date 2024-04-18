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
    int t;
    scd(t);
    frange(_, t) {
        int n, k;
        scd(n);
        scd(k);

        vii vec(n);
        frange(i, n) scd(vec[i].f);
        frange(i, n) scd(vec[i].s);

        int ma = 0;
        int tot = 0;
        int mv = 0;
        frange(i, min(n, k)) {
            tot += vec[i].f;
            mv = max(mv, vec[i].s);
            ma = max(ma, tot + (k-i-1) * mv);
        }
        printf("%d\n", ma);
    }
}