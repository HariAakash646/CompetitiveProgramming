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
    int n, x;
    scd(n);
    scd(x);

    vi pr(n), pg(n), co(n);

    frange(i, n) scd(pr[i]);

    frange(i, n) scd(pg[i]);

    frange(i, n) scd(co[i]);

    vvi dp(n, vi(x+1));

    frange(i, x+1) {
        if(i % pr[0] == 0) {
            int v = i / pr[0];
            if(v <= co[0]) dp[0][i] = v * pg[0];
        }
    }

    forr(i, 1, n) {
        vector<deque<pii>> vec(pr[i]);

        frange(j, x+1) {
            int m = j % pr[i];
            while(vec[m].size() && dp[i-1][j] - (j/pr[i] * pg[i]) >= vec[m].front().f) vec[m].pop_front();
            vec[m].push_front(mp(dp[i-1][j] - (j/pr[i] * pg[i]), j));
            while((j - vec[m].back().s)/pr[i] > co[i]) vec[m].pop_back();
            dp[i][j] = vec[m].back().f + (j/pr[i] * pg[i]);
        }
    }

    printf("%d", *max_element(all(dp[n-1])));
}