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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void usaco() {
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}


int main()
{
    // usaco();
    fastio();
    lli m;
    int n;
    cin >> m >> n;
    cout << fixed << setprecision(9);
    frange(i, n)
    {
        lli l1, h1, l2, h2;
        lli p1, p2;
        cin >> l1 >> h1 >> p1 >> l2 >> h2 >> p2;
        // p1 /= 100;
        // p2 /= 100;
        if (p2 < p1)
        {
            swap(l1, l2);
            swap(h1, h2);
            swap(p1, p2);
        }
        ld tot = m;
        if(m >= l2) {
            tot += ld(p2)/100 * min(h2, m);
            lli m1 = m - min(h2, m);
            if(m1 >= l1) {
                tot += ld(p1)/100 * min(h1, m1);
            }
        }
        ld tot2 = m;
        if(m >= l1) tot2 += ld(p1)/100 * min(h1, m);
        tot = max(tot, tot2);
        tot2 = m;
        lli m1 = m;
        if(m >= l1) {
            tot2 += l1 * ld(p1)/100;
            m1 -= l1;
        }
        if(m1 >= l2)
            tot2 += ld(p2)/100 * min(h2, m1);
        tot = max(tot, tot2);
        cout << tot << "\n";
    }
}