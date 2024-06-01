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

bool check(lli x, int c, lli v) {
    lli v1 = 1;
    frange(i, c) {
        v1 *= x;
        if(v1 > v) return false;
    }   
    return true;
}

int main() {
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n;
        scd(n);
        vll vec(n);
        lli c = 0;
        frange(i, n) {sclld(vec[i]); if(vec[i] == 1) c += n;}
        
        frange(i, min(30, n)) {
            frange(j, n) {
                if(vec[j] != 1) {
                    c += check(vec[j], i+1, vec[i]);
                }
            }
        }
        printf("%lld\n", c);
    }
}