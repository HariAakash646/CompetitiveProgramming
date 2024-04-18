#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
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
typedef long double ld;
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
	int n;
	cin >> n;

	vvi grid(n+1, vi(n+1));

	forr(i, 1, n+1) {
		string str;
		cin >> str;
		forr(j, 1, n+1) {
			grid[i][j] = str[j-1] - '0';
		}
	}

	vvi pref(n+1, vi(n+1));
	vi row(n+1), col(n+1);
	forr(i, 1, n+1) {
		forr(j, 1, n+1) {
			pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + grid[i][j];
			// row[i][j] = row[i][j-1];
			// col[i][j] = col[i-1][j];
			if(grid[i][j]) {
				row[i] = j;
				col[j] = i;
			}

		}
	}
	lli cnt = 0;
	// vector<seti> val(2*n+1);
	// vvi vec(n+1, vi(n+1));
	// forr(i, 1, n+1) {
	// 	forr(j, 1, n+1) {
	// 		int x = row[i];
	// 		int y = col[j];
	// 		// printf("%d %d %d %d\n", i, j, x, y);
	// 		if(y + (j-i) <= n && y + (j-i) >= 0)
	// 			vec[y][y + (j-i)]++;
	// 		if(x + (i-j) <= n && x + (i-j) >= 0)
	// 			vec[x + (i-j)][x]++;
	// 		int id = i - j;
	// 		if(id < 0) id = 2*n+id;
	// 		// printf("%d\n", id);
	// 		val[id].insert(i);
	// 		while(val[id].size()) {
	// 			int id2 = *prev(val[id].end());
	// 			if(vec[id2][id2 + (j-i)] == 2) val[id].erase(prev(val[id].end()));
	// 			else break;
	// 		}
	// 		auto it = val[id].upper_bound(i);
	// 		int v = 0;
	// 		if(it != val[id].begin()) {
	// 			it--;
	// 			v = *it;
	// 		}
	// 		int v2 = i;
	// 		cnt += v2 - v;
	// 		if(v != i)
	// 		printf("%d %d %d\n", i, j, v);
	// 	}
	// }
	seti ran;
	ran.insert(0);
	ran.insert(n+1);
	forr(i, 1, n+1) {
		int id = row[i];
		int l = *prev(ran.upper_bound(id));
		int r = *ran.lower_bound(id);
		forr(k, l+1, id+1) {
			forr(j, id, r) {
				int l = j - k + 1;
				if(i + l - 1 > n) continue;
				int v = pref[i+l-1][j] - pref[i-1][j] - pref[i+l-1][k-1] + pref[i-1][k-1];
				if(v == l) cnt++;
			}
		}
		ran.insert(id);
	}
	cout << cnt;
}