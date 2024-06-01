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
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        lli p, q;
        sclld(p);
        sclld(q);

        if(p==0) {
            int n = 2;
            int m = q;
            printf("%d %d\n", n, m);
            frange(i, n) {
                frange(j, m) printf("B");
                printf("\n");
            }
            continue;
        }
        if(q==0) {
            int n = 2;
            int m = p;
            printf("%d %d\n", n, m);
            frange(i, n) {
                frange(j, m) printf("R");
                printf("\n");
            }
            continue;
        }

        int n = p+2;
        int m = q+2;
        
        int n1 = 0;
        int m1 = 0;

        if(p%2==0) n1 = 1;
        if(q%2==1) m1 = 1;
        

        printf("%d %d\n", n+n1, m+m1);

        vvi grid(n+n1, vi(m+m1));
        frange(i, n+n1) {
            frange(j, m+m1) {
                grid[i][j] = (i+j)%2;
            }
        }
        grid[0][1] = grid[0][0] = 1;
        grid[1][0] = grid[1][1] = 0;

        forr(i, 2, n) {
            grid[i][0] = grid[i][1] = 0;
            
        }


        forr(j, 2, m) {
            grid[0][j] = grid[1][j] = 1;

        }

        

        forr(i, 2, m-1+m1) grid[n-1+n1][i] = 0;
        forr(i, 2, n-1+n1) grid[i][m-1+m1] = 1;

        grid[n-1][0] = 1;

        if(n1) {
            grid[n][1] = 0;
            grid[n][0] = 1;
        }

        if(m1) {
            grid[1][m] = 1;
            grid[0][m] = 0;
        }
        grid[n-1+n1][m-1+m1] = 0;
        frange(i, n+n1) {
            frange(j, m+m1) {
                if(grid[i][j]) printf("B");
                else printf("R");
            }
            printf("\n");
        }
    }
}