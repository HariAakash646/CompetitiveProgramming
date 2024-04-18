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
    vb sieve(4e6+1);
    sieve[1] = true;
    sieve[0] = true;

    forr(i, 2, 4e6+1) {
        if(!sieve[i]) {
            for(int j=2*i; j<=4e6; j+=i) sieve[j] = true;
        }
    }

    int t;
    scd(t);
    frange(_, t) {
        int h;
        scd(h);

        int curr = 1;
        int c = 0;
        while(curr <= h) {
            if(!sieve[h]) {
                h = 0;
                printf("%d\n", c+1);
                break;
            }
            h -= curr;
            c++;
            // printf("%d ", h);
            if(h < 0) break;
            if(h == 0) {
                printf("%d\n", c);
                break;
            }
            else if(!sieve[h]) {
                h = 0;
                printf("%d\n", c+1);
                break;
            }
            curr *= 2;
        }
        if(h != 0) printf("-1\n");
    }
}