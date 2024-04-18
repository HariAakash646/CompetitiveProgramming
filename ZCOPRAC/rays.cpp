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
    int n, m;
    scd(n);
    scd(m);

    int w, b;
    scd(w);
    scd(b);

    vvi wpos(n+1), bpos(n+1);
    vector<vii> pos(n+1);

    frange(i, w) {
        int x, y;
        scd(x);
        scd(y);
        wpos[x].pb(y);
        pos[x].pb(mp(y, 0));
    }

    frange(i, b) {
        int x, y;
        scd(x);
        scd(y);
        bpos[x].pb(y);
        pos[x].pb(mp(y, 1));
    }

    
    lli tot = 0;
    forr(i, 1, n+1) {
        
        sort(all(pos[i]));
        sort(all(wpos[i]));
        sort(all(bpos[i]));

        if(pos[i].empty() || pos[i].back().f != m) {
            tot++;
            pos[i].pb(mp(m, 1));
        }
        else if(pos[i].back().s == 0) pos[i].back().s = 1;

        

        lli l = 1;

        for(auto p : pos[i]) {
            if(p.s == 1)
                tot += (p.f - l) * (p.f - l + 1) / 2 + (p.f - l);
            else {
                auto it = upper_bound(all(pos[i]), p);
                tot += (p.f - l) * (p.f - l + 1) / 2 + (p.f-l);
                tot += ((*it).f - p.f) * (p.f - l);
            }
            l = p.f + 1;
        }
    }
    printf("%lld", tot);

    


}