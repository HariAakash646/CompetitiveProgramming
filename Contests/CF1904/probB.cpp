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
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        vector<pair<lli, int>> vec(n);

        frange(i, n) {
            sclld(vec[i].f);
            vec[i].s = i;
        }

        sort(all(vec));

        vll pref(n);
        pref[0] = vec[0].f;

        forr(i, 1, n) pref[i] = pref[i-1] + vec[i].f;

        vi cnt(n);
        vi out(n);
        cnt[n-1] = n;
        out[vec[n-1].s] = n-1;
        for(int i=n-2; i>=0; i--) {
            if(pref[i] >= vec[i+1].f) {
                cnt[i] = cnt[i+1];
            }
            else {
                cnt[i] = i+1;
            }
            out[vec[i].s] = cnt[i]-1;
        }

        for(auto e : out) printf("%d ", e);
        printf("\n");
        

    }
}