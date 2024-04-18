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
   //  freopen("threesum.in", "r", stdin);
   // freopen("threesum.out", "w", stdout);
}

vvi lift;

int binlift(int x, lli c) {
    frange(i, 64) {
        if(c & (1LL<<i)) {
            x = lift[i][x];
        }
    }
    return x;
}

int main() {
    // usaco();
    int n, k;
    lli m;
    scd(n);
    scd(k);
    sclld(m);

    lift = vvi(64, vi(n+1));

    vll vec(n+1);
    frange(i, n) sclld(vec[i+1]);

    int l = 1;
    int r = k+1;
    lift[0][1] = k+1;

    forr(i, 2, n+1) {
        while(r < n && vec[r+1] - vec[i] < vec[i] - vec[l]) {
            l++;
            r++;
        }
        if(vec[r] - vec[i] > vec[i] - vec[l]) {
            lift[0][i] = r;
        }
        else lift[0][i] = l;
    }

    forr(i, 1, 64) {
        forr(j, 1, n+1) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    forr(i, 1, n+1) printf("%d ", binlift(i, m));
}