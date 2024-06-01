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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int lsb(int x) {
    return x & (-x);
}

const lli mod = 998244353;
vll inv(501);

lli modinv(lli a) {
  return a <= 1 ? a : mod - (mod/a) * modinv(mod % a) % mod;
}

lli combi(lli n, lli r) {
    if(r > n) return 0;
    lli out = 1;
    forr(i, n-r+1, n+1) out = (out*i) % mod;
    forr(i, 1, r+1) out = (out * inv[i]) % mod;
    return out;
}

int main() {
    // usaco();
    int t;
    scd(t);

    forr(i, 1, 501) inv[i] = modinv(i);

    frange(_, t) {
        int n; lli k;
        scd(n);
        sclld(k);

        vll vec(n+1);
        forr(i, 1, n+1) sclld(vec[i]);

        vll out(n+1);

        for(int i=2; i/2<=n; i*=2) {
            for(int j=i/2; j<=n; j+=i) {
                int c = 1;
                // printf("%d %lld\n", j, out[j]);
                out[j] = (vec[j]-out[j]+mod)%mod;
                int id = j+lsb(j);
                lli tot = 0;
                while(id<=n) {
                    tot = combi(k+c-1, c);
                    tot %= mod;
                    out[id] += out[j] * tot;
                    out[id] %= mod;
                    c++;
                    id+=lsb(id);
                }
            }
        }

        forr(i, 1, n+1) printf("%lld ", out[i]);
        printf("\n");
    }
}