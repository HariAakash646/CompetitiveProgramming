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
    int t;
    scd(t);

    frange(_, t) {
        int n, x;
        scd(n);
        scd(x);
        if(n % 2) {
            if(x == n) {
                for(int i=n; i>=1; i--) printf("%d ", i);
            }
            else if(x == 1) {
                forr(i, 1, n+1) printf("%d ", i);
            }
            else printf("-1");
            printf("\n");
        }
        else {
            if(x > n/2) {
                {
                    for(int i=x; i<=n; i++) printf("%d ", i);
                    for(int i=n/2+1; i<x; i++) printf("%d ", i);
                    for(int i=0; i<x-(n/2); i++) printf("%d ", n/2-i);
                    forr(i, 1, n/2-(x-(n/2)-1)) printf("%d ", i);
                }
                // if(x == n/2+1) {
                //     for(int i=n/2+1; i<=n; i++) printf("%d ", i);
                //     for(int i=1; i<=n/2; i++) printf("%d ", i);
                // }
                // else 
            }
            else {

                {
                    for(int i=x; i>=1; i--) printf("%d ", i);
                    for(int i=n/2-1; i>x; i--) printf("%d ", i);
                    for(int i=0; i<=(n/2)-x; i++) printf("%d ", (n/2+i));
                    forr(i, 0, n/2-((n/2)-x)) printf("%d ", n-i);
                }

            }
            printf("\n");
        }




    } 
}