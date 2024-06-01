#include "mars.h"
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

int pos(int i, int j, int x) {
	return i*x+j;
}

std::string process(std::vector <std::vector<std::string>> a, int i, int j, int k, int n)
{
	string out;
	frange(i, 100) out += '0';
	if(max(i, j) == 0) {
		if(a[0][0][0] == '1') out[0] = '1';
	}
	else if(min(i, j) == 0) {
		if(k == 0) {
			int ie = 2;
			int je = 2;
			if(i == 0) je = 3;
			if(j == 0) ie = 3;
			frange(r, ie) {
				frange(c, je) {
					if(a[r][c][0] == '1') {
						int id;
						if(j == 0) {
							id = pos(i+r, j+c, 3);
						}
						else {
							id = pos(i+r, j+c, 2*n+1);
						}
						// printf("%d %d %d\n", i+r, j+c, id);
						out[id] = '1';
					}
				}
			}

		}
		else {
			int ie = 2;
			int je = 2;
			if(i == 0) je = 3;
			if(j == 0) ie = 3;
			frange(r, ie) {
				frange(c, je) {
					frange(l, 100) {
						if(out[l] == '1' || a[r][c][l] == '1') {
							out[l] = '1';
						}
					}
				}
			}
		}
	}
	else if(min(i, j) > 1) {
		if(k == 0) {
			forr(r, 0, 3) {
				forr(c, 0, 3) {
					if(int(a[r][c][0] - '0')) {
						out[pos(i-2+r, j-2+c, 2*(n-1)+1)] = '1';
					}
				}
			}
		}
		else {
			frange(r, 3) {
				frange(c, 3) {
					frange(l, 100) {
						if(out[l] == '1' || a[r][c][l] == '1') {
							out[l] = '1';
						}
					}
				}
			}
		}
	}
	
	if(k == n-1) {
		int x = 2*n+1;
		vvi grid(2*n+1, vi(2*n+1));
		if(out[0] == '1') grid[0][0] = 1;
		frange(l, 100) {
			if(a[0][1][l] == '1') {
				grid[l/(2*n+1)][l%(2*n+1)] = 1;
			}
			if(a[1][0][l] == '1') {
				grid[l/3][l%3] = 1;
			}
			if(a[0][2][l] == '1') {
				grid[l/(2*n+1)][l%(2*n+1)] = 1;
			}
			if(a[2][0][l] == '1') {
				grid[l/3][l%3] = 1;
			}
			if(a[2][2][l] == '1') {
				// printf("%d ", l);
				grid[l/(2*(n-1)+1)+2][l%(2*(n-1)+1)+2] = 1;
			}
		}

		if(n == 1) {
			frange(i, 3) {
				frange(j, 3) {
					grid[i][j] = a[i][j][0] -'0';
				}
			}
		}

		// frange(i, x) {
		// 	frange(j, x) {
		// 		printf("%d ", grid[i][j]);
		// 	}
		// 	printf("\n");
		// }
		
		vector<vb> vis(x, vb(x));
		int c = 0;
		frange(i, x) {
			frange(j, x) {
				if(!vis[i][j] && grid[i][j]) {
					c++;
					stack<pii> stk;
					stk.push(mp(i, j));
					while(stk.size()) {
						auto p = stk.top();
						stk.pop();
						if(p.f < 0 || p.f >= x || p.s < 0 || p.s >= x || !grid[p.f][p.s] || vis[p.f][p.s]) continue;
						vis[p.f][p.s] = true;
						stk.push(mp(p.f+1, p.s));
						stk.push(mp(p.f-1, p.s));
						stk.push(mp(p.f, p.s+1));
						stk.push(mp(p.f, p.s-1));
					}
				}

			}
		}
		out = "";
		frange(i, 100) out += '0';
		frange(i, 20) {
			if(c&(1<<i)) out[i] = '1';
		}
	}


	// printf("%d %d %d ", k, i, j);
	// cout << out << "\n";
	return out;
}
