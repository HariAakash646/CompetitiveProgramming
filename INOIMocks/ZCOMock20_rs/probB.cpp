#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    vii vec(m);

    frange(i, m) {
        scd(vec[i].f);
    }

    frange(i, m) {
        scd(vec[i].s);
    }

    frange(i, m) {
        vec[i] = mp(vec[i].f + vec[i].s, vec[i].f - vec[i].s);
    }

    sort(all(vec), greater<>());
    vi lis(m+1, 2e9+10);
    lis[0] = -1e9;

    for(auto p : vec) {
        // printf("%d %d\n", p.f, p.s);
        int id = lower_bound(all(lis), p.s) - lis.begin();
        lis[id] = p.s;
    }
    int id = 0;
    frange(i, m+1) {
        // printf("%d ", lis[id]);
        if(lis[i] != 2e9+10) id = i;
        else break;
    }

    printf("%d", id);
}