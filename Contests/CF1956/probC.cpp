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
        int n;
        scd(n);
        lli tot=0;
        for(int i=n; i>=1; i--) {
            tot += (2*i-1) * i;
        }
        printf("%lld %d\n", tot, 2*n-1);
        int i1 = 1;
        int i2 = 2;
        frange(i, 2*n-1) {
            if(i % 2 == 0) {
                printf("1 %d ", i1);
                i1++;
                for(int j=n; j>=1; j--) printf("%d ", j);
            }
            else {
                printf("2 %d ", i2);
                i2++;
                for(int j=n; j>=1; j--) printf("%d ", j);
            }
            printf("\n");
        }
    }
} 