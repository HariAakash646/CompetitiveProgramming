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
    frange(_,t) {
        int n, k;
        scd(n);
        scd(k);
        vi vec(n);
        frange(i, n) scd(vec[i]);
        int mi = k-1;
        for(auto e : vec) {
            int v = e % k;
            if(v == 0) mi = 0;
            else mi = min(mi, k-v);
        }
        if(k == 4) {
            mi = min(mi, 2);
            int eve = 0;
            for(auto e : vec) {
                if(e % 2 == 0) eve++;
            }
            if(eve == 1) mi = min(mi, 1);
            else if(eve >= 2) mi = 0;
        }
        printf("%d\n", mi);
    }
}