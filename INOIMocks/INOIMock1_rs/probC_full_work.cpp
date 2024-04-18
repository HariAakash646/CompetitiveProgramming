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

int main() {
    fastio();
    // usaco();

    int l, q;
    cin >> l >> q;

    string str;
    cin >> str;

    vll val(1<<l);

    vll dp0(1<<l);
    vll dp1(1<<l);

    frange(i, 1<<l) {
        val[i] = dp0[i] = dp1[i] = str[i] - '0';
    }
    frange(j, l) {
    frange(i, 1<<l) {
        
            if(i&(1<<j)) dp1[i] += dp1[i^(1<<j)];
            else dp0[i] += dp0[i^(1<<j)];
        }
    }

    frange(_, q) {
        string quer;
        cin >> quer;

        reverse(all(quer));

        int n0 = 0, n1 = 0, nq = 0;

        for(auto e : quer) {
            if(e == '0') n0++;
            else if(e == '1') n1++;
            else nq++;
        }
        lli out = 0;
        if(nq <= 6) {
            int v = 0;
            vi pos;

            frange(i, l) {
                if(quer[i] =='1') v += (1<<i);
                else if(quer[i] == '?') pos.pb(i);
            }

            frange(i, 1<<nq) {
                int tmp = v;
                frange(j, nq) {
                    if(i & (1<<j)) tmp += (1<<pos[j]);
                }
                out += val[tmp];
            }
        }
        else if(n0 <= 6) {
            int v = 0;
            vi pos;

            frange(i, l) {
                if(quer[i] =='1') v += (1<<i);
                else if(quer[i] == '0') pos.pb(i);
            }

            frange(i, 1<<n0) {
                int tmp = v;
                frange(j, n0) {
                    if(i & (1<<j)) tmp += (1<<pos[j]);
                }
                if(__builtin_popcount(i) % 2 == 0) out += dp0[tmp];
                else out -= dp0[tmp];
            }
        }
        else {
            int v = 0;
            vi pos;

            frange(i, l) {
                if(quer[i] =='1') {
                    v += (1<<i);
                    pos.pb(i);
                }
                else if(quer[i] == '?') v += (1<<i);
            }

            frange(i, 1<<n1) {
                int tmp = v;
                frange(j, n1) {
                    if(i & (1<<j)) tmp -= (1<<pos[j]);
                }
                if(__builtin_popcount(i) % 2 == 0) out += dp1[tmp];
                else out -= dp1[tmp];
            }
        }
        printf("%lld\n", out);
    }
}