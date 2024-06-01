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

int gcd(lli a, lli b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    // usaco();
    int n;
    scd(n);
    if(n <= 2) {
        printf("-1");
        return 0;
    }
    vii vec(n);
    seti st1, st2, st3, st4;
    frange(i, n) {
        int x, y;
        scd(x);
        scd(y);
        st1.insert(x);
        st2.insert(y);
        st3.insert(x-y);
        st4.insert(x+y);
        // x+=300;
        // y+=300;
        vec[i] = mp(x, y);
    }

    if(st1.size()==1 || st2.size()==1 || st3.size() == 1 || st4.size() == 1) {
        printf("-1");
        return 0;
    }

    lli mi = 0;
    set<lli> val;

    for(auto p : vec) {
        auto it1 = st1.upper_bound(p.f);
        if(it1 == st1.end()) continue;
        auto it2 = st2.upper_bound(p.s);
        if(it2 == st2.end()) continue;
        val.insert(lli(*it1-p.f) * lli(*it2 - p.s));
    }
    for(auto e : val) {
        mi = gcd(mi, e);
    }
    printf("%lld", mi);
}