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

int main() {
    // usaco();
    fastio();
    int t;
    cin >> t;

    frange(_, t) {
        int n;
        string str;
        cin >> n >> str;
        int c = 0;
        frange(i, n) {
            if(str[i] == '?') c++;
        }
        if(str[0] == '?') {
            string out;
            out += '1';
            frange(i, c-1) out += '0';
            cout << out << "\n";
        }
        else {
            string out;
            int tot = 0;
            frange(i, n) {
                if(str[i] != '?') {
                    tot += (str[i] - '0');
                }
            }
            if(tot % 9 == 0) {
                out += '2';
            }
            else {
                out += '1';
            }
            frange(i, c-1) out += '1';
            reverse(all(out));
            cout << out << "\n";
        }
    }
}