#include <bits/stdc++.h>
 
using namespace std;
 
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;
 
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


int main() {
    // usaco();
    fastio();
    int t;
    cin >> (t);

    frange(_, t) {
        string str;
        cin >> str;
        int out = 0;
        int n = str.size();
        for(int i=n/2; i>=1; i--) {
            vi pref(n);
            frange(j, n-i) {
                if(str[j] == str[j+i] || str[j] == '?' || str[j+i] == '?') {
                    pref[j] = 1;
                }
            }
            forr(j, 1, n) pref[j] += pref[j-1];
            if(pref[i-1] == i) {
                out = i;
                break;
            }
            forr(j, i, n) {
                if(pref[j] - pref[j-i] == i) {
                    out = i;
                    break;
                }
            }
            if(out) break;
        }
        cout << 2*out << "\n";
    }
}