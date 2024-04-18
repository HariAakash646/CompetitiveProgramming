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

int main() {
    // usaco();
    int n;
    string str;
    cin >> n >> str;

    lli tot = 0;

    frange(i, n) {
        if(str[i] == '1') {
            tot += lli(i+1) * (n - i);
            tot %= mod;
        }
    }

    vi nex(n);
    if(str[n-1] == '1')
    nex[n-1] = n-1;
    else nex[n-1] = n;

    for(int i=n-2; i>=0; i--) {
        if(str[i] == str[i+1]) {
            nex[i] = i;
        }
        else nex[i] = nex[i+1];
    }
    // frange(i, n) printf("%d ", nex[i]);
    // printf("%lld\n", tot);
    frange(i, n) {
        if(str[i] == '0') {
            tot += (nex[i] - i + 1)/2;
            tot %= mod;
        }
    }

    printf("%lld", tot);


}