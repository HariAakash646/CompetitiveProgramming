#include "dna.h"
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

vi cnta1, cntc1, cntt1;
vi cnta2, cntc2, cntt2;
vi ac, at, ca, ct, ta, tc;

void init(std::string a, std::string b) {
	int n = a.size();
	cnta1 = cntc1 = cntt1 = vi(n+1);
	cnta2 = cntc2 = cntt2 = vi(n+1);
	ac = at = ca = ct = ta = tc = vi(n+1);
	forr(i, 1, n+1) {
		cnta1[i] = (a[i-1] == 'A') + cnta1[i-1];
		cntc1[i] = (a[i-1] == 'C') + cntc1[i-1];
		cntt1[i] = (a[i-1] == 'T') + cntt1[i-1];

		cnta2[i] = (b[i-1] == 'A') + cnta2[i-1];
		cntc2[i] = (b[i-1] == 'C') + cntc2[i-1];
		cntt2[i] = (b[i-1] == 'T') + cntt2[i-1];
		ac[i] = ac[i-1];
		at[i] = at[i-1];
		ca[i] = ca[i-1];
		ct[i] = ct[i-1];
		tc[i] = tc[i-1];
		ta[i] = ta[i-1];
		if(a[i-1] == 'A' && b[i-1] == 'C') ac[i]++;
		if(a[i-1] == 'A' && b[i-1] == 'T') at[i]++;
		if(a[i-1] == 'C' && b[i-1] == 'A') ca[i]++;
		if(a[i-1] == 'C' && b[i-1] == 'T') ct[i]++;
		if(a[i-1] == 'T' && b[i-1] == 'C') tc[i]++;
		if(a[i-1] == 'T' && b[i-1] == 'A') ta[i]++;

	}
}

int get_distance(int x, int y) {
	x++;
	y++;
	// printf("%d %d\n", cnta1[y] - cnta1[x-1], cnta2[y] - cnta2[x-1]);
	if(cnta1[y] - cnta1[x-1] != cnta2[y] - cnta2[x-1]) return -1;
	if(cntc1[y] - cntc1[x-1] != cntc2[y] - cntc2[x-1]) return -1;
	if(cntt1[y] - cntt1[x-1] != cntt2[y] - cntt2[x-1]) return -1;
	int out = 0;
	int acv = ac[y] - ac[x-1];
	int atv = at[y] - at[x-1];
	int cav = ca[y] - ca[x-1];
	int ctv = ct[y] - ct[x-1];
	int tcv = tc[y] - tc[x-1];
	int tav = ta[y] - ta[x-1];
	int v = min(acv, cav);

	out += v;
	acv -= v;
	cav -= v;

	v = min(atv, tav);
	out += v;
	atv -= v;
	tav -= v;

	v = min(tcv, ctv);
	out += v;
	tcv -= v;
	ctv -= v; 

	out += 2*(ctv + tcv);

	return out;
}
