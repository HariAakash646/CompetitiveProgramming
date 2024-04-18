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

lli gcd(lli a, lli b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n;
        lli k;
        scd(n);
        sclld(k);

        vll vec(n);
        frange(i, n) sclld(vec[i]);

        sort(all(vec));


        seti st;
        frange(i, n) {
            if(vec[i] < k) st.insert(-1);
            if(vec[i] == k) st.insert(0);
            if(vec[i] > k) st.insert(1);
        }
        if(st.size() > 1) {
            printf("-1\n");
            continue;
        }

        lli g = 0;

        frange(i, n) {
            g = gcd(g, abs(vec[i] - k));
        }

        lli tot = 0;
        frange(i, n) {
            if(g == 0) continue;
            tot += abs(vec[i]-k)/g-1;
        }
        printf("%lld\n", tot);


    }
}