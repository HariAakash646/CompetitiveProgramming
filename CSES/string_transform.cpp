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

    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;

    frange(i, n) pq.push(mp(str[i], i));
    vi nxt(n);
    frange(i, n) {
        auto p = pq.top();
        pq.pop();
        nxt[p.s] = i;
    }

    int id;
    frange(i, n) {
        if(str[i] == '#') id = i;
    }
    string out = "";
    frange(i, n) {
        id = nxt[id];
        if(str[id] != '#')
        out += str[id];
    }
    reverse(all(out));
    cout << out;
}