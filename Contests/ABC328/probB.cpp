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

    int c = 0;

    forr(i, 1, n+1) {
        int k;
        scd(k);

        
        forr(j, 1, k+1) {
            int d = j;
            int v = d % 10;
            d /= 10;
            int a = 1;
            while(d) {
                if(d % 10 != v) a = 0;
                d /= 10;
            }
    
            int x = i;
            while(x) {
                if(x % 10 != v) a = 0;
                x /= 10;
            }
            c += a;
        }

        

    }
    printf("%d", c);
}