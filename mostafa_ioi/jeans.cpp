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

int n, k;
vector<vll> dp;
vi vec;
vi cnt;
pii curr;
lli tot = 0;

void dnc(int id, int l, int r, int optl, int optr) {
    if(l > r) return;
    int mid = (l+r)/2;
    // for(int i=r; i>=optl; )

    while(curr.s < mid) {
        curr.s++;
        tot += cnt[vec[curr.s]];
        cnt[vec[curr.s]]++;
        
    }

    while(curr.f > min(optr+1, mid)) {
        curr.f--;
        tot += cnt[vec[curr.f]];
        cnt[vec[curr.f]]++;
        
    }

    while(curr.f < min(optr+1, mid)) {
        cnt[vec[curr.f]]--;
        tot -= cnt[vec[curr.f]];
        curr.f++;
    }

    while(curr.s > mid) {
        cnt[vec[curr.s]]--;
        tot -= cnt[vec[curr.s]];
        curr.s--;
    }

    pair<lli, int> mi = mp(1e18, -1);
    // printf("%d %d %lld\n", curr.f, curr.s, tot);
    
    // cnt[vec[mid]]++;
    for(int i=min(optr, mid-1); i>=optl; i--) {
        mi = min(mi, mp(tot + dp[id-1][i], i));
        if(i > 0) {tot += cnt[vec[i]];
        cnt[vec[i]]++;
        curr.f = i;}
    }

    dp[id][mid] = mi.f;
    // for(int i=mid-1; i>=optl; i--) cnt[vec[i]]--;
    dnc(id, l, mid-1, optl, mi.s);
    dnc(id, mid+1, r, mi.s, optr);
}

int main() {
    // usaco();
    scd(n);
    scd(k);

    vec = vi(n+1);
    forr(i, 1, n+1) scd(vec[i]);

    dp = vector<vll>(k+1, vll(n+1, 1e18));
    dp[0][0] = 0;
    cnt = vi(n+1);
    forr(i, 1, k+1) {
        tot = 0;
        cnt = vi(n+1);
        cnt[vec[1]]++;
        curr = mp(1, 1);
        dnc(i, 1, n, 0, n-1);
    }

    printf("%lld", dp[k][n]);


}