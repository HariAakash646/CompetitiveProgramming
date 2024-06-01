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

void ins(int x, int v, mpii &mv) {
    auto it = mv.upper_bound(x);
    if(it != mv.begin()) {
        it--;
        if((*it).f >= v) return;
    }
    mv[x] = v;
    it = mv.lower_bound(x);
    it++;
    while(it != mv.end() && (*it).s <= v) {
        mv.erase(it);
        it = mv.lower_bound(x);
        it++;
    }
}

int query(int x, mpii &mv) {
    auto it = mv.lower_bound(x);
    if(it != mv.begin()) {
        it--;
        return (*it).s;
    }
    else return 0;
}

int main() {
    usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, k;
        scd(n);
        scd(k);

        vi vec(n+1);

        frange(i, n) {
            scd(vec[i+1]);
        }

        

        vector<vector<mpii>> dp(n+1, vector<mpii>(k+1));
        dp[0][0][-1e9] = 0;
        

        forr(i, 1, n+1) {
            frange(j, k+1) {
                int v = query(vec[i], dp[i-1][j]);
                ins(vec[i], v+1, dp[i][j]);
                for(auto p : dp[i-1][j]) ins(p.f, p.s, dp[i][j]);
                if(j>0) {
                    for(auto p : dp[i-1][j-1]) {
                        ins(p.f+1, p.s+1, dp[i][j]);
                    }
                }
                // printf("%d:%d ", dp[i][j].f, dp[i][j].s);
            }
            dp[i-1] = {};
            // printf("\n");
        }
        int ma = 0;
        frange(j, k+1) {
            
            ma = max(ma, query(1e9+5, dp[n][j]));
            printf("%d ", ma);
        }
        printf("\n");
    }
}