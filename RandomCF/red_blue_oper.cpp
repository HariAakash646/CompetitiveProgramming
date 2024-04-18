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
    int n, q;
    scd(n);
    scd(q);

    vll vec(n);

    frange(i, n) sclld(vec[i]);
    sort(all(vec));
    lli ma = vec[n-1];
    vll v2 = vec;
    frange(i, n) v2[i] -= i;

    lli mi = *min_element(all(v2));
    vll mv(n);
    mv[0] = v2[0];
    forr(i, 1, n) mv[i] = min(mv[i-1], v2[i]); 
    lli d1 = 0;
    lli d2 = 0;
    lli d3 = 0;

    frange(i, n) d1 += v2[i] - mi;
    frange(i, n-1) d2 += v2[i] - ma;
    frange(i, n-1) d3 += v2[i] - mi;
    d3 += ma - mi; 

    frange(_, q) {
        lli k;
        sclld(k);
        if(k < n) {
            printf("%lld ", min(mv[k-1]+k, vec[k]));
        }
        else if((k - n) % 2 == 0) {
            lli og = k;
            k -= n;
            k -= d1 * 2;
            if(k <= 0) printf("%lld ", mi+og);
            else {
                k/=2;
                printf("%lld ", mi+og-(k+n-1)/n);
            }
        }
        else {
            lli og = k;
            if(ma == mi) {
                // printf("HI ");
                printf("%lld ", ma-k/2);
            }
            else if(ma < mi+k) {

                k -= n-1;
                lli dif = d2 + (n-1)*og;
                k -= 2*dif;
                // printf("%lld %lld %lld %lld\n", k, dif, og, d2);
                if(k <= 0) printf("%lld ", ma);
                else {
                    k /= 2;
                    printf("%lld ", ma - (k+n-1)/n);
                }
            }
            else {
                k-=n-1;
                k -= (d3-og) * 2;
                if(k <= 0) printf("%lld ", mi+og);
                else {
                    k/=2;
                    printf("%lld ", mi+og-(k+n-1)/n);
                }
            }
        }
    }
}