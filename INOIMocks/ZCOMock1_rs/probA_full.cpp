#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t);
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

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

inline int readInt() {
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar_unlocked();
    while (ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar_unlocked();
	}
    return x;
}


const int MAXN = 1e7+5;
pii stk[MAXN];

int main() {
	// usaco();
	// fastio();
	int n;
	n = readInt();

	// vii vec(n);
	// frange(i, n) {
	// 	cin >> (vec[i].f);
	// 	cin >> (vec[i].s);
	// }

	
	int top = -1;
	pii e, p, k;

	frange(i, n) {
		e.f = readInt();
		e.s = readInt();
		if(top >= 0 && stk[top].s >= e.s) {
			p = stk[top];
			p.f += p.s - e.s;
			if(p.f >= e.f) continue;
		}
		while(top >= 0 && e.s >= stk[top].s) {
			// auto p = stk[top];
			k = e;
			k.f -= k.s - stk[top].s;
			if(k.f <= stk[top].f) top--;
			else break;
		}
		stk[++top] = e;
	}
	cout << top+1;
}