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

	int n = rand(1, 10);
	printf("%d\n", n);
	
	frange(i, n) {
		printf("%d ", rand(1, 100));
	}
	printf("\n");
	frange(i, n) {
		printf("%d ", rand(1, 100));
	}



} 