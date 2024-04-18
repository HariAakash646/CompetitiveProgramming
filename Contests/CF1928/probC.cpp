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
        int n, x;
        scd(n);
        scd(x);

        int v = n - x;
        int tot = 0;
        for(int i=1; i*i<=v; i++) {
            if(v % i == 0) {
                int y = v / i;
                if(i % 2 == 0) {
                    int k = (i + 2) / 2;
                    if(x <= k)
                        tot++;
                }
                if(y % 2 == 0 && y != i) {
                    int k = (y + 2) / 2;
                    if(x <= k)
                        tot++;
                }
            }
        }

        // printf("%d ", tot);

        if(x != 1) {
            int v = n + x - 2;
            for(int i=1; i*i<=v; i++) {
                if(v % i == 0) {
                    int y = v / i;
                    if(i % 2 == 0) {
                        int k = (i + 2) / 2;
                        if(x < k)
                            tot++;
                    }
                    if(y % 2 == 0 && y != i) {
                        int k = (y + 2) / 2;
                        if(x < k)
                            tot++;
                    }
                }
            }
        }
        printf("%d\n", tot);

    }
}