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
    // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
    freopen("art2.in", "r", stdin);
   freopen("art2.out", "w", stdout);
}

int main() {
    usaco();
    int n;
    scd(n);
    vi vec(n);
    vi pos(n+1);
    frange(i, n) {
        scd(vec[i]);
        pos[vec[i]] = i;
    }

    stack<int> stk;
    int ma = 0;
    frange(i, n) {
        int a = vec[i];
        if(a == 0) {
            if(stk.size()) {
                printf("-1");
                return 0;
            }
            continue;
        }
        if(stk.size() && stk.top() == a) stk.pop();
        stk.push(a);
        ma = max(ma, (int)stk.size());
        if(i == pos[a]) {
            while(stk.size() && stk.top() == a) stk.pop();
        }
        
    }
    if(stk.size()) printf("-1");
    else printf("%d", ma);


}