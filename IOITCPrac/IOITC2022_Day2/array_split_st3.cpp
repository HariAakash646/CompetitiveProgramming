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

int n, k;
vll vec, pref;
map<lli, int> mv;

void ins(lli v, int x) {
    auto it = mv.lower_bound(v);
    if(it != mv.end()) {
        if((*it).s <= x) return;
    }
    mv[v] = x;
    it = mv.find(v);
    while(it != mv.begin()) {
        it--;
        if((*it).s >= x) mv.erase(it);
        else break;
        it = mv.find(v);
    }
}

int query(lli v) {
    auto it = mv.lower_bound(v);
    if(it == mv.end()) return 1e9;
    else return (*it).s;
}

bool check(lli x) {
    lli curr = 0;
    int c = 1;
    forr(i, 1, n+1) {
        curr += vec[i];
        if(curr > x) {
            curr = vec[i];
            c++;
        }
    }
    return c <= k;
}

int main() {
    // usaco();
    scd(n);
    scd(k);

    pref = vec = vll(n+1);
    forr(i, 1, n+1) sclld(vec[i]);
    forr(i, 1, n+1) pref[i] = pref[i-1] + vec[i];

    lli lo = *max_element(all(vec));
    lli hi = 1e15;

    while(lo != hi) {
        lli mid = lo + (hi-lo)/2;
        if(check(mid)) hi = mid;
        else lo = mid+1;
    }
    printf("%lld\n", lo);
}