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
        int n;
        scd(n);
        pii ran = mp(0, 1e9+5);
        seti st;
        frange(i, n) {
            int a;
            int x;
            scd(a);
            scd(x);
            if(a == 1) {
                ran.f = max(ran.f, x);
            }
            else if(a == 2) {
                ran.s = min(ran.s, x);
            }
            else st.insert(x);
        }

        if(ran.f <= ran.s) {
            int c = ran.s - ran.f + 1;
            for(auto e : st) {
                if(ran.f <= e && e <= ran.s) c--;
            }
            printf("%d\n", c);
        }
        else printf("0\n");
    }
}