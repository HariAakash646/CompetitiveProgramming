#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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
    freopen("input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}


int main() {
	// usaco();
	int n;
	scd(n);
	// printf("%d\n", n);
	vii vec(n);
	seti st;
	frange(i, n) {
		scd(vec[i].f);
		scd(vec[i].s);
		st.insert(vec[i].s);
	}

	int c = st.size();
	sort(all(vec));
	map<int, int> m;
	int i1 = 0;
	int i2 = 0;
	
	int mi = 1e9;
	int c1 = 0;
	while(i2 < n) {
		m[vec[i2].s]++;
		if(m[vec[i2].s] == 1) c1++;
		while(c1== c) {
			mi = min(mi, vec[i2].f - vec[i1].f);
			
			m[vec[i1].s]--;
			if(m[vec[i1].s] == 0) c1--;
			i1++;
		}
		i2++;
	}
	printf("%d", mi);

}