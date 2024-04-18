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

void usaco() {
	// freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vb vis;
vi unk;

void dfs(int x, vii &vec) {
	if(vis[x]) return;
	vis[x] = true;
	dfs(vec[x].f, vec);
	unk[x] = unk[vec[x].f];
}

int main() {
	usaco();
	fastio();
	int c, t;
	cin >> c >> t;

	frange(_, t) {
		int n, m;
		cin >> n >> m;

		vii vec(n+3);
		forr(i, 1, n+1) vec[i] = mp(i, 1);
		vector<pair<char, pii>> quer(m);
		vb det(n+1);

		frange(i, m) {
			char ch;
			cin >> ch;
			int x, y;
			cin >> x;
			if(ch == '+') {
				cin >> y;
				vec[x] = vec[y];
			}
			else if(ch == '-') {
				cin >> y;
				
				vec[x] = vec[y];
				vec[x].s = !vec[x].s;
			}
			else if(ch == 'U') {
				vec[x] = mp(n+2, 1);
			}
			else if(ch == 'T') {
				vec[x] = mp(n+1, 1);
			}
			else {
				vec[x] = mp(n+1, 0);
			}
			
		}

		vi indeg(n+3);
		forr(i, 1, n+3) {
			indeg[vec[i].f]++;
		}

		queue<int> q;
		forr(i, 1, n+3) {
			if(!indeg[i]) q.push(i);
		}
		vb cyc(n+3, true);
		while(q.size()) {
			auto e = q.front();
			cyc[e] = false;
			q.pop();
			indeg[vec[e].f]--;
			if(indeg[vec[e].f] == 0) q.push(vec[e].f);
		}

		vis = vb(n+3);
		unk = vi(n+3);
		unk[n+2] = 1;
		vis[n+2] = true;
		int c = 0;
		forr(i, 1, n+3) {
			if(cyc[i] && !vis[i]) {
				int x = i;
				int k1 = 0;
				int cr = 0;
				while(!cr || x != i) {
					vis[x] = true;
					cr++;
					k1 += !vec[x].s;
					x = vec[x].f;
				}
				if(k1 % 2) {
					int x = i;
					int cr = 0;
					while(!cr || x != i) {
						unk[x] = 1;
						cr++;
						x = vec[x].f;
					}
				}
			}
		}

		// forr(i, 1, n+1) {
		// 	if(vis[i]) continue;
		// 	int x = i;
		// 	while(!vis[x]) {
		// 		unk[x] = unk[vec[x].f];
		// 		vis[x] = true;
		// 		x = vec[x].f;
		// 	}
		// }
		forr(i, 1, n+1) {
			dfs(i, vec);
		}

		forr(i, 1, n+1) c += unk[i];
		cout << c << "\n";
	}
}