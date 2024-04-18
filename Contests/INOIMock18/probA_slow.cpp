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

    vi pr1(n+1), pr0(n+1);

    forr(i, 1, n+1) {
        pr1[i] = pr1[i-1] + (str[i-1] - '0');
        pr0[i] = pr0[i-1] + (str[i-1] == '0');
    }

    lli tot = 0;

    forr(i, 1, n+1) {
        forr(j, i, n+1) {
            tot += max(pr1[j] - pr1[i-1], pr0[j] - pr0[i-1]);
            tot %= mod;
        }
    }
    printf("%lld", tot);

}