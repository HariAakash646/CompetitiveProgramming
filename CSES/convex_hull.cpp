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

bool cmp(pii x, pii y) {
    if(x.f < y.f) return true;
    else if(x.f == y.f) {
        return x.s > y.s;
    }
    else return false;
}

int area(pii O, pii P, pii Q) {
    return (P.first - O.first) * (Q.second - O.second) -
           (P.second - O.second) * (Q.first - O.first);
}


int main() {
    // usaco();
    int n;
    scd(n);

    vii vec(n);

    frange(i, n) {
        scd(vec[i].f);
        scd(vec[i].s);
    }
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());
    n = vec.size();
    vector<pii> stk;

    for(auto p : vec) {
        while(stk.size() >= 2 && area(stk[stk.size()-2], stk.back(), p) <= 0) stk.pop_back();
        stk.pb(p);
    }

    // for(auto p : stk) pts.insert(p);
    // stk = {};
    // sort(all(vec), cmp);
    vec.pop_back();
    reverse(all(vec));
    
    int low_len = stk.size();
    for(auto p : vec) {
        while(stk.size() > low_len && area(stk[stk.size()-2], stk.back(), p) <= 0) stk.pop_back();
        stk.pb(p);
    }
    stk.pop_back();
    printf("%d\n", (int)stk.size());
    for(auto p : stk) printf("%d %d\n", p.f, p.s);
}