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

    int n = str.size();

    seti st;
    st.insert(-1);

    auto it = st.begin();

    vb pr(n, true);

    frange(i, n) {
        if(*it != -1) {
            if(str[i] == 'C' && str[*it] == 'B') {
                if(*prev(it) >= 0 && str[*prev(it)] == 'A') {
                    pr[i] = false;
                    pr[*prev(it)] = false;
                    pr[*it] = false;
                    int v1 = *it;
                    int v2 = *prev(it);
                    st.erase(v1);
                    st.erase(v2);
                    it = prev(st.end());
                }
                else {
                    st.insert(i);
                    it = prev(st.end());
                }
            }
            else {
                st.insert(i);
                it = prev(st.end());
            }
        }
        else {
            st.insert(i);
            it = prev(st.end());
        }
    }

    frange(i, n) {
        if(pr[i]) cout << str[i];
    }
}