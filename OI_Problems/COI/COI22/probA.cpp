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

vi ev, od;
int n;

bool check(int x, int v) {
    if(x == 0) return true;
    x *= 2;
    x += v;
    for(int i=1; i+x-1<=n; i++) {
        printf("? %d %d\n", i, i+x-1);
        fflush(stdout);
        int o;
        scd(o);
        if(o) return true;
    }
    return false;
}

int main() {
    
    cin >> n;

    int ma = 1;
    int lo = 0;
    int hi = n/2;

    forr(i, 1, n+1) {
        ev.pb(i);
        od.pb(i);
    }

    while(lo != hi) {
        int mid = (lo + hi+1)/2;
        if(check(mid, 0)) {
            lo = mid;
        }
        else hi = mid-1;
    }
    int v1 = lo;

    lo = 0;
    hi = (n-1)/2;

    while(lo != hi) {
        int mid = (lo + hi+1)/2;
        if(check(mid, 1)) lo = mid;
        else hi = mid-1;
    }
    printf("! %d\n", max(2*v1, 2*lo+1));


    return 0;
}