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

const lli mod = 1e9 + 7;

int main() {
    srand(time(0));
    // usaco();
    int n;
    string str;
    cin >> n >> str;
    if(n%2==0) {
        printf("NOT POSSIBLE");
        return 0;
    }
    int x = n/2;
    bool done = false;
    lli pre;
    string out;

    lli r = rand() % (mod-10000) + 10000;
    // lli r = 5;
    vll powr(2e6+1, 1);
    forr(i, 1, 2e6+1) {
        powr[i] = powr[i-1] * r % mod;
    }

    lli v = 0;
    frange(i, x) {
        v += (str[i] - 'A' + 1) * powr[i];
        // cout << str[i] << " ";
        // printf("%lld\n", v);
        v %= mod;
    }

    lli v2 = 0;
    frange(i, x) {
        v2 += (str[i+x+1] - 'A' + 1) * powr[i];
        v2 %= mod;
    }

    if(v2 == v) {
        if(done && v != pre) {
            printf("NOT UNIQUE");
            return 0;
        }
        done = true;
        out = "";
        pre = v;
        frange(i, x) out += str[i];
    }

    frange(i, x) {
        v2 -= (str[i+x+1] - 'A' + 1) * powr[i] % mod;
        v2 += mod;
        v2 %= mod;
        v2 += (str[i+x] - 'A' + 1) * powr[i];
        v2 %= mod;
        // printf("%lld %lld\n", v, v2);
        if(v2 == v) {
            if(done && v != pre) {
                printf("NOT UNIQUE");
                return 0;
            }
            if(!done) {done = true;
                        out = "";
                        pre = v;
                        frange(i, x) out += str[i];}
        }
    }

    v = 0;
    frange(i, x) {
        v += (str[i+x+1] - 'A' + 1) * powr[i];
        v %= mod;
    }

    v2 = 0;
    frange(i, x) {
        v2 += (str[i+1] - 'A' + 1) * powr[i];
        v2 %= mod;
    }

    if(v2 == v) {
        if(done && v != pre) {
            printf("NOT UNIQUE");
            return 0;
        }
        if(!done) {done = true;
                out = "";
                pre = v;
                frange(i, x) out += str[i+x+1];}
    }

    frange(i, x) {
        v2 -= (str[i+1] - 'A' + 1) * powr[i] % mod;
        v2 += mod;
        v2 %= mod;
        v2 += (str[i] - 'A' + 1) * powr[i];
        v2 %= mod;
        // printf("%lld %lld\n", v, v2);
        if(v2 == v) {
            if(done && v != pre) {
                printf("NOT UNIQUE");
                return 0;
            }
            if(!done) {done = true;
                        out = "";
                        pre = v;
                        frange(i, x) out += str[i+x+1];}
        }
    }
    if(done)
    cout << out;    
    else printf("NOT POSSIBLE");



}