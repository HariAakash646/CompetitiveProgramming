#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t);
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
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
	int l, n;
	cin >> l >> n;
	string str;
	cin >> str;

	vector<vll> dist(26, vll(26, 1e18));

	frange(i, 26) dist[i][i] = 0;

	frange(i, n) {
		char a, b;
		lli c;
		cin >> a >> b >> c;
		int i1 = a-'a';
		int i2 = b-'a';
		// cout << i1 << " " << i2 << "\n"; 
		dist[i1][i2] = min(dist[i1][i2], c);
	}

	frange(k, 26) {
		frange(i, 26) {
			frange(j, 26) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	lli tot = 0;

	frange(i, l/2) {
		lli mi = 1e18;
		int a = str[i] - 'a';
		int b = str[l-i-1] - 'a'; 
		frange(j, 26) {
			mi = min(mi, dist[a][j] + dist[b][j]);
		}
		if(mi >= 1e18) {
			cout << -1;
			return 0;
		}
		tot += mi;
	}
	cout << tot;
}