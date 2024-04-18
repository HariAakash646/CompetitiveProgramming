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

vi vec;
vii val;
int n;

bool check(lli k) {
    pair<lli, lli> cnt = mp(0LL, k);

    frange(i, n) {
        auto p = val[i];
        if(p.f == p.s) {
            if(p.f * k > vec[i]) return false;
        }
        else if(p.f > p.s) {
            if(p.s * k > vec[i]) return false;
            cnt.s = min(cnt.s, (vec[i] - p.s*k) / (p.f - p.s));
        }
        else {
            if(p.f * k > vec[i]) return false;
            cnt.f = max(cnt.f, k - (vec[i] - p.f * k) / (p.s - p.f));
        }
    }
    return cnt.f <= cnt.s;
}

int main() {
    // usaco();
    scd(n);
    vec = vi(n);
    val = vii(n);

    frange(i, n) scd(vec[i]);
    frange(i, n) {
        scd(val[i].f);
        
    }
    frange(i, n) scd(val[i].s);

    lli lo = 0;
    lli hi = 1e9;

    while(lo != hi) {
        lli mid = (lo+hi+1)/2;
        if(check(mid)) {
            lo = mid;
        }
        else hi = mid-1;
    }
    printf("%lld", lo);
}