#include "squarerect.h"
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

bool am_i_square(int n, int Q) {

	// int i1 = (rand() % 5 + 1) * 20;
	// int j1 = (rand() % 5 + 1) * 20;
	for(int i=20; i<=n; i+=20) {

		vi vec;
		if(Q == 1e4) vec = {20, 41, 61, 81};
		else
		vec = {20, 40, 61, 81};
		// int id = rand() % 3+1;
		// for(int j=id; j<4; j++) vec[j]++;
		seti st;
		st.insert(0);
		st.insert(101);
		for(auto j : vec) {
			// printf("%d %d\n", i, j);
			if(inside_shape(i, j)) {
				int lo = max(1, i-20+1);
				int hi = i;
				while(lo != hi) {
					int mid = (lo+hi)/2;
					if(inside_shape(mid, j)) {
						hi = mid;
					}
					else lo = mid+1;
				}
				int li = lo;
				lo = i;
				hi = n;
				while(lo != hi) {
					int mid = (lo+hi+1)/2;
					if(inside_shape(mid, j)) {
						lo = mid;
					}
					else hi = mid-1;
				}
				int ri = lo;
				int x = ri - li;
				if(x < 19) return false;
				lo = *prev(st.lower_bound(j))+1;
				hi = j;
				while(lo != hi) {
					int mid = (lo+hi)/2;
					if(inside_shape(i, mid)) {
						hi = mid;
					}
					else lo = mid+1;
				}
				int lj = lo;

				if(lj + x <= n && inside_shape(i, lj+x)) {
					if(lj + x + 1 > n || !inside_shape(i, lj+x+1)) return true;
					else return false;
				}
				else return false;
				st.insert(j);
			}
		}
	}

	return false;
}
