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
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    // usaco();
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);

    mpii mv;

    vii vec(n);

    frange(i, n) {
        scd(vec[i].f);
        scd(vec[i].s);
    }

    sort(all(vec));

    vll cnt(n);
    cnt[0] = m;
    lli tot = 0;
    frange(i, n) {
        lli v = min(cnt[i], (lli)vec[i].s);
        int id = lower_bound(all(vec), mp(vec[i].f+k, 0)) - vec.begin();
        if(id < n) {
            cnt[id] += v;
        }
        cnt[i] -= v;
        if(i +1 < n) cnt[i+1] += cnt[i];
        tot += v;
    }

    printf("%lld", tot);


}