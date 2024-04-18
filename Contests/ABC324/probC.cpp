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
    int n;
    string t;
    cin >> n >> t;

    vi vec;
    forr(i, 1, n+1) {
        string st;
        cin >> st;

        if(t.size() == st.size()) {
            int c = 0;
            frange(i, t.size()) {
                if(t[i] != st[i]) c++;
            }
            if(c <= 1) vec.pb(i);
        }
        else if(abs((int)t.size() - (int)st.size()) == 1) {
            string t1 = t;
            if(st.size() > t1.size()) swap(t1, st);
            int i1 = 0;
            int c = 0;
            frange(i, t1.size()) {
                if(i1 == st.size() || st[i1] != t1[i]) {
                    c++;
                }
                else {
                    i1++;
                }
            }
            if(c <= 1) vec.pb(i);
        }
    }
    cout << (int)vec.size() << "\n";
    for(auto e : vec) cout << e << " ";
}