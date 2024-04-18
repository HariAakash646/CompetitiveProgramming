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

int n, m;
vi a, b;

bool check(int x) {
    forr(i, x, n) {
        if(a[i-x] >= b[i]) return false;
    }
    return true;
}

int main() {
    usaco();
    int t;
    scd(t);
    frange(_, t) {
        scd(n);
        scd(m);
        a = b = vi(n);
        a[0] = 1;
        forr(i, 1, n) scd(a[i]);
        frange(i, n) scd(b[i]);

        sort(all(a));
        sort(all(b));

        int lo = 0;
        int hi = n;

        while(lo != hi) {
            int mid = (lo + hi)/2;
            if(check(mid)) hi = mid;
            else lo = mid+1;
        }
        mseti st1, st2;
        // vii val(n-lo, mp(1e9, 0));
        forr(i, 1, n-lo) 
        {
            st1.insert(a[i]);
            // val[i-1].f = a[i];
        }
        forr(i, lo, n-1) {
            st2.insert(b[i]);
            // if(b[i] < val[i-lo].f) val[i-lo] = mp(b[i]-1, 1);
        }
        
        lli tot = 0;
        tot += lo;
        int v = 1;
        auto it1 = st1.begin();
        auto it2 = st2.begin();
        while(v < m && st1.size()) {
            if(*(st1.begin()) < *st2.begin()) {
                int nx = *(st1.begin());
                st1.erase((st1.begin()));
                if(nx > m) tot += (m - v) * lo;
                else 
                tot += lli(nx - v) * lo;
                st2.erase(st2.begin());
                // printf("%lld %d %d %d\n", tot, v, nx, lo);
                v = nx;
            }
            else {
                int nx = *st2.begin();
                if(nx > m)
                    {tot += lli(m - v) * lo;}
                else
                {tot += lli(nx - v - 1) * lo; tot += lo+1; lo++;}
                
                
                st2.erase(st2.begin());
                st1.erase(prev(st1.upper_bound(m)));
                // printf("%lld %d %d %d\n", tot, v, nx, lo);
                v = nx;

            }
        }
        int va = b[n-1];
        if(m > v) {
            if(m < va)
            tot += (m-v)*(lo);
            else {
                
                tot += lli(va - v - 1) * lo;
                tot += lli(m - va + 1) * (lo+1);
                // printf("%d %d ", v, va);
            }
        }
        printf("%lld\n", tot);

    }
}