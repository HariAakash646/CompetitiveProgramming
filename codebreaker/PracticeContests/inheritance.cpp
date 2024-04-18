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

int n, m, k;

int findf(int x, vi &disset) {
    while(x != disset[x]) {
        x = disset[x];
    }
    return x;
} 

void unionf(int x, int y, vi &disset, vi &sze) {
    x = findf(x, disset);
    y = findf(y, disset);
    if(sze[y] > sze[x]) swap(x, y);

    disset[y] = x;
    sze[x] = max(sze[x], sze[y]+1);
}

int main() {
    // usaco();
    scd(n);
    scd(m);
    scd(k);

    vector<pair<pii, pii>> vec(m);

    frange(i, m) {
        scd(vec[i].s.f);
        scd(vec[i].s.s);
        scd(vec[i].f.f);
        vec[i].f.s = i;
    } 
    sort(all(vec), greater<>());
    vvi disset(k, vi(n+1)), sze(k, vi(n+1));
    frange(i, k) {
        forr(j, 1, n+1) disset[i][j] = j; 
    }
    vi out(m);

    frange(i, m) {
        auto p = vec[i];
        int lo = 0;
        int hi = k;

        while(lo != hi) {
            int mid = (lo + hi)/2;
            if(findf(p.s.f, disset[mid]) != findf(p.s.s, disset[mid])) {
                hi = mid;
            }
            else lo = mid+1;
        }

        if(lo < k)
        {
            unionf(p.s.f, p.s.s, disset[lo], sze[lo]);
            out[p.f.s] += lo+1;
        }
        else out[p.f.s] = 0;
    }
    frange(i, m) printf("%d\n", out[i]);
}