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
    int n;
    scd(n);

    vi pos(11, -1);

    vvi pos2(11, vi(11, -1));

    lli tot = 0;
    int ma = -1;
    frange(i, n) {
        int a;
        scd(a);
        
        forr(j, 1, 11) {
            forr(k, 1, 11) {
                if(a - k == k - j) {
                    ma = max(ma, pos2[j][k]);
                }
            }
        }
        tot += ma + 1;
        forr(j, 1, 11) {
            pos2[j][a] = pos[j];
        }
        pos[a] = i;
    }

    printf("%lld", tot);
}