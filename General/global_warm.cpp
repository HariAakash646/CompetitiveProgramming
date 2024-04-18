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
    int n;
    scd(n);
    
    vii vec(n);

    frange(i, n) {
        scd(vec[i].f);
        vec[i].s = i+1;
    }
    sort(all(vec), greater<>());

    vb vis(n+2);
    int c = 0;
    int ma = 0;
    frange(i, n) {
        auto p = vec[i];
        vis[p.s] = true;
        if(vis[p.s-1] && vis[p.s+1]) c--;
        if(!vis[p.s-1] && !vis[p.s+1]) c++;
        if(i+1<n && vec[i+1].f == p.f) continue;
        ma = max(ma, c);
    }
    printf("%d", ma);

    

}