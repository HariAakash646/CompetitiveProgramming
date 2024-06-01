#include "perm.h"
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

vi insert(vi vec, int id, int v) {
	vi out;
	frange(i, id) {
		out.pb(vec[i]);
	}
	out.pb(v);
	forr(i, id, vec.size()) {
		out.pb(vec[i]);
	}
	return out;
}

vi construct_permutation(long long k)
{
	vi vec;
	int n = 0;
	
	vi out;

	for(int i=60; i>=0; i--) {
		if(k&(1LL<<i)) {
			frange(j, i) {
				out.pb(j);
			}
			n = i;
			break;
		}
	}

	int id = n-1;
	for(int i=id; i>=0; i--) {
		if(k&(1LL<<i)) {
			out = insert(out, i, n);
			n++;
		}
	}

	// printf("%lld\n", k);
	// for(auto e : out) printf("%d ", e);
	// printf("\n");
	return out;
}