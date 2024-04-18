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
    int n, k;
    scd(n);
    scd(k);

    int root = 0;

    frange(i, k) {
        vi cnt(n+1);
        frange(j, n-1) {
            int a, b;
            scd(a);
            scd(b);
            cnt[a]++;
            cnt[b]++;
        }
        bool done = false;
        forr(j, 1, n+1) {
            if(cnt[j] == n-1) {
                done = true;
                if(root == 0 || j == root) root = j;
                else root = -1;
            }
        }
        if(!done) root = -1;
    }
    
        forr(i, 1, n+1) {
            forr(j, 1, n+1) {
                if(i == j) printf("1 ");
                else if(i == root || j == root) printf("2 ");
                else {
                    if(root != -1) printf("3 ");
                    else printf("2 ");
                }
            }
            printf("\n");
        }
    
}