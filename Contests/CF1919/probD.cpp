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

bool inter(pii p1, pii p2) {
    if(p2.s < p1.f || p2.f > p1.s) return false;
    else return true;
}

int main() {
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n;
        scd(n);
        stack<pii> stk;

        frange(i, n) {
            int x;
            scd(x);
            pii p = mp(x, x);
            while(stk.size()) {
                auto p2 = stk.top();
                // p2.f--;
                // p2.s--;

                if(inter(p, p2)) {
                    p = mp(max(p.f, p2.f), min(p.s, p2.s));
                    p.f--;
                    stk.pop();
                }
                else {

                    // p2.f--;
                    // p2.s++;
                    // printf("p2: %d %d\n", p2.f, p2.s);
                    if(min(p2.s, p.s) + 1 == max(p.f, p2.f)) {
                        p = mp(min(p2.s, p.s), min(p2.s, p.s));
                        stk.pop();
                    }
                    else break;
                }
            }
            // printf("%d %d\n", p.f, p.s);
            stk.push(p);
        }
        if(stk.size() == 1) {
            auto p = stk.top();
            if(p.f <= 0 && 0 <= p.s) printf("YES\n");
            else printf("NO\n");
            // printf("YES\n");
        }
        else printf("NO\n");
    }
}