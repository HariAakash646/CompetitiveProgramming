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

const int MAXN = 1e6;
const lli mod = 1e9 + 7;

struct arr {
    int a[26];
    arr() {}
    void clear() { memset(a,-1,sizeof(a)); }
    int& operator[](int i) { return a[i]; }
};

vll dp;

struct trie {
    int cnt, prefix_cnt[MAXN], word_cnt[MAXN];
    arr to[MAXN];

    trie() { cnt = MAXN-1; }

    void clear() { for(int i = 0; i < cnt; i++) prefix_cnt[i] = word_cnt[i] = 0, to[i].clear(); cnt = 1; }

    void add(const string& s) {
        int u = 0;
        for(const char& c: s)  {
            if(to[u][c-'a'] == -1) to[u][c-'a'] = cnt++;
            u = to[u][c-'a'];
            prefix_cnt[u]++;
        }
        word_cnt[u]++;
    }

    bool count(const string& s) {
        int u = 0;
        for (const char& c: s) {
            if (to[u][c-'a'] == -1) return 0;
            u = to[u][c-'a'];
        }
        // cout << "u: " << u << "\n";
        return word_cnt[u];
    }

    void update(int i, const string& s) {
      string nst;
      int u = 0;
      for(int j=i-1; j>=0; j--) {
        char c = s[j];
        if(to[u][c-'a'] == -1) break;
        u = to[u][c-'a'];
        if(word_cnt[u]) {
          dp[i] += dp[j];
          dp[i] %= mod;
        }
      }
      
      

    }
} tr;

int main() {
    // usaco();
    fastio();
    string str;
    cin >> str;
    int k;
    cin >> k;

    int n = str.size();

    tr.clear();
    tr.add("");
    frange(i, k) {
      string st;
      cin >> st;
      if(st.size() > n) continue;
      reverse(all(st));
      tr.add(st);
    }
    
    dp = vll(n+1);
    dp[0] = 1;
    int l = 0;
    forr(i, 1, n+1) {
      tr.update(i, str);

    }
    cout << dp[n];
}