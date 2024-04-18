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

bool cmp(pii &x, pii &y) {
    if(x.f < y.f) return true;
    else if(x.f == y.f) return x.s > y.s;
    else return false;
}

int main() {
    usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n, k;
        scd(n);
        vii vec(n);
        frange(i, n) {
            scd(vec[i].f);
            vec[i].s = i;
        }
        sort(all(vec), cmp);
        scd(k);
        int id = -1;
        mpii val;
        int tot = 0;
        int lim = 1e9;
        for(auto p : vec) {
            if(p.s > id) {
                int c = k / (p.f-tot);
                c = min(c, lim);
                if(c > 0) {
                    val[p.s] = c;
                    lim = c;
                    id = p.s;
                    k -= c*(p.f-tot);
                    tot = p.f;
                }
                else break;
            }
        }
        id = -1;
        for(auto p : val) {
            forr(i, id+1, p.f+1) printf("%d ", p.s);
            id =p.f;
        }
        forr(i, id+1, n) printf("%d ", 0);
        printf("\n");
    }
}