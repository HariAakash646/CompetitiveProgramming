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
    lli n;
    sclld(n);
    n++;

    vll vec(19);
    vec[0] = 1;
    lli v = 1;
    forr(i, 1, 19) {
        v *= 10;
        vec[i] = 10 * vec[i-1] + v;
    }
    lli out = 0;
    vll po10(19);
    po10[0] = 1;

    forr(i, 1, 19) po10[i] = 10 * po10[i-1];

    while(n>0) {
        forr(i, 0, 19) {
            if(vec[i] > n) {
                lli v1 = 0;
                if(i > 0) v1 = vec[i-1];
                if(n <= po10[i] + v1) {
                    n -= v1+1;
                    out += po10[i];
                }
                else {
                    n -= po10[i] + v1;
                    lli v = n/v1;
                    n -= v * v1;
                    out += po10[i] * v;
                }
                break;
            } 
        }
    }
    cout << out - 1;
}