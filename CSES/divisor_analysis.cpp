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

lli mod = 1e9 + 7;

lli inv(lli a) {
  return a <= 1 ? a : mod - (mod/a) * inv(mod % a) % mod;
}


lli modexp(lli x, lli k, lli mod) {
    if(k == 0) return 1;
    lli v = modexp(x, k/2, mod);
    v *= v;
    v %= mod;
    if(k % 2) {
        return v * x % mod;
    }
    else return v;
}

int main() {
    // usaco();
    int n;
    scd(n);

    vector<pair<lli, lli>> vec(n);

    frange(i, n) {
        sclld(vec[i].f);
        sclld(vec[i].s);
    }

    vector<lli> cnt(n);
    lli c = vec[0].s + 1;
    cnt[0] = vec[0].s + 1;
    forr(i, 1, n) {
        cnt[i] = (cnt[i-1] * (vec[i].s + 1)) % (mod-1);
        c *= vec[i].s + 1;
        c %= mod;
    }

    printf("%lld ", c);

    vll sum(n);

    sum[0] = ((modexp(vec[0].f, vec[0].s+1, mod) - 1 + mod) % mod) * inv(vec[0].f - 1) % mod;

    forr(i, 1, n) {
        sum[i] = sum[i-1] * (((modexp(vec[i].f, vec[i].s+1, mod) - 1 + mod) % mod) * inv(vec[i].f - 1) % mod) % mod;
    }

    vll prod(n);
    lli ex = vec[0].s * (vec[0].s + 1) / 2;
    ex %= (mod-1);

    prod[0] = modexp(vec[0].f, ex, mod);

    forr(i, 1, n) {
        lli ex = vec[i].s * (vec[i].s + 1) / 2;
        ex %= (mod-1);

        ex *= cnt[i-1];
        ex %= (mod-1);

        prod[i] = modexp(vec[i].f, ex, mod) * modexp(prod[i-1], vec[i].s+1, mod) % mod;
    }

    printf("%lld %lld", sum[n-1], prod[n-1]);
}