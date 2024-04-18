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
    // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
    freopen("cowrect.in", "r", stdin);
   freopen("cowrect.out", "w", stdout);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    usaco();
    int n;
    cin >> n;
    vvi pos(1001);
    seti st;

    vvi hols(1001, vi(1001));
    vvi gols(1001, vi(1001));

    frange(i, n) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if(c == 'H') {
            st.insert(x);
            pos[x].pb(y);
            hols[x][y] = 1;
        }
        else gols[x][y] = 1;
    }

    frange(x, 1001) {
        frange(y, 1001) {
            if(x > 0) {
                hols[x][y] += hols[x-1][y];
                gols[x][y] += gols[x-1][y];
            }
            if(y > 0) {
                hols[x][y] += hols[x][y-1];
                gols[x][y] += gols[x][y-1];
            }
            if(x > 0 && y > 0) {
                hols[x][y] -= hols[x-1][y-1];
                gols[x][y] -= gols[x-1][y-1];
            }
        }
    }

    pii ma = mp(0, 0);

    for(auto l : st) {
        vi vec;
        for(auto r : st) {
            if(r < l) continue;
            // printf("%d %d\n", l, r);
            for(auto e : pos[r]) vec.pb(e);
            sort(all(vec));
            frange(i, vec.size()) {
                int t = vec[i];
                int lo = i;
                int hi = vec.size()-1;
                while(lo != hi) {

                    int mid = (lo + hi+1)/2;
                    int b = vec[mid];

                    int v = gols[r][b];
                    if(l > 0) 
                        v -= gols[l-1][b];
                    if(t > 0)
                        v -= gols[r][t-1];
                    if(l > 0 && t > 0)
                        v += gols[l-1][t-1];
                    // printf("%d %d %d\n", t, b, v);
                    if(v == 0) lo = mid;
                    else hi = mid-1;
                }
                int b = vec[lo];
                int v = gols[r][b];
                if(l > 0) 
                    v -= gols[l-1][b];
                if(t > 0)
                    v -= gols[r][t-1];
                if(l > 0 && t > 0)
                    v += gols[l-1][t-1];
                if(v == 0) {
                    int area = (b-t) * (r-l);
                    ma = max(ma, mp(lo-i+1, -area));
                }
                // printf("%d %d %d %d\n", l, r, t, b);
            }
        }
    }
    cout <<  ma.f << "\n" << -ma.s;
}