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
    int n, sz;
    scd(sz);
    scd(n);
    

    vector<vll> dp(sz+1, vll(sz+1));

    vll tot(sz+1);
    vector<vector<pair<lli, lli>>> val(sz+1);

    frange(i, n) {
        lli a, b, c;
        sclld(a);
        sclld(b);
        sclld(c);
        tot[b] += c;
        val[b].pb(mp(a, c));
    }
    forr(i, 1, sz+1) sort(all(val[i]), greater<>());

    vector<vll> pref(sz+1, vll(sz+1));

    forr(i, 1, sz+1) {
        int curr = 1;
        bool done = false;
        for(auto p : val[i]) {
            frange(j, p.s) {
                pref[i][curr] = pref[i][curr-1] + p.f;
                curr++;
                if(curr > sz) {
                    done = true;
                    break;
                }
            }
            if(done) break;
        }
        forr(j, curr, sz+1) {
            pref[i][j] = pref[i][j-1];
        }
    }

    forr(i, 1, sz+1) {
        forr(j, 1, sz+1) {
            for(int k=0; j-i*k>=0; k++) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-i*k] + pref[i][k]);
            }
        }
    }
    printf("%lld", *max_element(all(dp[sz])));

}