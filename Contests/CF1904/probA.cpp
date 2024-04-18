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
    int t;
    scd(t);

    frange(_, t) {
        int a, b, x1, y1, x2, y2;
        pii p1, p2;
        scd(a);
        scd(b);
        scd(x1);
        scd(y1);
        scd(x2);
        scd(y2);

        p1 = mp(x1, y1);
        p2 = mp(x2, y2);

        pii dir = mp(a, b);

        vi vec = {-1, 1};
        int tot = 0;
        for(auto e : vec) {
            for(auto c : vec) {
                pii pn;
                pn.f = p1.f + a * e;
                pn.s = p1.s + b * c;
                pii pn2 = mp(abs(pn.f - p2.f), abs(pn.s - p2.s));
                if((pn2.f == a && pn2.s == b) || (pn2.f == b && pn2.s == a)) tot++;
            }
        }

        if(a!=b){for(auto e : vec) {
                    for(auto c : vec) {
                        pii pn;
                        pn.f = p1.f + b * e;
                        pn.s = p1.s + a * c;
                        pii pn2 = mp(abs(pn.f - p2.f), abs(pn.s - p2.s));
                        if((pn2.f == a && pn2.s == b) || (pn2.f == b && pn2.s == a)) tot++;
                    }
                }}

        printf("%d\n", tot);



    }
}