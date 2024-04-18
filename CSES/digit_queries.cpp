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
    vll cnt(17);
    vll po10(19);
    po10[0] = 1;
    forr(i, 1, 19) po10[i] = po10[i-1] * 10;
    frange(i, 17) {
        cnt[i] = (i+1) * (po10[i+1] - po10[i]);
    }

    int q;
    scd(q);

    frange(_, q) {
        lli k;
        sclld(k);
        k--;
        int id = 16;
        frange(i, 16) {
            k -= cnt[i];
            if(k < 0) {
                id = i;
                k += cnt[i];
                break;
            }
        }
        // k--;
        lli v = po10[id];
        v += (k) / (id+1);
        
        // k = (k-1) % (id+1);
        k %= id+1;
        // printf("%lld %lld %d ", v, k, id);
        // if(k == id) {
        //     v++;
        //     k = 0;
        // }
        // else k++;
        vi out;
        while(v) {
            out.pb(v % 10);
            v /= 10;
        }
        reverse(all(out));
        printf("%d\n", out[k]);
    } 
}