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
        int n, q;
        scd(n);
        scd(q);

        vll vec(n+1), sum(n+1), xo(n+1);
        forr(i, 1, n+1) {
            sclld(vec[i]);
            sum[i] = sum[i-1] + vec[i];
            xo[i] = xo[i-1] ^ vec[i];
        }

        frange(i, q) {
            int l, r;
            scd(l);
            scd(r);
            lli v = sum[r] - sum[l-1] - (xo[r] ^ xo[l-1]);

            int lo = l;
            int hi = r;
 
            while(lo != hi) {
                int mid = (lo + hi)/2;
                lli v2 = sum[mid] - sum[l-1] - (xo[mid] ^ xo[l-1]);
                if(v2 == v) hi = mid;
                else lo = mid+1;
            }
 
            int lo2 = l;
            int hi2 = lo;
            while(lo2 != hi2) {
                int mid = (lo2 + hi2+1)/2;
                lli v2 = sum[lo] - sum[mid-1] - (xo[lo] ^ xo[mid-1]);
                if(v2 == v) lo2 = mid;
                else hi2 = mid-1;
            }
            
            pii p1 = mp(lo2, lo);
            
            lo2 = l;
            hi2 = r;
            while(lo2 != hi2) {
                int mid = (lo2 + hi2+1)/2;
                lli v2 = sum[r] - sum[mid-1] - (xo[r] ^ xo[mid-1]);
                if(v2 == v) lo2 = mid;
                else hi2 = mid-1;
            }

            lo = lo2;
            hi = r;

            while(lo != hi) {
                int mid = (lo + hi)/2;
                lli v2 = sum[mid] - sum[lo2-1] - (xo[mid] ^ xo[lo2-1]);
                if(v2 == v) hi = mid;
                else lo = mid+1;
            }

            pii p2 = mp(lo2, lo);

            if(p1.s - p1.f < p2.s - p2.f) printf("%d %d\n", p1.f, p1.s);
            else printf("%d %d\n", p2.f, p2.s);
        }
    }
}