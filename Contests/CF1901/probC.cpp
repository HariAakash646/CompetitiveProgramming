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

        int mi = 1e9;
        int ma = 0;

        frange(i, n) {
            int a;
            scd(a);
            ma = max(ma, a);
            mi = min(mi, a);
        }

        int dif = ma - mi;

        int c = 0;
        vi vec;
        while(dif) {
            c++;
            int v= 0;
            if(dif % 2) {
                if(mi % 2 == 1) v = 1;
            }
            mi = (mi+v)/2;
            ma = (ma + v)/2;
            if(c <= n) vec.pb(v);
            dif = ma - mi;
            // printf("%d %d\n", ma, mi);
        }

        printf("%d\n", c);
        if(c <= n) {
            for(auto e : vec) printf("%d ", e);
        }
        printf("\n");
    }
}