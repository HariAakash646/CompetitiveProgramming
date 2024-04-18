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
        cin >> n;
        string str;
        cin >> str;

        string lng;
        vi lv;
        frange(i, n) {
            auto e = str[i];
            
            while(lv.size() && e > str[lv.back()]) lv.pop_back();
            lv.pb(i);
        }

        seti st;
        for(auto e : lv) st.insert(e);

        frange(i, n) {
            if(st.find(i) == st.end()) lng += str[i];
        }

        if(is_sorted(all(lng))) {
            int l = lv.size();
            char c = str[lv.front()];
            set<char> tmp;
            for(auto e : lv) {
                tmp.insert(str[e]);
            }
            // if(tmp.size() == 1) l = 0;
            frange(i, lv.size()) {
                if(str[lv[i]] == c) l--;
            }
            string st2;
            auto it = prev(st.end());
            frange(i, n) {
                if(st.find(i) == st.end()) st2 += str[i];
                else {
                    st2 += str[*it];
                    it--;
                }
            }
            // cout << st2;
            if(is_sorted(all(st2)))
            cout << l << "\n";
            else cout << "-1\n";
        }
        else cout << "-1\n";
    }
}