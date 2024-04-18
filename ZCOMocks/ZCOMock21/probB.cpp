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
    int l, r;
    scd(l);
    scd(r);

    set<pii> ran;

    frange(i, r) {
        int c;
        scd(c);
        int tot = 0;

        vi vec(c+1);
        forr(j, 1, c+1) {
            int a;
            scd(a);
            vec[j] = vec[j-1] + a;
            tot += a;
        }

        int x = l - tot;
        forr(j, 1, c+1) {
            int l1 = vec[j-1] + x;
            int r1 = vec[j];
            if(l1 < r1) ran.insert(mp(l1, r1));
        }
    }
    pii curr = mp(0, 0);
    int cnt = 0;
    for(auto p : ran) {
        if(p.f <= curr.s) {
            curr.s = max(curr.s, p.s);
        }
        else {
            cnt += curr.s - curr.f;
            curr = p;
        }
    }
    cnt += curr.s - curr.f;
    printf("%d", cnt);
}