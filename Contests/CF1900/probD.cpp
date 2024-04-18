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

int sqrtfu(int x) {
    lli lo = 1;
    lli hi = x;
    while(lo != hi) {
        lli mid = (lo + hi+1)/2;
        if(mid *mid <= x) lo = mid;
        else hi = mid-1; 
    }
    return (int)lo;
}

int main() {
    // usaco();
    int t;
    scd(t);

    vvi fact(1e5+1);

    forr(e, 1, 1e5+1) {
        int sq = sqrtfu(e);

        forr(i, 1, sq+1) {
            if(e % i == 0) {
                fact[e].pb(i);
                if(e / i != i) fact[e].pb(e/i);
            }
        }
        sort(all(fact[e]), greater<>());
    }



    frange(_, t) {
        int n;
        scd(n);

        vi vec(n);

        frange(i, n) scd(vec[i]);

        sort(all(vec));

        

        vll cnt(1e5+1);
        lli tot = 0;
        frange(i, n) {
            vector<pair<int, lli>> reset;
            for(auto e : fact[vec[i]]) {
                tot += e * cnt[e] * (n-i-1);
                for(auto x : fact[e]) {
                    if(x != e)
                    {   
                        cnt[x] -= cnt[e];
                        reset.pb(mp(x, cnt[e]));
                    }
                }
            }
            for(auto p : reset) cnt[p.f] += p.s;
            for(auto e : fact[vec[i]]) cnt[e]++;
        }
        printf("%lld\n", tot);
    }
}