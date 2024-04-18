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

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

bool am_i_square(int n, int Q) {

	for(int i=1; i<=n; i+=(n+4)/5) {
		for(int j=1; j<=n; j+=(n+4)/5) {
			if(inside_shape(i, j)) {
				int lo = 1;
				int hi = i;
				while(lo != hi) {
					int mid = (lo+hi+1)/2;
					if(inside_shape(mid, j)) {
						hi = mid;
					}
					else lo = mid+1;
				}
				int li = lo;
				lo = i;
				hi = n;
				while(lo != hi) {
					int mid = (lo+hi)/2;
					if(inside_shape(mid, j)) {
						lo = mid;
					}
					else hi = mid-1;
				}
				int ri = lo;
				lo = 1;
				hi = j;
				while(lo != hi) {
					int mid = (lo+hi+1)/2;
					if(inside_shape(i, mid)) {
						hi = mid;
					}
					else lo = mid+1;
				}
				int lj = lo;
				lo = j;
				hi = n;
				while(lo != hi) {
					int mid = (lo+hi)/2;
					if(inside_shape(i, mid)) {
						lo = mid;
					}
					else hi = mid-1;
				}
				int rj = lo;
				if(ri - li == rj - lj) return true;
				else return false;
			}
		}
	}

	return false;
}

int main() {
	return 0;
}