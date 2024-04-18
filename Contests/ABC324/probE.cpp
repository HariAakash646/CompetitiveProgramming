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

    int k = t.size();

    vi v1(n), v2(n);

    frange(i, n) {
        string st;
        cin >> st;
        int id = 0;
        frange(j, st.size()) {
            if(st[j] == t[id]) {
                id++;
                if(id >= k) break;
            }
        }
        v1[i] = id-1;
        id = k-1;
        for(int j=st.size()-1; j>=0; j--) {
            if(st[j] == t[id]) {
                id--;
                if(id < 0) break;
            }
        }
        v2[i] = id+1;
    } 
    sort(all(v1));
    sort(all(v2));
    lli c = 0;
    for(auto e : v1) {
        lli v = upper_bound(all(v2), e+1) - v2.begin();
        c += v;
    }
    cout << c;
}