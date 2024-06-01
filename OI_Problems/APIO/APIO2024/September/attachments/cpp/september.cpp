#include "september.h"
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



vvi graph;


int solve(int n, int m, std::vector<int> par, std::vector<std::vector<int>> S) {
	vi deg(n), cnt(n);
	forr(i, 1, n) {
		deg[par[i]]++;
	}
	seti act;
	int c = 0;
	forr(i, 0, n-1) {
		frange(j, m) {
			int x = S[j][i];
			cnt[x]++;
			act.insert(x);
			while(cnt[x] == m && deg[x]==0 && act.find(x) != act.end()) {
				act.erase(x);
				x = par[x];
				deg[x]--;
			}
		}
		
		if(act.empty()) c++;
	}

	return c;
}
