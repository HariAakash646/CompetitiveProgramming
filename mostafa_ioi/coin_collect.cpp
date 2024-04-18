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
    int n;
    scd(n);
    vii v1, v2;

    lli tot = 0;
    vvi cnt(2, vi(n));

    frange(i, 2*n) {
        int x, y;
        scd(x);
        scd(y);
        int x1 = max(1, min(n, x));
        int y1 = 1;
        if(y >= 2) y1 = 2;
        cnt[y1-1][x1-1]++;
        tot += abs(x-x1) + abs(y-y1);
    }

    

    

    

    
    printf("%lld", tot);
}