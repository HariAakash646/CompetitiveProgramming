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
        int n, k;
        scd(n);
        scd(k);

        vi vec(n);
        frange(i, n) scd(vec[i]);


        int id = n-1;
        vb vis(n);
        bool done = true;

        while(true) {
            // printf("%d ", vec[id]);
            if(vis[id]) break;
            if(vec[id] > n) {
                done = false;
                break;
            }
            vis[id] = true;
            id = (id - vec[id] + n) % n;
            k--;

            if(k == 0) break;
        }
        if(done) printf("Yes\n");
        else printf("No\n");
    }
}