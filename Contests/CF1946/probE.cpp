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

const lli mod = 1e9 + 7;
vll fact(2e5+1);

int n, m1, m2;
vi pref, suf;

lli inv(lli a) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

lli combi(int n, int r) {
    return ((fact[n] * inv(fact[r]) % mod) * inv(fact[n-r])) % mod;
}

lli rec_pref(int x) {
    if(x == -1) {
        return fact[pref[0]-1];
    }
    return ((combi(pref[x+1]-2, pref[x+1] - pref[x]-1) * fact[pref[x+1] - pref[x]-1]) % mod * rec_pref(x-1)) % mod; 
}

lli rec_suf(int x) {
    if(x == m2) {
        return fact[n-suf[m2-1]];
    }
    return ((combi(n-suf[x-1]-1, suf[x] - suf[x-1]-1) * fact[suf[x] - suf[x-1]-1]) % mod * rec_suf(x+1)) % mod;
}

int main() {
    // usaco();
    int t;
    scd(t);

    fact[0] = 1;
    forr(i, 1, 2e5+1) {
        fact[i] = (fact[i-1] * i) % mod;
    }

    frange(_, t) {
        
        scd(n);
        scd(m1);
        scd(m2);

        pref = vi(m1);
        suf = vi(m2);

        frange(i, m1) scd(pref[i]);
        frange(i, m2) scd(suf[i]);

        if(pref[m1-1] != suf[0] || pref[0] != 1 || suf[m2-1] != n) {
            printf("0\n");
            continue;
        }
        lli out = (rec_pref(m1-2) * rec_suf(1) % mod)* combi(n-1, pref[m1-1]-1);
        out %= mod;
        printf("%lld\n", out);

    }
}