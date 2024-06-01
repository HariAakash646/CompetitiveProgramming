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

bool query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    string out;
    cin >> out;
    if(out == "YES") return true;
    else return false;
}

int main() {
    // fastio();
    int t;
    cin >> t;

    frange(_, t) {
        int n;
        cin >> n;

        seti bl, wh, un;
        bl.insert(1);

        forr(i, 2, n+1) {
            if(un.size()) {
                bool v = query(*prev(un.end()), i);
                if(v) un.insert(i);
                else {
                    v = query(*prev(bl.end()), i);
                    if(v) {
                        bl.insert(i);
                        for(auto e : un) wh.insert(e);
                        un = {};
                    }
                    else {
                        wh.insert(i);
                        for(auto e : un) bl.insert(e);
                        un = {};
                    }
                }
            }
            else if(wh.size()) {
                bool v1 = query(*prev(bl.end()), i);
                bool v2 = query(*prev(wh.end()), i);
                if(v1 && v2) un.insert(i);
                else if(v1) bl.insert(i);
                else wh.insert(i);
            }
            else {
                bool v = query(*prev(bl.end()), i);
                if(v) bl.insert(i);
                else wh.insert(i);
            }
        }
        for(auto e : un) bl.insert(e);
        vi out(n+1);
        for(auto e : wh) out[e] = 1;
        cout << "! ";
        forr(i, 1, n+1) {
            cout << out[i] << " ";
        }
        cout << endl;
    }
}