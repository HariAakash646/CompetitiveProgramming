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
    int n;
    scd(n);
    vi v1(n);
    frange(i, n) scd(v1[i]);

    priority_queue<pii> pq;

    frange(i, n) {
        int a;
        scd(a);
        if(a > 0)
            pq.push(mp(a, i));
    }

    vvi grid(n, vi(n));

    frange(i, n) {
        vii nxt;
        frange(j, v1[i]) {
            if(pq.size() == 0) {
                printf("-1");
                return 0;
            }
            auto p = pq.top();
            pq.pop();
            grid[i][p.s] = 1;
            p.f--;
            if(p.f > 0) nxt.pb(p);
        }
        for(auto p : nxt) pq.push(p);
    }
    if(pq.size()) {
        printf("-1");
        return 0;
    }

    frange(i, n) {
        frange(j, n) {
            if(grid[i][j]) printf("X");
            else printf(".");
        }
        printf("\n");
    }
}