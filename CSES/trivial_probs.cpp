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
 
    int n;
    scd(n);
    vi vec(n);

    frange(i, n) scd(vec[i]);

    lli mi = 1e12;

    frange(i, 1<<n) {
        lli t1 = 0;
        lli t2 = 0;

        frange(j, n) {
            if(i & (1<<j)) t1 += vec[j];
            else t2 += vec[j];
        }
        mi = min(mi, abs(t1 - t2));
    }

    printf("%lld", mi);
 
 
 
 
}