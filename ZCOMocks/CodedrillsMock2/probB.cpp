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


int main() {
	// usaco();
	int n;
	scd(n);
	int x = (1<<n);
	vll vec(x);
	vector<pair<lli, lli>> val(n+1);

	frange(i, x) {
		sclld(vec[i]);
		forr(j, 1, n+1) {
			int id = i % (1<<j);
			if(id < (1<<(j-1))) val[j].f += vec[i];
			else val[j].s += vec[i];
		}
	}

	int q;
	scd(q);

	frange(_, q) {
		int i;
		lli v;
		scd(i);
		sclld(v);
		forr(j, 1, n+1) {
			int id = i % (1<<j);
			if(id < (1<<(j-1))) val[j].f += v-vec[i];
			else val[j].s += v-vec[i];
		}
		vec[i] = v;
		lli tot = 0;
		forr(j, 1, n+1) {
			lli v1 = min(val[j].f, val[j].s);
			// printf("%lld %lld\n", val[j].f, val[j].s);
			tot += v1 * (1<<(j-1));
		}
		printf("%lld\n", tot);
	}


}