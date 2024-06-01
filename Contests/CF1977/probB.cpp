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
        int x;
        scd(x);

        vi vec(32);
        frange(i, 30) {
            if(x & (1<<i)) vec[i] = 1;
        }

        forr(i, 1, 31) {
            if(vec[i] && vec[i-1]) {
                vec[i] = 0;
                vec[i-1] = -1;
                int id = i+1;
                while(vec[id]) {
                    vec[id] = 0;
                    id++;
                }
                vec[id] = 1; 

            }
        }
        printf("32\n");
        for(auto e : vec) printf("%d ", e);
        printf("\n");
    }
}