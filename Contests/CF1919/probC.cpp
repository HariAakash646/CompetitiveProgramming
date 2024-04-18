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
    int t;
    scd(t);
    frange(_, t) {
        int n;
        scd(n);
        vi vec(n);
        int c = 0;
        int v1 = 1e9;
        int v2 = 1e9;
        frange(i, n) {
            scd(vec[i]);
            if(v1 > v2) swap(v1, v2);
            if(vec[i] <= v1) {
                v1 = vec[i];
            }
            else if(vec[i] <= v2) {
                v2 = vec[i];
            }
            else {
                c++;
                if(v1 < v2) v1 = vec[i];
                else v2 = vec[i];
            }
        }
        printf("%d\n", c);

    }
}