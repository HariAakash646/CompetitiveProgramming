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

const lli mod = 1e9 + 7;
vi vec;
vector<vll> lef, rig;
vll out;
int n, k;

void rec(int l, int r, vector<pair<pii, int>> quer) {
    if(l >= r) {
        for(auto p : quer) out[p.s] = 2;
        return;
    }
    int mid = (l+r)/2;

    forr(i, l, mid+1) {
        frange(j, k) lef[i][j] = 0;
    }
    forr(i, mid+1, r+1) {
        frange(j, k) rig[i][j] = 0;
    }
    vector<vll> tot(k, vll(k));
    for(int i=mid; i>=l; i--) {
        lef[i][vec[i]]++;
        frange(j, k) {
            
            lef[i][j] += tot[j][vec[i]];
            lef[i][j] %= mod;
            
            lli v = lef[i][j];
            lef[i][j] += tot[j][0];
            lef[i][j] %= mod;
            frange(e, vec[i]+1) {
                tot[j][e] += v;
                if(tot[j][e] >= mod)
                    tot[j][e] -= mod;
            }
            
        }
    }
    tot = vector<vll>(k, vll(k));
    forr(i, mid+1, r+1) {
        rig[i][vec[i]]++;
        frange(j, k) {
            rig[i][j] += tot[j][vec[i]];
            rig[i][j] %= mod;
            
            lli v = rig[i][j];
            rig[i][j] += tot[j][k-1];
            rig[i][j] %= mod;
            forr(e, vec[i], k) {
                tot[j][e] += v;
                if(tot[j][e] >= mod) tot[j][e] -= mod;
            }
            
        }
        for(int j=k-2; j>=0; j--) {
            rig[i][j] += rig[i][j+1];
            rig[i][j] %= mod;
        }
    }

    vector<pair<pii, int>> lv, rv;

    for(auto p : quer) {
        if(p.f.f <= mid && p.f.s > mid) {
            lli tot = 0;
            frange(j, k) {
                tot += lef[p.f.f][j] * (rig[p.f.s][j]+1);
                tot %= mod;
            }
            tot += rig[p.f.s][0] + 1;
            tot %= mod;
            out[p.s] = tot;
        }
        else if(p.f.s <= mid) lv.pb(p);
        else rv.pb(p);
    }
    rec(l, mid, lv);
    rec(mid+1, r, rv);
}

int main() {
    // usaco();
    freopen("nondec.in", "r", stdin);
    freopen("nondec.out", "w", stdout);
    scd(n);
    scd(k);

    vec = vi(n+1);
    forr(i, 1, n+1) {scd(vec[i]); vec[i]--;}
    int q;
    scd(q);

    vector<pair<pii, int>> quer(q);

    frange(i, q) {
        scd(quer[i].f.f);
        scd(quer[i].f.s);
        quer[i].s = i;
    }

    lef = rig = vector<vll>(n+1, vll(k));
    out = vll(q);

    rec(1, n, quer);

    frange(i, q) printf("%lld\n", out[i]);
}
