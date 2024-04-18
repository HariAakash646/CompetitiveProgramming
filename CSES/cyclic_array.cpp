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
    lli k;
    sclld(k);

    vll vec(2*n+1);
    forr(i, 1, n+1) {
        sclld(vec[i]);
        vec[n+i] = vec[i];
    }
    lli v = 0;
    int r = 2*n;

    vvi lift(21, vi(2*n+2));
    lift[0][2*n+1] = 2*n+1;

    for(int i=2*n; i>=1; i--) {
        v += vec[i];
        while(v > k) {
            v -= vec[r];
            r--;
        }
        lift[0][i] = r+1;
    }

    forr(i, 1, 21) {
        forr(j, 1, 2*n+2) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    int mi = n;

    forr(i, 1, n+1) {
        int x = i;
        int c = 1;
        for(int j=20; j>=0; j--) {
            int xt = lift[j][x];
            if(xt < n+i) {
                x = xt;
                c += (1<<j);
            }
        }
        // printf("%d ", c);
        mi = min(mi, c);
    }
    printf("%d", mi);

}