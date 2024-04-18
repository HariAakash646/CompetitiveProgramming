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
        int n, x, y;
        scd(n);
        scd(x);
        scd(y);
        vi vec(x);
        frange(i, x) scd(vec[i]);
        sort(all(vec));
        // if(n == 4) {
        //     if(x > 2) {
        //         printf("2\n");
        //     }
        //     else {
        //         if((vec[0] == 0 && vec[1] == 4) || vec[0] + 1 == vec[1]) {
        //             printf("0\n");
        //         }
        //         else printf("2\n");
        //     }
        // }
        // else {
        int out = x-2;
        forr(i, 1, x) {
            if(vec[i] - vec[i-1] == 2) out++;
        }
        if((vec[0] == 1 && vec[x-1] == n-1) || (vec[0] == 2 && vec[x-1] == n)) out++;
        mseti eve, odd;
        forr(i, 1, x) {
            if(vec[i] - vec[i-1] > 2) {
                if((vec[i] - vec[i-1]) % 2) odd.insert(vec[i] - vec[i-1]);
                else eve.insert(vec[i] - vec[i-1]);
            }
        }

        int d = n - vec[x-1] + vec[0];
        if(d > 2) {
            if(d % 2) odd.insert(d);
            else eve.insert(d);
        }

        for(auto e : eve) {
            // printf("%d ", e);
            int v = e / 2;
            if(y >= v-1) {
                y -= v-1;
                out += v + (v-1);
            }
            else {
                
                out += 2*y;
                y = 0;
            }
        }

        for(auto e : odd) {
            // printf("%d ", e);
            int v = e / 2;
            if(y >= v) {
                y -= v;
                out += 2 * v;
            }
            else {
                out += 2 * y;
                y = 0;
            }
        }
        

        printf("%d\n", out);
        // }
    }
}