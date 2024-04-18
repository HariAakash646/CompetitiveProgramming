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

int n, h;
vi vec;

bool check(int x, int y) {
    if(x + y >= n) return true;

    int curr = vec[x];

    frange(i, x) {
        curr += vec[i];
        curr += vec[x];
    }

    for(int i=n-y; i<n; i++) {
        curr += vec[i] + vec[x];
    }

    return curr >= h;
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        scd(n);
        scd(h);
        vec = vi(n);

        frange(i, n) scd(vec[i]);

        sort(all(vec));

        int mi = n;

        frange(i, n) {
            frange(j, n) {
                if(check(i, j)) mi = min(mi, i+j);
            }
        }

        printf("%d\n", mi);
    }
}