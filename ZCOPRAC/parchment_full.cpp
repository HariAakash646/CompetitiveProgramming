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
    int n, q, a;
    scd(n);
    scd(a);

    vi vec(n);

    frange(i, n) scd(vec[i]);
    sort(all(vec));

    vi cnt(n+1, a);

    for(int i=a; i>=0; i--) {
        auto it = vec.begin();
        int c = 0;
        while(it != vec.end()) {
            c++;
            it = upper_bound(it+1, vec.end(), *it+i);
        }
        cnt[c] = i;
    }

    int mi = cnt[1];
    forr(i, 1, n+1) {
        mi = min(mi, cnt[i]);
        cnt[i] = mi;
    }

    scd(q);

    frange(_, q) {
        int v;
        scd(v);
        if(v >= n) printf("0\n");
        else printf("%d\n", cnt[v]);
    }
}