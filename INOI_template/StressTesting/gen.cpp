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

int rand(int a, int b) {
	return rand() % (b - a + 1) + a;
}

int main(int argc, char* argv[]) {
	srand(atoi(argv[1]));

	int n = rand(2, 4);
	int m = rand(1, min(n*n, 5));

	printf("%d %d\n", n, m);

	set<pii> st;
	while(st.size() < m) {
		int x = rand(0, n-1);
		int y = rand(0, n-1);
		st.insert(mp(x, y));
	}
	for(auto p : st) printf("%d %d %d\n", p.f, p.s, rand(1, 5));


} 