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

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int trace_len(int a, int b) {
    if(a == b) return 0;
    if(a > b) return 1+trace_len(a-b, b);
    else return 1+trace_len(a, b-a);
}

string trace(int a, int b) {
    if(a == b) return "";
    if(a > b) return '1' + trace(a-b, b);
    else return '0' + trace(a, b-a);
}

int main() {
    int n;
    scd(n);
    n++;
    int ma = 1e9;
    int mv = 0;

    forr(a, 1, n+2) {
        int b = n+1-a;
        if(gcd(a, b) == 1) {
            int l = trace_len(a, b);
            if(l < ma) {
                ma = l;
                mv = a;
                // cout << l << "\n";
            }
        }
    }

    cout << trace(mv, n-mv+1);

}