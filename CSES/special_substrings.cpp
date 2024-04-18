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

vi freq;
map<char, int> ch;

bool check() {
    frange(i, freq.size()) {
        if(!freq[i]) return false;
    }
    return true;
}

int main() {
    string str;

    cin >> str;

    int n = str.size();
    vb vis(26);

    int id = 0;
    for(auto e : str) {
        if(!vis[e-'a']) {
            vis[e-'a'] = true;
            ch[e] = id++;
        }
    }
    freq = vi(id);

    map<vi, lli> dp;
    dp[freq] = 1;
    lli ans = 0;
    for(auto e : str) {
        freq[ch[e]]++;
        if(check()) {
            frange(i, id) freq[i]--;
        }
        ans += dp[freq];
        dp[freq]++;
    }
    printf("%lld", ans);
}