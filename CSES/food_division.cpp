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
    int n;
    scd(n);

    vi v1(n), v2(n);

    frange(i, n) scd(v1[i]);

    frange(i, n) scd(v2[i]);

    vll flow(n);

    forr(i, 1, n) flow[i] = flow[i-1] + (v2[i-1] - v1[i-1]);

    sort(all(flow));
    lli mid = flow[n/2];

    lli ans = 0;

    frange(i, n) ans += abs(flow[i] - mid);

    printf("%lld", ans);
}