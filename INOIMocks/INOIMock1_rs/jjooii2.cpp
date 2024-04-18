#include <bits/stdc++.h>

using namespace std;

#define scd(x) scanf("%d", &x)
#define sclld(x) scanf("%lld", &x)
#define frange(i, n) for(int i=0; i<n; i++)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define all(vec) vec.begin(), vec.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second

typedef long long lli;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<lli> vll;
typedef vector<vi> vvi;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int main() {
	// usaco();
	int n, k;
	scd(n);
	scd(k);

	string str;
	cin >> str;

	vi veci(n+1, -1), veco(n+1, -1), vecj(n+1, -1);

	int l = 0;
	int r = 0;
	int c = 0;
	if(str[l] == 'I') c++;
	bool done = false;
	while(l < n) {

		while(c < k) {
			r++;
			if(r >= n) {
				forr(i, l, n) veci[i] = -1;
				done = true;
				break;
			}
			if(str[r] == 'I') c++;
		}
		if(done) break;

		if(c == k) {
			veci[l] = r;
			if(str[l] == 'I') c--;
			l++;
		}
	}

	l = 0;
	r = 0;
	c = 0;
	if(str[l] == 'O') c++;
	done = false;
	while(l < n) {

		while(c < k) {
			r++;
			if(r >= n) {
				forr(i, l, n) veco[i] = -1;
				done = true;
				break;
			}
			if(str[r] == 'O') c++;
		}
		if(done) break;

		if(c == k) {
			veco[l] = r;
			if(str[l] == 'O') c--;
			l++;
		}
	}

	l = 0;
	r = 0;
	c = 0;
	if(str[l] == 'J') c++;
	done = false;
	while(l < n) {

		while(c < k) {
			r++;
			if(r >= n) {
				forr(i, l, n) vecj[i] = -1;
				done = true;
				break;
			}
			if(str[r] == 'J') c++;
		}
		if(done) break;

		if(c == k) {
			vecj[l] = r;
			if(str[l] == 'J') c--;
			l++;
		}
	}

	for(int i=n-1; i>=0; i--) {
		if(veco[i] != -1) {
			int id = veco[i];
			if(veci[id+1] != -1) {
				veco[i] = veci[id+1];
			}
			else veco[i] = -1;
		}
	}

	for(int i=n-1; i>=0; i--) {
		if(vecj[i] != -1) {
			int id = vecj[i];
			if(veco[id+1] != -1) {
				vecj[i] = veco[id+1];
			}
			else vecj[i] = -1;
		}
	}

	int out = -1;

	frange(i, n) {
		if(vecj[i] != -1) {
			int v = vecj[i] - i + 1 - 3 * k;
			if(out == -1) out = v;
			out = min(out, v);
		}
	}

	printf("%d", out);
}
