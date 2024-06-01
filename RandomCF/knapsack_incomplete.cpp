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
    lli w;
    sclld(w);
    vll cnt(9), pik(9);
    lli tot = 0;
    forr(i, 1, 9) {
        sclld(pik[i]);
        tot += pik[i] * i;
    }

    if(tot <= w) {
        printf("%lld\n", tot);
        return 0;
    }
    int id = 8;
    while(tot >= w) {
        lli c = min(pik[id], (tot - w + id - 1)/id);
        pik[id] -= c;
        cnt[id] += c;
    }
}