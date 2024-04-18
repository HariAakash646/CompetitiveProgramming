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
    string str;
    cin >> str;

    int n = str.size();

    set<char> st;

    int k = 0;

    string out = "";

    for(auto e : str) {
        st.insert(e);
        if(st.size() == 4) {
            out += e;
            k++;
            st = {};
        }
    }
    

    vector<char> vec = {'A', 'B', 'C', 'D'};

    for(auto e : vec) {
        if(st.find(e) == st.end()) {
            out += e;
            break;
        }
    }
    cout << out;
}