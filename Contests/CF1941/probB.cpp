#include <bits/stdc++.h>
 
using namespace std;
 
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
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
        int n;
        scd(n);
        vi vec(n);
        frange(i, n) scd(vec[i]);

        bool done = true;
        frange(i, n-2) {
            if(vec[i+1] < vec[i] * 2) {
                done = false;
                break;
            }
            if(vec[i+2] < vec[i]) {
                done = false;
                break;
            }
            vec[i+1] -= 2*vec[i];
            vec[i+2] -= vec[i];
        }
        if(vec[n-2] != 0 || vec[n-1] != 0) done = false;
        if(done)
        printf("YES\n");
        else printf("NO\n");
    }
}