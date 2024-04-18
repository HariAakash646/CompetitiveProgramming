#include <bits/stdc++.h>

using namespace std;

#define forr(i, j, k) for(int i=j; i<k; i++)
#define frange(i, k) forr(i, 0, k)
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(vec) vec.begin(), vec.end()

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long lli;
typedef vector<lli> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef set<int> seti;
typedef map<int, int> mpii;
typedef multiset<int> mseti;
typedef vector<bool> vb;
typedef long double ld;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

const lli mod = 1e9 + 7;

const int MAXN = 1e6+1;

int cnt[MAXN];
int trie[MAXN][26];
int id = 0;

void add(string str) {
	int x = 0;
	frange(i, str.size()) {
		int v = str[i] - 'a';
		if(trie[x][v] != -1) {
			x = trie[x][v];
		}
		else {
			trie[x][v] = ++id;
			x = id;
		}
	}
	cnt[x]++;
}

int main() {
	// usaco();
	fastio();
	frange(i, 1e6+1) {
		cnt[i] = 0;
		frange(j, 26) trie[i][j] = -1;
	}

	string str;
	cin >> str;
	int n = str.size();
	int k;
	cin >> k;

	frange(_, k) {
		string st;
		cin >> st;
		reverse(all(st));
		add(st);
	}

	vll dp(n+1);
	dp[0] = 1;

	forr(i, 1, n+1) {
		int x = 0;
		for(int j=i; j>=1; j--) {
			int v = str[j-1] - 'a';
			if(trie[x][v] == -1) break;
			x = trie[x][v];
			if(cnt[x]) {
				dp[i] += dp[j-1];
				dp[i] %= mod;
			}
		}
	} 
	cout << dp[n];
}