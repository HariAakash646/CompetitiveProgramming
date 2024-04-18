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
typedef vector<lli> vll;
typedef vector<bool> vb;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

lli mi;
int n;

lli cnt(vll &vec, int x) {
    auto it = vec.begin();
    vb vis(n, false);
    int v = 0;
    lli tot = 0;
    while(v < x) {
        tot += (x-v);
        it = lower_bound(it, vec.end(), tot);
        if(it == vec.end()) {
            break;
        }
        vis[int(it-vec.begin())] = true;
        it++;
        v++;
    }

    int id = n-1;
    frange(i, x-v) {
        while(id >= 0 && vis[id]) id--;
        id--;
    }
    while(id >= 0 && vis[id]) id--;
    lli v1 = 0;
    if(id >= 0) v1 = vec[id];
    lli v2 = lli(x) * lli(x+1)/2;

    return max(v1, v2);
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        
        scd(n);
        vll vec(n);
        frange(i, n) sclld(vec[i]);
        sort(all(vec));
        mi = 1e18;

        int l = 0;
        int r = n;
        while (r-l>=3) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            lli f1 = cnt(vec, m1);
            lli f2 = cnt(vec, m2);
            if (f1 >= f2)
                l = m1;
            else
                r = m2;
        }

        forr(i, l, r+1) {
            mi = min(mi, cnt(vec, i));
        }

        printf("%lld\n", mi);
    }
}