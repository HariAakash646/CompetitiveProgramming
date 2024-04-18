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

vi disset, sze;
vi cnt;
int ma = 0;

int findf(int x) {
    while(x != disset[x]) {
        x = disset[x];
    }
    return x;
} 

void unionf(int x, int y) {
    x = findf(x);
    y = findf(y);
    if(sze[y] > sze[x]) swap(x, y);

    disset[y] = x;
    sze[x] = max(sze[x], sze[y]+1);
    cnt[x] += cnt[y];
    ma = max(ma, cnt[x]);
}

int main() {
    // usaco();
    int n, m, q;
    scd(n);
    scd(m);
    scd(q);

    vector<pair<int, pii>> edges(m);

    frange(i, m) {
        scd(edges[i].s.f);
        scd(edges[i].s.s);
        scd(edges[i].f);
    }
    sort(all(edges), greater<>());

    disset = sze = vi(n+1);
    cnt = vi(n+1, 1);
    forr(i, 1, n+1) disset[i] = i;
    int id = 0;
    vi out(n+1, -1);
    for(auto p : edges) {
        int a = p.s.f;
        int b = p.s.s;
        if(findf(a) != findf(b)) {
            unionf(a, b);
            forr(i, id+1, ma+1) {
                out[i] = p.f;
            }
            id = ma;
        }
    }

    frange(i, q) {
        int v;
        scd(v);
        if(v <= n)
        printf("%d\n", out[v]);
    else printf("-1\n");
    }
}