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
        int n, k;
        scd(n);
        scd(k);
        vi out(n);
        vi val;
        for(int i=(k+1)/2; i>=1; i--) val.pb(i);
        for(int i=k; i>(k+1)/2; i--) val.pb(i);
        int en = -1;
        for(int i=0; i+k-1<n; i+=k) {
            // out[i] = i+1;
            for(int j=0; i+j<n && j < k; j++) {
                out[i+j] = i+val[j];
                en = i+j;
            }
            // for(int j=i+1; j<min(n, i+k); j++) {
            //     out[j] = min(n, i+k) - (j - i) + 1;
            // }
        }
        en++;
        val = {};
        int kt = n - en;
        for(int i=(kt+1)/2; i>=1; i--) val.pb(i);
        for(int i=kt; i>(kt+1)/2; i--) val.pb(i);
        for(int i=en; i<n; i++) {
            out[i] = val[i-en] + en;
        }
        frange(i, n) printf("%d ", out[i]);
        printf("\n");
        int q = (n+k-1)/k;
        printf("%d\n", q);
        for(int i=1; i<=n; i++) {
            printf("%d ", (i+k-1)/k);
        }
        printf("\n");
    }
}