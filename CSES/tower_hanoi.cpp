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

vii out;

void rec(int x, int v1, int v2, int v3) {
    if(x == 1) {
        out.pb(mp(v1, v2));
        return;
    }
    
    
    rec(x-1, v1, v3, v2);
    out.pb(mp(v1, v2));
    rec(x-1, v3, v2, v1);

}


int main() {

    int n;
    scd(n);

    rec(n, 1, 3, 2);

    printf("%d\n", (int)out.size());
    for(auto p : out) printf("%d %d\n", p.f, p.s);
    

}