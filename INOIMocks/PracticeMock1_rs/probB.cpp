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

		vi vec(n+1);
		forr(i, 1, n+1) vec[i] = i;
		// forr(i, 1, n+1) vec[i] = mp(i, 1);
		// vector<pair<char, pii>> quer(m);
		vi val(n+1);
		frange(i, m) {
			char ch;
			cin >> ch;
			if(ch=='U') {
				int id;
				cin >> id;
				val[id] = 1;
			}
			else {
				int x, y;
				cin >> x >> y;				
				vec[x] = vec[y];
			}
		}

		forr(i, 1, n+1) c += val[vec[i]];
		cout << c << "\n";
	}
}