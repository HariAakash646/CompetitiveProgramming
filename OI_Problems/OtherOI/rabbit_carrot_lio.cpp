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

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);
    vi vec(n);
    frange(i, n) {
        int a;
        scd(a);
        vec[i] = m * (i+1) - a;
    }
    vi lis(n+1, 1e9+5);
    lis[0] = 0;

    frange(i, n) {
        int id = upper_bound(all(lis), vec[i]) - lis.begin();
        if(id != 0)
            lis[id] = vec[i];
    }
    // frange(i, n+1) printf("%d ", lis[i]);
    for(int i=n; i>=0; i--) {
        if(lis[i] < 1e9+5) {
            printf("%d", n-i);
            return 0;
        }
    }
}