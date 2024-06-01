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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n;
vll vec;
lli k;

bool check(lli x) {
    lli kt = 0;

    frange(i, n) {
        kt += max(0LL, x-vec[i]);
    }
    return kt <= k;
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        
        
        scd(n);
        sclld(k);
        vec = vll(n);

        frange(i, n) sclld(vec[i]);

        lli lo = 0;
        lli hi = 2e12;

        while(lo != hi) {
            lli mid = (lo+hi+1)/2;
            if(check(mid)) lo = mid;
            else hi = mid-1;
        }

        lli tot = n*(lo-1) + 1;
        lli kt = 0;
        lli c = 0;
        frange(i, n) {
            kt += max(0LL, lo-vec[i]);
            if(vec[i] > lo) c++;
        }
        c += (k-kt);
        tot += c;
        printf("%lld\n", tot);
    }
}