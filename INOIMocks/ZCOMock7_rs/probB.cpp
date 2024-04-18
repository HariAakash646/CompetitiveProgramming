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
	int n, q;
	cin >> n >> q;

	vector<vector<seti>> val(2, vector<seti>(n+1));
	vii pos(n+1);

	forr(i, 1, n+1) {
		val[0][i].insert(i);
		pos[i] = mp(i, 0);
	}

	frange(_, q) {
		char t;
		int a, b;
		cin >> t >> a >> b;
		if(t == 'Q') {
			if(val[pos[a].s][pos[a].f].count(b)) {
				cout << "R\n";
			}
			else if(val[!pos[a].s][pos[a].f].count(b)) {
				cout << "A\n";
			}
			else {
				cout << "?\n";
			}
		}
		else if(t == 'R') {
			if(pos[a].f == pos[b].f) continue;
			if(val[0][pos[a].f].size() + val[1][pos[a].f].size() > val[0][pos[b].f].size() + val[1][pos[b].f].size()) {
				swap(a, b);
			}
			int x = pos[a].f;
			int x2 = pos[a].s;
			for(auto e : val[x2][x]) {
				pos[e] = mp(pos[b].f, pos[b].s);
				val[pos[b].s][pos[b].f].insert(e);
			}

			for(auto e : val[!x2][x]) {
				pos[e] = mp(pos[b].f, !pos[b].s);
				val[!pos[b].s][pos[b].f].insert(e);
			}
		}
		else {
			if(pos[a].f == pos[b].f) continue;
			if(val[0][pos[a].f].size() + val[1][pos[a].f].size() > val[0][pos[b].f].size() + val[1][pos[b].f].size()) {
				swap(a, b);
			}
			int x = pos[a].f;
			int x2 = pos[a].s;
			for(auto e : val[x2][x]) {
				pos[e] = mp(pos[b].f, !pos[b].s);
				val[!pos[b].s][pos[b].f].insert(e);
			}

			for(auto e : val[!x2][x]) {
				pos[e] = mp(pos[b].f, pos[b].s);
				val[pos[b].s][pos[b].f].insert(e);
			}
		}
	}
}