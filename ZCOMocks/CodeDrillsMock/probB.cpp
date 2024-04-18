#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define all(vec) vec.begin(), vec.end()
#define mp make_pair
#define pb push_back

typedef long long lli;
typedef vector<int> vi;
typedef vector<lli> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef set<int> seti;
typedef vector<vi> vvi;
typedef map<int, int> mpii;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const int MAX = 5001;

int grid[MAX][MAX];
int up[MAX][MAX];
int down[MAX][MAX];
int left1[MAX][MAX];
int rigt[MAX][MAX];

int main() {
	// usaco();
	fastio();
	int n, m;
	cin >> n >> m;	

	// vvi grid(n, vi(m));

	frange(i, n) {
		frange(j, m) grid[i][j] = 0;
	}

	frange(i, n) {
		string row;
		cin >> row;
		frange(j, m) {
			if(row[j] == '1') grid[i][j] = 1;
		}
	}

	// vvi up(n, vi(m)), down(n, vi(m)), left1(n, vi(m)), rigt(n, vi(m));

	frange(i, m) {
		up[0][i] = grid[0][i];
		down[n-1][i] = grid[n-1][i];
	}

	frange(i, n) {
		left1[i][0] = grid[i][0];
		rigt[i][m-1] = grid[i][m-1];
	}

	forr(i, 0, n) {
		frange(j, m) {
			if(grid[i][j]) {
				if(i > 0)
					up[i][j] = 1 + up[i-1][j];
				if(j > 0)
					left1[i][j] = 1 + left1[i][j-1];
			}
		}
	}

	for(int i=n-1; i>=0; i--) {
		for(int j=m-1; j>=0; j--) {
			if(grid[i][j]) {
				if(i < n-1)
					down[i][j] = 1 + down[i+1][j];
				if(j < m-1) 
					rigt[i][j] = 1 + rigt[i][j+1]; 
			}
		}
	}

	lli tot = 0;

	frange(i, n) {
		frange(j, m) {
			tot += min({up[i][j], down[i][j], rigt[i][j], left1[i][j]});
		}
	}

	cout << tot;
}