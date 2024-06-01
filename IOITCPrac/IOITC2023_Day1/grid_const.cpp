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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    usaco();
    int t;
    scd(t);

    frange(_, t) {
        lli p, q;
        sclld(p);
        sclld(q);

        int n = 2;
        // int m = 9;

        printf("%d %d\n", 2*n+2, 2*n+4);

        vvi grid(2*n+2, vi(2*n+4));
        grid[0][0] = 1;

        for(int i=0; i<=2*n; i+=2) {
            // printf("%d %d\n", i+1, i+3);
            grid[i][i+2] = grid[i+1][i+2] = grid[i][i+3]= grid[i+1][i+3] = 1;
            if(i > 0) grid[i-1][i+2] = 1;
        }  

        frange(i, 2*n+1) grid[i][0] = 1;


            
        for(int i=n; i>=0; i--) {
            
            if(q & (1LL<<i)) {
                int r = (n - i) * 2 + 1;
                frange(j, (n - i) * 2 + 2) grid[r][j] = 1;
            }   
        }
        grid[0][0] = 0;
        frange(i, 2*n+2) {
            frange(j, 2*n+4) {
                if(grid[i][j]) printf("B");
                else printf("R");
            }
            printf("\n");
        }
    }
}