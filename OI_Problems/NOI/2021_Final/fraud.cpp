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
    int n;
    scd(n);
    vll v1(n), v2(n);

    frange(i, n) sclld(v1[i]);
    frange(i, n) sclld(v2[i]);

    ld lo = 0;
    ld hi = 1e18;

    forr(i, 1, n) {
        if(v1[i] >= v1[i-1] && v2[i] >= v2[i-1]) {
            printf("NO\n");
            return 0;
        }
        else if(v1[i] <= v1[i-1] && v2[i] <= v2[i-1]) continue;
        else if(v1[i] < v1[i-1]) {
            lo = max(lo, ld(v2[i] - v2[i-1]) / ld(v1[i-1] - v1[i]));
        }
        else if(v1[i] > v1[i-1]) {
            hi = min(hi, ld(v2[i-1] - v2[i]) / ld(v1[i] - v1[i-1]));
        }
    }
    // cout << lo << " " << hi << "\n";
    if(lo < hi) printf("YES");
    else printf("NO");
}