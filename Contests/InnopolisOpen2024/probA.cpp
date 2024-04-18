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

void fastio() {
    ios_base::sync_with_stdio();
    cin.tie(0);
    // cout.tie(0);
}

int main() {
    usaco();
    fastio();
    int n;
    cin >> n;

    vector<pair<pair<ld, ld>, int>> vec(n);

    ld tot = 0;
    frange(i, n) {
        cin >> vec[i].f.s >> vec[i].f.f;
        vec[i].s = i;
        tot += vec[i].f.s;
    }
    cout << fixed << setprecision(10);
    sort(all(vec));
    ld ti = 0;
    ld mul = 1;
    ld premul = 1;
    vector<ld> out(n);
    out[vec[0].s] = vec[0].f.f;
    ti = vec[0].f.f;
    forr(i, 1, n) {
        lli tv = tot - vec[i-1].f.s;
        ld v = vec[i-1].f.s;
        vec[i].f.s += vec[i].f.s / tv * vec[i-1].f.s;
        vec[i].f.f -= ti;
        ti += vec[i].f.f * (v/vec[i].f.s);
        out[vec[i].s] = ti;
    }


    for(auto e : out) cout << e << "\n";

    

}