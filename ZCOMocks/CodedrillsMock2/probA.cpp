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

const int MAX = 1001;
lli grid[MAX][MAX];

int main() {
	// usaco();
	int n, m;
	lli c;
	scd(n);
	scd(m);
	sclld(c);

	frange(i, n) {
		frange(j, m) sclld(grid[i][j]);
	}

	frange(i, n) {
		frange(j, m-1) {
			grid[i][j+1] += c - grid[i][j]; 
			grid[i][j] = c;
		}
		if(i < n-1)
		{
			grid[i+1][m-1] += c - grid[i][m-1];
			grid[i][m-1] = c;
		}
	}
	if(grid[n-1][m-1] == c) {
		printf("Yes");
	}
	else printf("No");
}