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
    fastio();
    // usaco();

    int t;
    cin >> t;
    frange(_, t) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int c = 0;
        frange(i, n) {
            if(str[i] == '1') c++;
        }
        vi suf(n);
        suf[0] = str[0] - '0';
        forr(i, 1, n) {
            if(str[i] == '1') suf[i] = suf[i-1] + 1;
        }
        lli tot = 0;
        forr(i, 1, n-c+1) {
            tot += suf[n-i];

            if(n-i-1>=0) {
                if(suf[n-i])
                    {suf[n-i-1] = suf[n-i];
                                    if(n-i-suf[n-i]-1>=0) suf[n-i-1] += suf[n-i-suf[n-i]-1];}
            }
            cout << tot << " ";
        }
        frange(i, c) cout << "-1 ";
        cout << "\n";


    }
}