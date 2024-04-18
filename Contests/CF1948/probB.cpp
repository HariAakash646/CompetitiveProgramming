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
        int mi = 1e9;
        for(int i=n-1; i>=0; i--) {
            if(vec[i] > mi) {
                if(vec[i] >= 10) {
                    int v1 = vec[i] % 10;
                    int v2 = vec[i] / 10;
                    if(v2 <= v1 && v1 <= mi) {
                        mi = v2;
                    }
                    else done = false;
                }
                else {
                    done = false;
                }
            }
            else
                mi = vec[i];
        }
        if(done) printf("YES\n");
        else printf("NO\n");
    }
}