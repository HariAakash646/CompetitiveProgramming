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

vi sze, disset;

int findf(int x)
{
    while (x != disset[x])
    {
        x = disset[x];
    }
    return x;
}

void unionf(int x, int y)
{
    x = findf(x);
    y = findf(y);
    if (x == y)
        return;
    if (sze[x] < sze[y])
    {
        swap(x, y);
    }
    disset[y] = x;
    sze[x] = max(sze[x], sze[y] + 1);
}

int main() {
    // usaco();
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);

    sze = vi(n+1, 1);
    disset = vi(n+1);

    forr(i, 1, n+1) disset[i] = i;

    set<pii> edge;

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        if(a > b) swap(a, b);
        edge.insert(mp(a, b));
    }

    vii quer(k);

    frange(i, k) {
        scd(quer[i].f);
        scd(quer[i].s);
        if(quer[i].f > quer[i].s) swap(quer[i].f, quer[i].s);
        edge.erase(mp(quer[i].f, quer[i].s));
    }

    int c = n;
    for(auto p : edge) {
        if(findf(p.f) != findf(p.s)) {
            unionf(p.f, p.s);
            c--;
        }
    }

    vi out(k);

    for(int i=k-1; i>=0; i--) {
        pii p = quer[i];
        out[i] = c;
        if(findf(p.f) != findf(p.s)) {
            unionf(p.f, p.s);
            c--;
        }
    }

    for(auto e : out) printf("%d ", e);
}