#include "gap.h"
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

// Subtask 1 too trivial

long long findGap(int T, int n)
{
	lli st, en;
	MinMax(0, 1e18, &st, &en);
	lli l = en - st;
	lli x = (l + n-2) / (n-1);
	lli pre = st;
	lli out = x;
	for(lli i=st; i<=en; i+=x+1) {
		lli mi, ma;
		MinMax(i, min(en, i+x), &mi, &ma);
		if(mi != -1)
			out = max(out, mi - pre);
		if(ma != -1)
		pre = ma;
	}
	return out;
}
