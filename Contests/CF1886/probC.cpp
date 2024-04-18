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
        string str;
        cin >> str;
        lli x;
        cin >> x;

        lli cnt = 0;
        lli pos = x;
        int n = str.size();
        frange(i, n) {
            lli v = n-i;
            if(x - v <= 0) {
                break;
            }
            x -= v;
            cnt = i+1;
            pos = x;
        }
        // cout << cnt << pos << "\n";
        int id = 0;
        vb rem(n);
        stack<int> stk;
        while(cnt) {
            if(stk.size() && str[stk.top()] > str[id]) {
                rem[stk.top()] = true;
                stk.pop();
                cnt--;
            }
            else {
                stk.push(id);
                id++;
            }
        }
        while(cnt) {
            rem[stk.top()] = true;
            stk.pop();
            cnt--;
        }
        string out = "";
        frange(i, n) {
            if(!rem[i]) out += str[i];
        }
        // cout << cnt << " " << pos << " " << out << "\n";
        cout << out[pos-1];
    }
}