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
    int n, m;
    scd(n);
    scd(m);
    vvi graph(n+1),par(n+1);
    vi indeg(n+1);
    vector<pair<int, bool>> cnt(n+1);
    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        cnt[a].f++;
        indeg[b]++;
        graph[a].pb(b);
        par[b].pb(a);
    }

    vb cyc(n+1, true);
    queue<int> q;
    forr(i, 1, n+1) {
        if(indeg[i] == 0) q.push(i);
    }
    int c = 0;
    while(q.size()) {
        auto p = q.front();
        q.pop();
        if(cnt[p].s) {
            c++;
        }
    }


}