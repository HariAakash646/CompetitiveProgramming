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

int query(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);

    int sc;
    scd(sc);
    return sc;

}

int main() {
    int r, c, k;

    scd(r);
    scd(c);
    scd(k);

    int rl=1, rh=r;
    int cl=1, ch=c;

    int fr = 1, fc = 1;
    int ansr, ansc;

    if(c == 1) {
        ansc = 1;
        fc = 0;
    }

    if(r == 1) {
        ansr = 1;
        fr = 0;
    }

    while(fc || fr) {
        int midr, midc;

        if(fr) {
            midr = (rl + rh)/2;
        }
        else {
            midr = ansr;
        }

        if(fc) {
            midc = (cl + ch)/2;
        }
        else midc = ansc;

        int v = query(midr, midc);

        if(fr) {
            int v2 = query(midr+1, midc);
            if(v2 == v) {
                ansr = midr;
                fr = 0;
            }
            else if(v2 < v) {
                rl = midr+1;
            }
            else {
                rh = midr;
            }
        }

        if(fc) {
            int v2 = query(midr, midc+1);
            if(v2 == v) {
                ansc = midc;
                fc = 0;
            }
            else if(v2 < v) {
                cl = midc+1;
            }
            else {
                ch = midc;
            }
        }

        if(rl == rh) {
            ansr = rl;
            fr = 0;
        }
        if(cl == ch) {
            ansc = cl;
            fc = 0;
        }

    }
    printf("! %d", query(ansr, ansc));
    fflush(stdout);
}