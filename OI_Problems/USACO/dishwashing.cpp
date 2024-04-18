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
    freopen("dishes.in", "r", stdin);
   freopen("dishes.out", "w", stdout);
}

vi vec;

bool check(int x) {
    vector<stack<int>> q;
    vb vis(x);
    vii val;
    frange(i, x) val.pb(mp(vec[i], i));
    sort(all(val));
    int curr = 0;
    vi ord;
    int si = 0;
    frange(i, x) {
        int id = upper_bound(all(ord), vec[i]) - ord.begin();
        if(id == ord.size()) {
            ord.pb(vec[i]);
            stack<int> tmp;
            tmp.push(vec[i]);
            q.pb(tmp);
        }
        else {
            ord[id] = vec[i];
            q[id].push(vec[i]);
        }
        while(val[curr].s <= i) {
            if(si < q.size() && q[si].top() == val[curr].f) {
                q[si].pop();
                curr++;
                if(q[si].size()) {
                    ord[si] = q[si].top();
                }
                else {
                    ord[si] = -1e9;
                    si++;
                }
            }
            else {
                return false;
            }
            if(curr >= val.size()) break;
        }
    }
    return true;
}

int main() {
    usaco();
    int n;
    scd(n);

    vec = vi(n);
    frange(i, n) scd(vec[i]);

    int lo = 1;
    int hi = n;
    while(lo != hi) {
        int mid = (lo + hi+1)/2;
        if(check(mid)) lo = mid;
        else hi = mid-1;
    }
    printf("%d", lo);

}