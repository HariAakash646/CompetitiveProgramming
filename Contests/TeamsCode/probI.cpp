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

int n, q;

vector<vi> minv;
vi vec;

void init() {
    minv = vector<vi>(21, vi(n+1));
    frange(i, n+1) minv[0][i] = vec[i];

    forr(i, 1, 21) {
        frange(j, n+1) {
            minv[i][j] = max(minv[i-1][j], minv[i-1][min(n, j+(1<<(i-1)))]);
        }
    }
}

int query(int l, int r) {
    // r++;
    int ln = r - l +1;
    int msb = 31 - __builtin_clz(ln);

    return max(minv[msb][l], minv[msb][r-(1<<msb)+1]);
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        
        scd(n);
        scd(q);

        vec = vi(n+1);
        forr(i, 1, n+1) scd(vec[i]);

        init();

        vi pref(n+1);
        vi prid(n+1, n+1);
        pref[0] = -1e9;
        forr(i, 1, n+1) {
            if(vec[i] > pref[i-1]) {
                pref[i] = vec[i];
                prid[i] = i;
            }
            else if(pref[i-1] > vec[i]) {
                pref[i] = pref[i-1];
                prid[i] = prid[i-1];
            }
            else {
                pref[i] = -1e9;
                prid[i] = n+1;
            }
        }

        vi suf(n+2, -1e9), sfid(n+2, n+1);
        suf[n] = vec[n];
        sfid[n] = n;
        for(int i=n-1; i>=1; i--) {
            int lo = i+1;
            int hi = n;
            while(lo != hi) {
                int mid = (lo+hi)/2;
                if(query(i+1, mid) >= vec[i]) {
                    hi = mid;
                }
                else lo = mid+1;
            }
            int v = query(i+1, lo);
            if(v < vec[i]) {
                suf[i] = vec[i];
                sfid[i] = i;
            }
            else if(v == vec[i]) {
                suf[i] = suf[lo+1];
                sfid[i] = sfid[lo+1];
            }
            else {
                suf[i] = suf[lo];
                sfid[i] = sfid[lo];
            }
        }

        frange(_, q) {
            int l, r, x;
            scd(l);
            scd(r);
            scd(x);
            int v = pref[l-1];
            int id = prid[l-1];
            int len = r-l+1;
            if(v < x) {
                if(len % 2) {
                    v = x;
                    id = r;
                }
                else {
                    v = -1e9;
                    id = n+1;
                }
            } 
            else if(v == x) {
                len++;
                if(len % 2) {
                    v = x;
                    id = r;
                }
                else {
                    v = -1e9;
                    id = n+1;
                }
            }
            if(r == n) {
                printf("%d\n", id);
                continue;
            }

            int lo = r+1;
            int hi = n;

            while(lo != hi) {
                int mid = (lo+hi)/2;
                if(query(r+1, mid) >= v) {
                    hi = mid;
                }
                else lo = mid+1;
            }
            int v1 = query(r+1, lo);
            
            // printf("%d %d %d %d ", v, id, v1, lo);
            if(v1 < v) {
                printf("%d\n", id);
            }
            else if(v1 == v) {
                printf("%d\n", sfid[lo+1]);
            }
            else {
                printf("%d\n", sfid[lo]);
            }
        }
    }


}