#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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
    freopen("input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);
    vi vec(n+1);
    vec[n] = 0;
    bool z = false;
    frange(i, n) {
        scd(vec[i]);
        if(vec[i]==0) z = true;
    }
    if(z) n--;
    sort(vec.begin(), vec.begin()+n+1);
    int zer;
    frange(i, n+1) {
        if(vec[i]== 0) zer = i;
    }
    vector<vector<map<int, lli>>> dp1(n+1, vector<map<int, lli>>(n+1)), dp2(n+1, vector<map<int, lli>>(n+1));
    // cout << z << "\n";
    if(z) dp1[zer][zer][0] = dp2[zer][zer][0] = m;
    else
    dp1[zer][zer][0] = dp2[zer][zer][0] = 0;
    int mv = m;
    forr(l, 1, n+1) {
        for(int i=0; i+l<=n; i++) {
            int j = i+l;
            for(auto p : dp1[i][j-1]) {
                if(vec[j] == 0) m = 0;
                dp1[i][j][p.f+vec[j]-vec[j-1]] = max(dp1[i][j][p.f+vec[j]-vec[j-1]], p.s+max(0, m-(p.f + vec[j] - vec[j-1])));
                m = mv;
            }
            for(auto p : dp2[i][j-1]) {
                if(vec[j] == 0) m = 0;
                dp1[i][j][p.f+vec[j]-vec[i]] = max(dp1[i][j][p.f+vec[j]-vec[i]], p.s+max(0, m-(p.f + vec[j] - vec[i])));
                m = mv;
            }
            for(auto p : dp2[i+1][j]) {
                if(vec[i] == 0) m = 0;
                dp2[i][j][p.f+vec[i+1]-vec[i]] = max(dp2[i][j][p.f+vec[i+1]-vec[i]], p.s+max(0, m-(p.f+vec[i+1]-vec[i])));
                m = mv;
            }
            for(auto p : dp1[i+1][j]) {
                if(vec[i] == 0) m = 0;
                dp2[i][j][p.f+vec[j]-vec[i]] = max(dp2[i][j][p.f+vec[j]-vec[i]], p.s+max(0, m-(p.f + vec[j] - vec[i])));
                m = mv;
            }
            vi rem;
            lli ma = 0;
            for(auto p : dp1[i][j]) {
                if(p.s <= ma) rem.pb(p.f);
                ma = max(ma, p.s);
            }
            for(auto e : rem) dp1[i][j].erase(e);
            rem = {};
            ma = 0;
            for(auto p : dp2[i][j]) {
                if(p.s <= ma) rem.pb(p.f);
                ma = max(ma, p.s);
            }
            for(auto e : rem) dp2[i][j].erase(e);
        }
    }
    lli ma = 0;
    for(auto p : dp1[0][n]) {
        ma = max(ma, p.s);
    }
    for(auto p : dp2[0][n]) {
        ma = max(ma, p.s);
    }
    printf("%lld", ma);

}