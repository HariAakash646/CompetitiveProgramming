#pragma GCC optimize("O2")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
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

const lli mod = 1e9 + 7;

struct Arr {
	lli arr[205][205] = {0};
};

inline Arr matmul(Arr a, Arr b, int na, int ma, int nb, int mb) {
	
	Arr out;

	for(int i=0; i<ma; i+=4) {
		frange(j, na) {
			frange(k, mb) {
				out.arr[j][k] += a.arr[j][i] * b.arr[i][k] + a.arr[j][i+1] * b.arr[i+1][k] + a.arr[j][i+2] * b.arr[i+2][k] + a.arr[j][i+3] * b.arr[i+3][k];
				if(out.arr[j][k] >= mod)
					out.arr[j][k] %= mod;
			}
		}
	}
	// frange(i, na) {
	// 	frange(j, mb) {
	// 		printf("%lld ", out[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("********************\n");
	return out;
}

inline Arr binexp(Arr a, lli k, int n) {
	
	if(k == 1) return a;
	Arr out;
	if(k == 0) {

		frange(i, n) out.arr[i][i] = 1;
		return out;
	}

	out = binexp(a, k/2, n);
	out = matmul(out, out, n, n, n, n);
	if(k % 2) {
		out = matmul(out, a, n, n, n, n);
	}
	return out;
}

int main() {
	// usaco();
	lli n, c;
	sclld(n);
	sclld(c);

	Arr vec;
	frange(i, c+1) vec.arr[i][0] = 1;
	forr(i, 1, c+1) vec.arr[i-1][i] = 1;
	Arr val;
	val.arr[0][0] = 1;
	vec = binexp(vec, n, c+1);
	// frange(i, c+1) {
	// 	frange(j, c+1) {
	// 		printf("%lld ", vec[i][j]);
	// 	}
	// 	printf("\n");
	// }
	auto out = matmul(val, vec, 1, c+1, c+1, c+1);

	lli tot = 0;
	frange(i, c+1) {
		tot += out.arr[0][i];
	}
	printf("%lld", tot%mod);
}