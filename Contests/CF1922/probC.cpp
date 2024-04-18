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

        vi vec(n+1);
        forr(i, 1, n+1) scd(vec[i]);

        vll pref1(n+1), pref2(n+1);

        forr(i, 2, n+1) {
            pref1[i] = pref1[i-1];
            if(i == n || vec[i] - vec[i-1] < vec[i+1] - vec[i]) {
                pref1[i]++;
            }
            else pref1[i] += vec[i] - vec[i-1];
        }

        for(int i=n-1; i>=1; i--) {
            pref2[i] = pref2[i+1];
            if(i == 1 || vec[i+1] - vec[i] < vec[i] - vec[i-1]) {
                pref2[i]++;
            }
            else pref2[i] += vec[i+1] - vec[i];
        }

        int m;
        scd(m);

        frange(_, m) {
            int a, b;
            scd(a);
            scd(b);
            if(a < b) {
                printf("%lld\n", pref2[a] - pref2[b]);
            }
            else printf("%lld\n", pref1[a] - pref1[b]);
        }
    }
}