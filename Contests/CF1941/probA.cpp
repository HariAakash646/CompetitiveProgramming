#include <bits/stdc++.h>
 
using namespace std;
 
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
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
        int n, m, k;
        scd(n);
        scd(m);
        scd(k);
        vi v1(n), v2(m);
        frange(i, n) scd(v1[i]);
        frange(i, m) scd(v2[i]);
        sort(all(v1));
        sort(all(v2));  
        lli tot = 0;
        for(auto e : v1) {
            for(auto x : v2) {
                if(e + x <= k) tot++;
            }
        }
        printf("%lld\n", tot);
    }
}