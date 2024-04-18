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

const lli mod = 2e9 + 7;
 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const lli p = uniform_int_distribution<lli>(1e9, mod - 1)(rng);

// const lli p = 31;

int main() {
    fastio();
    // usaco();
    int n;
    cin >> n;

    vector<vll> vec(n);
    vll sze(n);
    vector<map<lli, lli>> cnt(1e6+10);
    lli tot = 0;

    frange(j, n) {
        string str;
        cin >> str;
        sze[j] = str.size();
        
        vll hash(str.size()+1);
 
        forr(i, 1, str.size()+1) {
            hash[i] = hash[i-1] * p + (str[i-1] - 'a' + 1);
            hash[i] %= mod;
            cnt[i-1][hash[i]]++;
            // printf("%lld " ,hash[i]);
        }
        // printf("\n");
        hash = vll(str.size()+1);
        for(int i=str.size()-1; i>=0; i--) {
            hash[i] = hash[i+1] * p + (str[i] - 'a' + 1);
            hash[i] %= mod;
            vec[j].pb(hash[i]);
            // printf("%lld " ,hash[i]);
        }
        // printf("\n");
        tot += (lli)str.size();
    }
    lli ans = 0;
    frange(i, n) {
        ans += tot + sze[i] * n;

        frange(j, vec[i].size()) {
            lli e = vec[i][j];
            ans -= 2 * cnt[j][e];
            if(cnt[j][e] == 0) break;
        }
        // cout << tot + sze[i] * n << " ";
    }
    cout << ans;
}