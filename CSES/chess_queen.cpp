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
    vvi grid(8, vi(8));

    frange(i, 8) {
        string str;
        cin >> str;
        frange(j, 8) {
            if(str[j] == '.') grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }

    vi vec = {0, 1, 2, 3, 4, 5, 6, 7};
    lli c = 0;
    do {
        bool done = true;
        frange(i, 8) {
            int j = vec[i];
            if(grid[i][j]) {
                done = false;
                break;
            }
            forr(k, i+1, 8) {
                if(vec[k] == j + (k - i)) {
                    done = false;
                    break;
                }
                if(vec[k] == j + (i-k)) {
                    done = false;
                    break;
                }
            }
        }
        if(done) c++;
    }
    while(next_permutation(all(vec)));
    printf("%lld", c);
}