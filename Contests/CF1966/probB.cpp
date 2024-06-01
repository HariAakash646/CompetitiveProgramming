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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, k;
        scd(n);
        scd(k);
        int msb = 31 - __builtin_clz(k);
        vi out;
        frange(i, msb) out.pb(1<<i);
        out.pb(k - (1<<msb));
        out.pb(k+1);
        out.pb((1<<(msb+1))+1);
        forr(i, msb+1, 21) out.pb(1<<i);
        printf("%d\n", (int)out.size());
        for(auto e : out) printf("%d ", e);
        printf("\n");
        // if(k != (1<<msb)) {
        //     vi val;
        //     frange(i, 21) {
        //         if(k & (1<<i)) val.pb(i);
        //     }
        //     int id = val[val.size()-2];
        //     out.pb(1<<id);
        // }
    }
}