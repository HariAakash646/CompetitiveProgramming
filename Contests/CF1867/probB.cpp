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
    freopen("input.in", "r", stdin);
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
    cin >> t;
    frange(_, t) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int un = 0;
        int eq = 0;
        string s2 = str;
        reverse(all(s2));
        frange(i, n/2) {
            if(str[i] != s2[i]) {
                un++;
            }
            else eq++;
        }
        string out;
        frange(i, un) out+='0';
        frange(i, 2*eq+1+(n%2)) {
            if(i % 2 == 0)
            out += '1';
            else if(n % 2 == 1) out += '1';
            else out += '0';
        }
        int x = n - out.size()+1;
        frange(i, x) out += '0';
        cout << out << "\n";
    }

}