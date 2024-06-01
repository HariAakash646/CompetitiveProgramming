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

int main() {
    // usaco();
    fastio();
    srand(time(0));
    int t;
    cin >> t;

    lli h = rand() % (mod-1) + 1;

    vll powh(1e6+1);
    powh[0] = 1;
    forr(i, 1, 1e6+1) {
        powh[i] = powh[i-1] * h % mod;
    }

    frange(_, t) {
        string str;
        cin >> str;

        int n = str.size();
        int l = 0;
        int r = n-1;
        bool curr = true;
        lli vf = 0;
        lli vs = 0;
        int lp = 0;
        int rp = n-1;
        int c = 0;
        while(l < r) {
            vf += lli(str[l]-'a'+1) * powh[(l-lp)] % mod;
            vf %= mod;
            vs *= h;
            vs %= mod;
            vs += lli(str[r] - 'a' + 1);
            vs %= mod;
            curr = true;
            l++;
            r--;
            // printf("%lld %lld\n", vf, vs);
            if(vf == vs) {
                c+=2;
                vs = vf = 0;
                lp = l;
                rp = r;
                if(l != r)
                curr = false;
            }
        }
        c += curr;
        cout << c << "\n";

    }
}