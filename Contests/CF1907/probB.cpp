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
    int t;
    cin >> t;

    frange(_, t) {
        string str;
        cin >> str;

        int n = str.size();
        vi vec(n);
        vi up, lo;

        frange(i, n) {
            if(str[i] == 'B') {
                if(up.empty()) continue;
                int id = up.back();
                vec[id] = 0;
                up.pop_back();
            }
            else if(str[i] == 'b') {
                if(lo.empty()) continue;
                int id = lo.back();
                vec[id] = 0;
                lo.pop_back();
            }
            else {
                vec[i] = 1;
                if('a' <= str[i] && str[i] <= 'z') lo.pb(i);
                else up.pb(i);
            }
        }

        frange(i, n) {
            if(vec[i]) cout << str[i];
        }
        cout << "\n";
    }
}