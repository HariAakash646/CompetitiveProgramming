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
typedef vector<vll> vvll;


void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int main() {
    int n=30;
    int curr = 1;
    vb vis(1e5);
    vi vec;
    forr(i, 1, n+1) {
        while(true) {
            bool done = true;
            for(auto e : vec) {
                if(vis[e+curr]) done = false;
            }
            if(vis[2*curr]) done = false;
            if(done) {
                vec.pb(curr);
                for(auto e : vec) vis[e+curr] = true;
                curr++;
                break;
            }
            else curr++;
        }
    }
    for(auto e : vec) printf("%d ", e);

}