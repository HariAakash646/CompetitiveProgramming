#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)

typedef long long int lli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<lli> vll;

const lli mod = 998244353;
vll fact(5e5+1, 1);

lli inv(lli a) {
  return a <= 1 ? a : mod - (mod/a) * inv(mod % a) % mod;
}

lli combi(int n, int r) {
    return (fact[n] * inv(fact[r]) % mod) * inv(fact[n-r]) % mod;
}

vvi minv;

void init(int n, vi &vec) {
    minv = vvi(20, vi(n));
    frange(i, n) minv[0][i] = vec[i];

    forr(i, 1, 20) {
        frange(j, n) {
            minv[i][j] = max(minv[i-1][j], minv[i-1][min(n-1, j+(1<<(i-1)))]);
        }
    }
}

int query(int l, int r) {
    int ln = r - l +1;
    int msb = 31 - __builtin_clz(ln);

    return max(minv[msb][l], minv[msb][r-(1<<msb)+1]);
}

int main() {
    forr(i, 1, 5e5+1) {
        fact[i] = (fact[i-1]*i) % mod;
    }
    int t;
    scd(t);

    frange(_, t) {
        int n, m;
        scd(n);
        scd(m);
        lli tot = 0;
        vi vec(n+1);
        set<int> st;
        frange(i, n) {scd(vec[i+1]); if(vec[i+1]) st.insert(vec[i+1]);}
        vi pre(n+1, 0);
        vi cnt(n+1);
        vi pos(m+1);

        forr(i, 1, n+1) {
            cnt[i] = cnt[i-1];
            if(vec[i]) {
                cnt[i]++;
                pre[i] = pos[vec[i]];
                pos[vec[i]] = i;
            }
        }

        init(n+1, pre);

        forr(i, max(1, (int)st.size()), min(n, m)+1) {
            lli out = combi(m-(int)st.size(), i-(int)st.size());
            for(int j=1; j<=n; j+=i) {
                if(query(j, min(n, j+i-1)) >= j) {
                    out = 0;
                    break;
                }
                int l = min(n, j+i-1) - j + 1;
                if(j+i-1 <= n)
                    out = (out * fact[i-(cnt[min(n, j+i-1)] - cnt[j-1])]) % mod;
                else {
                    int c = l - (cnt[min(n, j+i-1)] - cnt[j-1]);
                    out = (out * (fact[i-(cnt[min(n, j+i-1)] - cnt[j-1])] * inv(fact[i-(cnt[min(n, j+i-1)] - cnt[j-1])-c]) % mod)) % mod;
                }
            }
            // printf("%d %lld\n", i, out);
            tot = (tot + out)%mod;
        }
        printf("%lld\n", tot);
    }
}