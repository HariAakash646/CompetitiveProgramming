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
    int n, k;
    scd(n);
    scd(k);
    vi v1(n), v2(n);
    frange(i, n) scd(v1[i]);
    frange(i, n) scd(v2[i]);
    if(k == 1){
        
        int c = 0;
        if(v1[0] != v2[0]) c++;
        forr(i, 1, n) {
            if(v1[i] != v2[i]) {
                if(v1[i-1] == v2[i-1]) c++;
            }
        }
        printf("%d", c);
    }
    else if(n <= 3) {
        int c = k;
        frange(i, n) {
            int c1;
            if(v1[i] <= v2[i]) c1 = v2[i] - v1[i];
            else c1 = k + 1 - v1[i] + v2[i];
            c = min(c, c1);
        }
        
        
        lli tot = 0;
        tot += c;
        frange(i, n) v1[i] = (v1[i] + c) % (k+1);
        // printf("%lld ", tot);
        if(n == 3) {
            if(v1[1] != v2[1]) {
                int cm = 0;
                frange(i, n) {
                    int c1;
                    if(v1[i] <= v2[i]) c1 = v2[i] - v1[i];
                    else c1 = k + 1 - v1[i] + v2[i];
                    cm = max(cm, c1);
                }
                // printf("%lld", cm);
                tot += cm;
            }
            else {
                int c1, c3;
                int i = 0;
                if(v1[i] <= v2[i]) c1 = v2[i] - v1[i];
                else c1 = k + 1 - v1[i] + v2[i];

                i = 2;
                if(v1[i] <= v2[i]) c3 = v2[i] - v1[i];
                else c3 = k + 1 - v1[i] + v2[i];
                int c = min(c1, c3);
                frange(i, n) v1[i] = (v1[i] + c) % (k+1);
                lli va1 = tot + c;
                int cm = 0;
                frange(i, n) {
                    int c1;
                    if(v1[i] <= v2[i]) c1 = v2[i] - v1[i];
                    else c1 = k + 1 - v1[i] + v2[i];
                    cm = max(cm, c1);
                }
                va1 += cm;
                lli va2 = tot + c1 + c3;
                tot = min(va1, va2);
            }
            
        }
        else {
            frange(i, n) {
                if(v1[i] <= v2[i]) tot = v2[i] - v1[i];
                else tot = k + 1 - v1[i] + v2[i];
            }
        }
        printf("%lld", tot);
    }
    else {
        lli ma = 0;
        frange(i, n) {
            if(v1[i] != v2[i]) {
                ma = max(ma, lli(k + 1 - v1[i]));
            }
        }
        printf("%lld", ma);
    }
}