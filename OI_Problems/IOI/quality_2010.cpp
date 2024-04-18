#include <bits/stdc++.h>
#include "quality.h"

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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

int grid[3001][3001];
int pref[3002][3002];

bool check(int x, int r, int c, int h, int w) {
    
    // pref[0][0] = grid[0][0] < x;
    // forr(i, 1, r+1) pref[i][0] = pref[i-1][0] + (grid[i][0] < x);
    // forr(i, 1, c+1) pref[0][i] = pref[0][i-1] + (grid[0][i] < x);
    // cerr << "Checkpoint 2\n";
    forr(i, 1, r+1) {
        forr(j, 1, c+1) {
            int v;
            if((grid[i-1][j-1] < x)) v = 1;
            else if((grid[i-1][j-1] == x)) v= 0;
            else v = -1;
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + v;
        }
    }
    h--;
    w--;
    // cerr << "Checkpoint 3\n";
    forr(i, 1, r-h+1) {
        forr(j, 1, c-w+1) {
            int v = pref[i+h][j+w] - pref[i+h][j-1] - pref[i-1][j+w] + pref[i-1][j-1];
            // printf("%d ", v);
            if(v >= 0) return true;
        }
        // printf("\n");
    }
    // cerr << "Checkpoint 4\n";
    return false;
}

int rectangle(int r, int c, int h, int w, int arr[3001][3001]) {
    forr(i, 0, r) {
        forr(j, 0, c) {
            grid[i][j] = arr[i][j];
        }
    }
    int lo = 1;
    int hi = r*c;
    // cerr << "Checkpoint 1\n";
    while(lo != hi) {
        int mid = (lo + hi)/2;
        if(check(mid, r, c, h, w)) {
            hi = mid;
        }
        else {
            lo = mid+1;
        }
    }
    // forr(i, lo, hi) {
    //     if(check(i, r, c, h, w)) return i;
    // }
    // check(9, r, c, h, w);
    return lo;
}

// static int R,C,H,W,Q[3001][3001],i,j,ans;
// int main(){
//     usaco();
//    scanf("%d%d%d%d",&R,&C,&H,&W);
//    // cout << R << " " << C << "\n";
//    for (i=0;i<R;i++) for (j=0;j<C;j++) scanf("%d",&Q[i][j]);
//    ans = rectangle(R,C,H,W,Q);
//    printf("%d\n",ans);
//    return 0;
// }
