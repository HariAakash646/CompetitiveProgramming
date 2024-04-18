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
        int n;
        scd(n);

        vii a(n), b(n), c(n);

        frange(i, n) {
            scd(a[i].f);
            a[i].s = i;
        }

        frange(i, n) {
            scd(b[i].f);
            b[i].s = i;
        }

        frange(i, n) {
            scd(c[i].f);
            c[i].s = i;
        }

        sort(all(a), greater<>());
        sort(all(b), greater<>());
        sort(all(c), greater<>());

        int ma = 0;

        frange(i, 3) {
            frange(j, 3) {
                frange(k, 3) {
                    if(a[i].s != b[j].s && a[i].s != c[k].s && b[j].s != c[k].s) {
                        ma = max(ma, a[i].f + b[j].f + c[k].f);
                    }
                }
            }
        }
        printf("%d\n", ma);
    }
}