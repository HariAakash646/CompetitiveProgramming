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
        lli n, k;
        sclld(n);
        sclld(k);
        vll out;
        vll bin(60);
        frange(i, 60) {
            if(n % 2) bin[i] = 1;
            n /= 2;
        }
        
        lli v = 0;
        
        int id = -1;
        for(int i=59; i>=0; i--) {
            // if(i != 0 && bin[i] && v + 2 * bin[i] + bin[i-1] <= k) {
            //     bin[i-1] += 2*bin[i];
            //     bin[i] = 0;
            // }
            // else {
            //     v += bin[i];
            //     if(v == k) {
            //         id = i;
            //         break;
            //     }
            // }
            vll tmp = bin;
            frange(j, i) tmp[j] = 0;
            lli v = 0;
            forr(j, i, 60) v += bin[j];
            int pre = i;
            forr(j, i, 60) {
                if(tmp[j]) continue;
                int nx = j;
                for(int l=j; l>pre; l--) {
                    if(v+tmp[l] <= k) {
                        v += tmp[l];
                        tmp[l-1] += 2*tmp[l];
                        tmp[l] = 0;
                        nx = l-1;
                    }
                }
                pre = nx;
            }
            if(v == k) {
                id = i;
                bin = tmp;
                break;
            }
        }
        
        if(id != -1) {
            for(int i=59; i>=id; i--) {
                if(bin[i]) out.pb(1LL<<i);
            }
            sort(all(out), greater<>());
            printf("YES\n");
            printf("%d\n", (int)out.size());
            for(auto e : out) printf("%lld ", e);
                printf("\n");
        }
        else {
            printf("NO\n");
        }
    }
}