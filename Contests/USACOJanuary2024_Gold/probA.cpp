#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<lli> vll;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}


int main() {
    // usaco();
    fastio();
    int n, q;
    cin >> n >> q;

    vi he, ho, ve, vo, hori, vert;

    frange(i, n) {
        char c;
        int v;
        cin >> c >> v;
        if(c == 'V') {
            if(v % 2) vo.pb(v);
            else ve.pb(v);
            vert.pb(v);
        }
        else {
            if(v % 2) ho.pb(v);
            else he.pb(v);
            hori.pb(v);
        }
    }

    sort(all(he));
    sort(all(ho));
    sort(all(ve));
    sort(all(vo));
    sort(all(vert));
    sort(all(hori));

    frange(i, q) {
        int x, y, d;
        cin >> x >> y >> d;
        int v = 0;
        auto it = lower_bound(all(vert), x);
        auto it2 = lower_bound(all(hori), y);
        bool vr = false;
        if(it != vert.end() && *it == x) {
            vr = true;
        }


        while(true) {
            if(vr) {
                if(v % 2 == y % 2) {
                    auto it = upper_bound(all(ho), y);
                    if(it == ho.end()) {
                        y += d - v;
                        break;
                    }
                    if(*it - y >= d - v) {
                        y += d - v;
                        break;
                    }
                    v += *it - y;
                    y = *it;
                }
                else {
                    auto it = upper_bound(all(he), y);
                    if(it == he.end()) {
                        y += d - v;
                        break;
                    }
                    if(*it - y >= d - v) {
                        y += d - v;
                        break;
                    }
                    v += *it - y;
                    y = *it;
                }
                vr = false;
            }
            else {
                if(v % 2 == x % 2) {
                    auto it = upper_bound(all(ve), x);
                    if(it == ve.end()) {
                        x += d - v;
                        break;
                    }
                    if(*it - x >= d - v) {
                        x += d - v;
                        break;
                    }
                    v += *it - x;
                    x = *it;
                }
                else {
                    auto it = upper_bound(all(vo), x);
                    if(it == vo.end()) {
                        x += d - v;
                        break;
                    }
                    if(*it - x >= d - v) {
                        x += d - v;
                        break;
                    }
                    v += *it - x;
                    x = *it;
                }
                vr = true;
            }
        }
        cout << x << " " << y << "\n";
    }
}