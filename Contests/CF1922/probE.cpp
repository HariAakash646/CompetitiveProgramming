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
        lli x;
        sclld(x);
        vll out;
        lli v = 1;

        int c = 0;
        while(2*v <= x) {
            v *= 2;
            c++;
        }

        frange(i, c) out.pb(i);

        x -= v;
        while(x > 0) {
            lli v = 1;
            int c = 0;
            while(2*v <= x) {
                v *= 2;
                c++;
            }
            x-=v;

            out.pb(c);
        }
        printf("%d\n", (int)out.size());
        for(auto e : out) printf("%lld ", e);
        printf("\n");
    }
}
