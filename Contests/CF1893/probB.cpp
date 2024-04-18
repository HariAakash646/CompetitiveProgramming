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
        int n, m;
        scd(n);
        scd(m);
        vi v1(n), v2(m);

        vii lis(n+1, mp(1e9 + 10, 0));

        frange(i, n) scd(v1[i]);
        frange(i, m) scd(v2[i]);

        // lis[0] = mp(-1, -1);
        // vvi pre(n+1);
        // frange(i, n) {
        //     int v = v1[i];
        //     int it = lower_bound(all(lis), mp(v, 0)) - lis.begin();
        //     if(lis[it].f != v)
        //     {
        //         pre[it].pb(i);
        //         lis[it] = mp(v, i);
        //     }
        // }



        // int v = 0;
        // forr(i, 1, n+1) {
        //     if(lis[i].f != 1e9 + 10) v = i;
        // }

        vi pref(n);

        pref[0] = v1[0];
        forr(i, 1, n) pref[i] = min(pref[i-1], v1[i]);

        // int ma = lis[v].f;

        // for(int i=v-1; i>=1; i--) {
        //     int va = *prev(lower_bound(all(pre[i]), lis[i+1].s));
        //     lis[i] = mp(v1[va], va);
        // }
        
        vvi val(n);
        vi out;

        for(auto e : v2) {
            int lo = 0;
            int hi = n;
            while(lo != hi) {
                int mid = (lo + hi)/2;
                if(pref[mid] <= e) hi = mid;
                else lo = mid+1;
            }
            // printf("%d ", lo);
            int id = lo;
            if(id != n) {
                val[id].pb(e);
            }
            else {
                out.pb(e);
            }
        }

        // forr(i, 1, v+1) printf("%d ", lis[i].s);
        

        frange(i, n) {
            sort(all(val[i]), greater<int>());
            for(auto e : val[i]) printf("%d ", e);
            printf("%d ", v1[i]);
        }
        sort(all(out), greater<int>());
        for(auto e : out) printf("%d ", e);
        printf("\n");
        
    }
}
