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
   //  freopen("exercise.in", "r", stdin);
   // freopen("exercise.out", "w", stdout);
}

int n;
lli m;

lli binexp(lli x, int c) {
    if(c == 0) return 1;
    lli v = binexp(x, c/2);

    v = (v * v) % m;
    if(c % 2) return (v * x) % m;
    else return v;
}

vi disset, sze;

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
    scd(n);
    sclld(m);

    vll vec(n+1);
    forr(i, 1, n+1) sclld(vec[i]);

    vector<pair<lli, pii>> edges;

    forr(i, 1, n+1) {
        forr(j, i+1, n+1) {
            lli v = (binexp(vec[i], vec[j]) + binexp(vec[j], vec[i])) % m;
            edges.pb(mp(v, mp(i, j)));
        }
    }

    sort(all(edges), greater<>());

    disset = sze = vi(n+1);
    forr(i, 1, n+1) disset[i] = i;
    lli tot = 0;
    for(auto p :edges) {
        if(findf(p.s.f) != findf(p.s.s)) {
            unionf(p.s.f, p.s.s);
            tot += p.f;
        }
    }
    printf("%lld", tot);
}