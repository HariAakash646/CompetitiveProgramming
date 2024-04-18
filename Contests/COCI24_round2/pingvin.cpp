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

int n;
vector<vvi> grid;

int main() {
	fastio();
	// usaco();
	cin >> n;
	int x1, y1, z1;
	cin >> y1 >> x1 >> z1;
	x1--;
	y1--;
	z1--;
	int x2, y2, z2;
	cin >> y2 >> x2 >> z2;
	x2--;
	y2--;
	z2--;

	grid = vector<vvi>(n, vvi(n, vi(n)));

	frange(i, n) {
		frange(j, n) {
			string str;
			cin >> str;
			frange(k, n) {
				grid[i][j][k] = str[k] - '0';
			}
		}
	}

	vector<vector<vb>> vis(n, vector<vb>(n, vb(n)));

	queue<pair<pii, pii>> q;

	q.push(mp(mp(z1, y1), mp(x1, 0)));

	while(q.size()) {
		auto p = q.front();
		q.pop();
		int x = p.s.f;
		int y = p.f.s;
		int z = p.f.f;

		if(x < 0 || x >= n || y < 0 || y >= n || z < 0 || z >= n) continue;
		if(vis[z][y][x]) continue;
		if(grid[z][y][x]) continue;

		vis[z][y][x] = true;

		if(x == x2 && y == y2 && z == z2) {
			cout << p.s.s;
			return 0;
		}

		q.push(mp(mp(z+1, y), mp(x, p.s.s+1)));
		q.push(mp(mp(z-1, y), mp(x, p.s.s+1)));
		q.push(mp(mp(z, y+1), mp(x, p.s.s+1)));
		q.push(mp(mp(z, y-1), mp(x, p.s.s+1)));
		q.push(mp(mp(z, y), mp(x+1, p.s.s+1)));
		q.push(mp(mp(z, y), mp(x-1, p.s.s+1)));
		

	}
	cout << "-1";
}