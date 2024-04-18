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
        vii vec(n);

        frange(i, n) scd(vec[i].f);
        frange(j, n) scd(vec[j].s);

        frange(i, n) {
            if(vec[i].f > vec[i].s) swap(vec[i].f, vec[i].s);
        } 

        int ans = 0;
        int ma = 0;
        frange(i, n) ma = max(ma, vec[i].f);

        int mi = 1e9+10;
        frange(i, n) mi = min(mi, vec[i].s);

        ans = max(0, 2*(ma-mi));

        lli tot = ans;

        frange(i, n) tot += abs(vec[i].f - vec[i].s);

        printf("%lld\n", tot);


    }
}