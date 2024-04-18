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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    usaco();
    fastio();
    int n, q;
    cin >> n >> q;

    vector<ld> vec(n+1);
    forr(i, 1, n+1) {
        cin >> vec[i];
        vec[i] += 100;
    }

    vector<ld> cost(n+1, -1);
    vector<ld> val(n+1, 1e18);

    cout << fixed << setprecision(2);

    frange(_, q) {
        int t;
        cin >> t;

        if(t == 1) {
            int x, y;
            ld w;
            cin >> x >> y >> w;
            cout << val[y]*vec[y]/100 << " " << val[x]*vec[x]/100 << "\n";
            ld vx = min(w, val[y]*vec[y]/100);
            ld vy = min(w, val[x]*vec[x]/100);
            val[x] = min(val[x], vx);
            val[y] = min(val[y], vy);
        }
        else {
            int m;
            cin >> m;
            cout << val[m] << "\n";
        }
    }
}