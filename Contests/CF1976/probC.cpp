#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define f first
#define s second
typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef set<int> seti;

int main() {
    int t;
    scd(t);

    frange(_, t) {
        int n, m;
        scd(n);
        scd(m);

        vii vec(n+m+1);
        frange(i, n+m+1) scd(vec[i].f);
        frange(i, n+m+1) scd(vec[i].s);

        seti st1, st2;
        lli tot = 0;

        forr(i, 0, n+m+1) {
            if(vec[i].f > vec[i].s) {
                st1.insert(i);
            }
            else {
                st2.insert(i);
            }
        }
        if(st2.size() > m) {
            swap(n, m);
            swap(st1, st2);
            frange(i, n+m+1) swap(vec[i].f, vec[i].s);
        }
        int ext;
        while(st1.size() > n+1) {
            st2.insert(*prev(st1.end()));
            st1.erase(prev(st1.end()));
        }
        ext = *prev(st1.end());
        st1.erase(prev(st1.end()));
        for(auto e : st1) {
            tot += vec[e].f;
        }
        for(auto e : st2) tot += vec[e].s;

        forr(i, 0, n+m+1) {
            if(st1.count(i)) {
                printf("%lld ", tot + vec[ext].f - vec[i].f);
            }
            else if(st2.count(i)) {
                printf("%lld ", tot + vec[ext].s - vec[i].s);
            }
            else printf("%lld ", tot);
        }
        printf("\n");
    }
}