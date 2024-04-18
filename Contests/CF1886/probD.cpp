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

lli mod = 998244353;

lli inv(lli a) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

int main() {
    // usaco();
    fastio();
    int n, m;
    cin >> n >> m;

    string str;
    cin >> str;

    vll val(n+1);

    frange(i, n) {
        val[i] = i;
    }
    lli v = 1;
    bool zer = false;
    frange(i, n-1) {
        if(str[i] == '?') {
            if(i == 0) {
                zer = true;
            }
            else v = v *i % mod;
        }
    }
    if(zer) cout << "0\n";
    else
        cout << v << "\n";
    frange(_, m) {
        int i;
        char c;
        cin >> i >> c;
        i--;
        if(c == '?') {
            if(str[i] == '<' || str[i] == '>') {
                if(i == 0) zer = true;
                else v = (v * i) % mod;
            }

        }
        else {
            if(str[i] == '?') {
                if(i == 0) zer = false;
                else v = v * inv(i) % mod;
            }
        }
        str[i] = c;
        v %= mod;
        if(zer) cout << "0\n";
        else
        cout << v << "\n";
    }
}   