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

        mpii vec;
        frange(i, n) {
            int a;
            scd(a);
            vec[a]++;
        }

        lli tot = 0;
        for(auto p : vec) {
            tot += lli(p.s) * lli(p.s-1) * (p.s-2);
            // for(lli i=2; lli(p.f)*i*i <= 1e9; i++) {
            //     // printf("%lld\n", p.f * i * i);
            //     if(vec.find(p.f*i) != vec.end() && vec.find(p.f*i*i) != vec.end())
            //         tot += lli(p.s) * vec[p.f*i] * vec[p.f*i*i];
            // }
            if(p.f >= 1e6) {
                for(lli i=2; i*p.f <= 1e9; i++) {
                    if(p.f % i == 0 && vec.find(p.f/i) != vec.end() && vec.find(p.f*i) != vec.end()) {
                        tot += lli(p.s) * vec[p.f/i] * vec[p.f*i];
                    }
                }
            }
            else {
                for(lli i=2; i*i<=p.f; i++) {
                    if(p.f % i == 0) {
                        // printf("%lld ", i);
                        if(i > p.f/i) continue;
                        if(vec.find(p.f/i) != vec.end() && vec.find(p.f*i) != vec.end()) {
                            tot += lli(p.s) * vec[p.f/i] * vec[p.f*i];
                        }
                        lli v = p.f / i;
                        if(i*i== p.f) continue;
                        if(vec.find(p.f/v) != vec.end() && vec.find(p.f*v) != vec.end()) {
                            tot += lli(p.s) * vec[p.f/v] * vec[p.f*v];
                        }
                    }

                }
                if(p.f != 1 && vec.find(1) != vec.end() && vec.find(p.f*lli(p.f)) != vec.end()) 
                    tot += lli(p.s) * vec[1] * vec[p.f*lli(p.f)];
            }
        }
        printf("%lld\n", tot);
    }
}