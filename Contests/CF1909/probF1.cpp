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

const lli mod = 998244353;

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);

        vll vec(n);
        frange(i, n)
            sclld(vec[i]);
        lli cnt = 0;
        lli tot = 1;

        if(vec[0] > 1 || vec[n-1] != n) {
            printf("0\n");
            continue;
        } 
        if(vec[0] == 0) cnt++;

        int pk = 0;

        forr(i, 1, n) {
            if(vec[i] > (i+1)) {
                tot = 0;
                break;
            }
            if(vec[i] - vec[i-1] == 0) cnt++;
            else if(vec[i] - vec[i-1] == 1) {
                tot = tot*((i+1)-vec[i]+1) + tot * cnt;
                tot %= mod;
                
            }
            else if(vec[i] - vec[i-1] == 2) {
                tot *= cnt;
                tot %= mod;
                if(cnt == 0) {
                    tot = 0;
                    break;
                }
                
                cnt--;
                tot *= ((i+1)-vec[i]+1-pk);
                tot %= mod;
                // pk++;
            }
            else {
                tot = 0;
                break;
            }
            // printf("%lld ", tot);
        }
        printf("%lld\n", tot);
    }
}