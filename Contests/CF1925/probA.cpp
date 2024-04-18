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
        int n, k, m;
        cin >> n >> k >> m;
        string str;
        cin >> str;

        int id = 0;
        string out;
        bool ov = false;
        frange(i, n) {
            int ma = -1;
            char c1 = 'a';
            frange(j, k) {
                char c = 'a' + j;
                bool done = false;
                forr(l, id, m) {
                    if(str[l] == c) {
                        if(l > ma) {
                            ma = l;
                            c1 = c;
                        }
                        done = true;
                        break;
                    }
                }
                if(!done) {
                    ma = m;
                    c1 = c;
                }
            }
            // cout << ma << " " << c1 << "\n";
            if(ma == m) ov = true;
            id = ma+1;
            out += c1;
        }
        if(!ov) cout << "YES\n";
        else 
        cout << "NO\n" << out << "\n";
    }
}
