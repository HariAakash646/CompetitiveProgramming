#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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

lli mod = 998244353;

int main() {
    fastio();
    // usaco();
    int t;
    cin >> t;

    vll fact(2e5+1);
    fact[0] = 1;
    forr(i, 1, 2e5+1) {
        fact[i] = (i * fact[i-1]) % mod;
    }

    frange(_, t) {
        string str;
        cin >> str;int n = str.size();
        lli c = 1;
        int cnt = 0;

        int v = 1;
        char ch = str[0];

        forr(i, 1, n) {
            if(str[i] != ch) {
                cnt += (v-1);
                c = (c * v) % mod;
                ch = str[i];
                v = 0;
            }
            v++;
        }
        if(v > 1) {
            
            cnt += (v-1);
            c = (c * v) % mod;
            
        }
        c = (c * fact[cnt]) % mod;
        // vector<pair<int, lli>> dp1(n), dp2(n); 
        cout << cnt << " " << c << "\n";
    }
}