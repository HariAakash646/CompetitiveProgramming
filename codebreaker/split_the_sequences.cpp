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

struct line {
    lli m, c;
    int id;

    lli eval(lli x) {
        return m * x + c;
    }

    ld intersect(line y) {
        return ld(y.c - c) / ld(m - y.m);
    }
};

int main() {
    // usaco();
    int n, k;
    scd(n);
    scd(k);
    vll vec(n+1);
    forr(i, 1, n+1) sclld(vec[i]);

    vll pref(n+1);

    forr(i, 1, n+1) pref[i] = pref[i-1] + vec[i];

    vector<vll> dp(k+1, vll(n+1, -1e15));

    dp[0][0] = 0;
    vvi pre(k+1, vi(n+1));

    forr(i, 1, k+1) {
        deque<line> dq;
        line tmp;
        tmp.m = 0;
        tmp.c = dp[i-1][0];
        tmp.id = 0;
        dq.pb(tmp); 
        forr(j, 1, n+1) {
            while(dq.size() >= 2 && dq[1].eval((pref[n] - pref[j])) >= dq[0].eval(pref[n] - pref[j])) dq.pop_front();
            dp[i][j] = dq[0].eval(pref[n] - pref[j]) + pref[j] * (pref[n] - pref[j]);
            pre[i][j] = dq[0].id;
            line l;
            l.m = -pref[j];
            l.c = dp[i-1][j];
            l.id = j;

            while(dq.size() >= 2 && dq[dq.size()-2].intersect(l) >= dq[dq.size()-2].intersect(dq.back())) dq.pop_back();

            dq.pb(l);
        }
    }

    lli ma = -1e18;
    int mid = 0;

    forr(i, 1, n) {
        if(dp[k][i] >= ma) {
            ma = dp[k][i];
            mid = i;
        }
    }

    printf("%lld\n", ma);

    for(int i=k; i>=1; i--) {
        printf("%d ", mid);
        mid = pre[i][mid];
    }
}