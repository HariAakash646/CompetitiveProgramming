#include <bits/stdc++.h>
 
using namespace std;
 
#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
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

    int n;
    scd(n);
    
    lli v = 0;
    vector<pair<lli, lli>> vec(n);
    
    frange(i, n) {
        sclld(vec[i].f);
        sclld(vec[i].s);
    }
    
    frange(i, n-1) {
        v += vec[i].f * vec[i+1].s - vec[i].s * vec[i+1].f;
    }
    v += vec[n-1].f * vec[0].s - vec[n-1].s * vec[0].f;
    v = abs(v);
    v += 2;
    lli tot = 0;
    frange(i, n-1) {
        lli x = gcd(abs(vec[i].f - vec[i+1].f), abs(vec[i].s - vec[i+1].s));
        v -= x;
        tot += x;
    }
    lli x = gcd(abs(vec[n-1].f - vec[0].f), abs(vec[n-1].s - vec[0].s));
    v -= x;
    tot += x;

    printf("%lld %lld", v/2, tot);

}