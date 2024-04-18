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

struct line {
	lli m, c;

	lli eval(lli x) {
		return m * x + c;
	}

	ld intersect(line &y) {
		return ld(c - y.c) / ld(y.m - m);
	}
};

struct Data {
	line ln;
	int lc=-1, rc=-1;
};

vector<Data> tree;

void add(int x, int l, int r, Data data) {
	if(l > r) return;
	int mid = (l+r)/2;
	bool lb = data.ln.eval(l) < tree[x].ln.eval(l);
	bool mb = data.ln.eval(mid) < tree[x].ln.eval(mid);

	if(mb) {
		swap(data.ln, tree[x].ln);
	}
	if(lb != mb) {
		if(tree[x].lc == -1) {
			tree[x].lc = tree.size();
			tree.pb(data);
		}
		else {
			add(tree[x].lc, l, mid-1, data);
		}
	}
	else {
		if(tree[x].rc == -1) {
			tree[x].rc = tree.size();
			tree.pb(data);
		}
		else {
			add(tree[x].rc, mid+1, r, data);
		}
	}
} 

lli query(int x, int l, int r, lli v) {

	int mid = (l+r)/2;

	if(v == mid) return tree[x].ln.eval(v);
	else if(v < mid) {
		if(tree[x].lc != -1) 
			return min(tree[x].ln.eval(v), query(tree[x].lc, l, mid-1, v));
		else return tree[x].ln.eval(v);
	}
	else {
		if(tree[x].rc != -1) {
			return min(tree[x].ln.eval(v), query(tree[x].rc, mid+1, r, v));
		}
		else return tree[x].ln.eval(v);
	}
}

int main() {
	// usaco();
	int n;
	lli x;
	scd(n);
	sclld(x);

	Data tmp;
	tmp.ln.m = x;
	tmp.ln.c = 0;
	tree.pb(tmp);

	vector<pair<lli, lli>> vec(n);
	frange(i, n) sclld(vec[i].f);
	frange(i, n) sclld(vec[i].s);
	lli val;
	for(auto p : vec) {
		val = query(0, 0, 1e6+1, p.f);
		tmp.ln.c = val;
		tmp.ln.m = p.s;
		add(0, 0, 1e6+1, tmp);
	}
	printf("%lld", val);
}