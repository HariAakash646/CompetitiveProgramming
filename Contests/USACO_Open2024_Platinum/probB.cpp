#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int main() {
    // usaco();
    int n;
    scd(n);
    vll vec(n+1);
    forr(i, 1, n+1) sclld(vec[i]);

    int q;
    scd(q);
    // if(q <= 100) {
    //     frange(_, q) {
    //         int l, r;
    //         lli x;
    //         scd(l);
    //         scd(r);
    //         sclld(x);
    //         forr(i, l, r+1) {
    //             if(x > 0) x -= vec[i];
    //             else x += vec[i];
    //         }
    //         printf("%lld\n", x);
    //     }
    // }
    // else

     {
        vi idx(n+1);
        lli curr = 0;
        int id = 0;
        for(int i=n; i>=1; i--) {
            if(vec[i] != curr) {
                curr = vec[i];
                id = i;
            }
            idx[i] = id;
        }

        vll pref(n+1);
        forr(i, 1, n+1) pref[i] = pref[i-1] + vec[i];

        frange(_, q) {
            int l, r;
            lli x;
            scd(l);
            scd(r);
            sclld(x);
            int id = l;
            while(id <= r) {
                if(x > 0) {
                    int idt = lower_bound(all(pref), x + pref[id-1]) - pref.begin();
                    // printf("%d ", idt);
                    if(idt >= r) {
                        x -= pref[r] - pref[id-1];
                        id = r+1;
                    }
                    else {
                        x -= pref[idt] - pref[id-1];
                        id = idt+1;
                        if(id > r) break;
                        if(vec[id] != vec[idt]) continue;
                        idt = idx[id];
                        if(idt > r) {
                            if((r - id) % 2 == 0) x += vec[id];
                            id = r+1;
                        }
                        else {
                            if((idt - id) % 2 == 0) x += vec[id];
                            id = idt+1;
                        }
                    }
                }
                else {
                    int idt = upper_bound(all(pref), -x + pref[id-1]) - pref.begin();
                    if(idt >= r) {
                        x += pref[r] - pref[id-1];
                        id = r+1;
                    }
                    else {
                        x += pref[idt] - pref[id-1];
                        id = idt+1;
                        if(id > r) break;
                        if(vec[id] != vec[idt]) continue;
                        idt = idx[id];
                        if(idt > r) {
                            if((r - id) % 2 == 0) x -= vec[id];
                            id = r+1;
                        }
                        else {
                            if((idt - id) % 2 == 0) x -= vec[id];
                            id = idt+1;
                        }
                    }
                }
                // printf("%lld ", x);
            }
            printf("%lld\n", x);
        }
    }


}