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
    int n;
    scd(n);
    vi vec(n+2);
    frange(i, n) scd(vec[i+1]);

    vi r(n+1), l(n+1);

    stack<pii> stk;
    forr(i, 1, n+1) {
        while(stk.size() && stk.top().f >= vec[i]) stk.pop();
        if(stk.size()) {
            l[i] = stk.top().s;
        }
        else l[i] = 0;
        stk.push(mp(vec[i], i));
    }
    stk = {};
    for(int i=n; i>=1; i--) {
        while(stk.size() && stk.top().f >= vec[i]) stk.pop();
        if(stk.size()) {
            r[i] = stk.top().s;
        } 
        else r[i] = n+1;
        stk.push(mp(vec[i], i));
    }
    vi out(n+1, 0);
    forr(i, 1, n+1) {
        out[r[i] - l[i] - 1] = max(out[r[i] - l[i] - 1], vec[i]);
    }
    for(int i=n-1; i>=1; i--) out[i] = max(out[i], out[i+1]);
    forr(i, 1, n+1) printf("%d ", out[i]);
}