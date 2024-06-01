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

vector<vii> disset(601, vii(601));
vvi sze(601, vi(601));

pii findf(pii p) {
    if(disset[p.f][p.s] == p) return p;
    disset[p.f][p.s] = findf(disset[p.f][p.s]);
    return disset[p.f][p.s];
}

void unionf(pii p1, pii p2) {
    p1 = findf(p1);
    p2 = findf(p2);
    if(p1 == p2) return;
    if(sze[p1.f][p1.s] < sze[p2.f][p2.s]) swap(p1, p2);
    disset[p2.f][p2.s] = p1;
    sze[p1.f][p1.s] = max(sze[p1.f][p1.s], sze[p2.f][p2.s] + 1);
}

int main() {
    usaco();
    int n;
    scd(n);
    if(n <= 2) {
        printf("-1");
        return 0;
    }
    vii vec(n);
    seti st1, st2, st3, st4;
    frange(i, n) {
        int x, y;
        scd(x);
        scd(y);
        st1.insert(x);
        st2.insert(y);
        st3.insert(x-y);
        st4.insert(x+y);
        // x+=300;
        // y+=300;
        vec[i] = mp(x, y);
    }

    if(st1.size()==1 || st2.size()==1 || st3.size() == 1 || st4.size() == 1) {
        printf("-1");
        return 0;
    }

    frange(i, 601) {
        frange(j, 601) disset[i][j] = mp(i, j);
    }

    forr(i, -600, 601) {
        forr(j, -600, 601) {
            pii pre = mp(-1, -1);
            frange(k, n) {
                if(vec[k].f+i>=0 && vec[k].f+i<=600 && vec[k].s+j>=0 && vec[k].s+j<=600) {
                    if(pre.f != -1) unionf(pre, mp(vec[k].f+i, vec[k].s+j));
                    pre = mp(vec[k].f+i, vec[k].s+j);
                }
            }
        }
    }

    int c = 0;
    map<pii, int> mv;
    frange(i, 20) {
        frange(j, 20) {
            if(disset[i][j] == mp(i, j)) {mv[mp(i, j)] = c++;}
            printf("%d ", mv[findf(mp(i, j))]);
        }
        printf("\n");
    }
    printf("%d", c);
}