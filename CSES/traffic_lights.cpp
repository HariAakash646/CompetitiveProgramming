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
 
 
struct cmp {
	bool operator()(const pii &x, const pii &y) const {
		int l1 = x.s - x.f;
		int l2 = y.s - y.f;
 
		if(l1 < l2) return true;
		else if(l1 == l2) return x < y;
		else return false;
	}
};
 
int main() {
	int x, n;
	scd(x);
	scd(n);
 
	set<pii> st;
	mseti sz;
	st.insert(mp(1, x));
	sz.insert(x);
 
	frange(i, n) {
		int a;
		scd(a);
		auto it = st.lower_bound(mp(a+1, 0));
		it--;
		auto p = *it;
		sz.erase(sz.find(p.s - p.f + 1));
 
		st.erase(it);
		st.insert(mp(p.f, a));
		sz.insert(a - p.f+1);
		if(a < p.s) {
			st.insert(mp(a+1, p.s));
			sz.insert(p.s - a);
		}
		printf("%d ", *prev(sz.end()));
	}

	printf("\n");
}