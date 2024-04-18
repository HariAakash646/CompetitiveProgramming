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

int n;
vii vec;

bool check(int k) {
    pii curr = mp(0, 0);
    frange(i, n) {
        if(vec[i].f > curr.s + k) return false;
        if(vec[i].s < curr.f - k) return false;
        curr.f = max(vec[i].f, curr.f - k);
        curr.s = min(vec[i].s, curr.s + k);
    }
    return true;
}

int main() {
    int t;
    scd(t);
    frange(_, t) {
        scd(n);
        vec = vii(n);
        frange(i, n) {
            scd(vec[i].f);
            scd(vec[i].s);
        }

        int lo = 0;
        int hi = 1e9;

        while(lo != hi) {
            int mid = (lo + hi)/2;
            if(check(mid)) {
                hi = mid;
            }
            else lo = mid+1;
        }
        printf("%d\n", lo);
    }
}