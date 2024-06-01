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
    string str;
    cin >> str;
    lli x, y;
    cin >> x >> y;

    lli tot = 0;
    int c1 = 0, c0 = 0;
    for(auto e : str) {
        if(e == '0') {
            tot += c1*y;
            c0++;
        }
        else if(e == '1') {
            tot += c0*x;
            c1++;
        }
    }
    lli v0 = c0*y;
    lli v1 = c1*x;

    for(auto e : str) {
        if(e=='0') {
            v0 -= y;
            v0 += x;
        }
        else if(e=='1') {
            v1 += y;
            v1 -= x;
        }
        else {
            if(v0 < v1) {
                tot += v0;
                v1 += y;
            }
            else {
                tot += v1;
                v0 += x;
            }
        }
    }
    cout << tot;
}