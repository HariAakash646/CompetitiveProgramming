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
    int t;
    scd(t);
    frange(_, t) {
        int a, b, c, d, k;
        scd(a);
        scd(b);
        scd(c);
        scd(d);
        scd(k);
        // queue<pair<pii, int>> q;
        // q.push(mp(mp(a, b), 0));
        // int c1 = 0;
        // int out = -1;
        // while(c1 <= 1030) {
        //     c1++;
        //     pair<pii, int> p = q.front();
        //     if(p.f == mp(c, d)) {
        //         out = p.s;
        //         break;
        //     }
        //     q.pop();
        //     pii p2 = p.f;
        //     p2.f = p2.f & p2.s;
        //     q.push(mp(p2, p.s+1));
        //     pii p3 = p.f;
        //     p3.f = p3.f | p3.s;
        //     q.push(mp(p3, p.s+1));
        //     pii p4 = p.f;
        //     p4.s = p4.s ^ p4.f;
        //     q.push(mp(p4, p.s+1));
        //     pii p5 = p.f;
        //     p5.s = p5.s ^ k;
        //     q.push(mp(p5, p.s+1));
        // }
        pii p = mp(a, b);
        int out = -1;
        if(p == mp(c, d)) {
            out = 0;
        }
        frange(i, 1024+1) {
            pii p1 = p;
            int v = i;
            
            frange(j, 5) {
                if(v % 4 == 0) {
                    p1.f = p1.f & p1.s;
                }
                else if(v % 4 == 1) {
                    p1.f = p1.f | p1.s;
                }
                else if(v % 4 == 2) {
                    p1.s = p1.s ^ k;
                }
                else {
                    p1.s = p1.s ^ p1.f;
                }
                v /= 4;
                if(p1 == mp(c, d)) {
                    if(out == -1) out = j+1;
                    else
                    out = min(out, j+1);

                }
            }
        }
        printf("%d\n", out);
    }
}