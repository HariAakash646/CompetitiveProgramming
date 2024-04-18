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
typedef vector<bool> vb;
typedef set<int> seti;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}


int main() {
	// usaco();
	fastio();
	int l, q;
	cin >> l >> q;
	string str;
	cin >> str;

	vi mv(1<<l);

	frange(i, 1<<l) {
		mv[i] = str[i] - '0';
	}

	int v = 1;



	frange(i, l) v *= 3;

	vi tot(v);
	vi po3(l+1);
	po3[0] = 1;
	forr(i, 1, l+1) po3[i] = po3[i-1] * 3;
	frange(i, v) {
		int li=0;
		int r = 0;
		int x = 0;
		int k = i;
		bool done = false;
		frange(j, l) {
			if(k % 3 == 1) {
				x += po3[j];
				li += po3[j];
				r += po3[j];
			}
			else if(k % 3 == 2) {
				x += po3[j] * 2;
				if(!done)
					{r += po3[j]; done = true;}
				else {
					li += po3[j] * 2;;
					r += po3[j] * 2;
				}
			}
			k /= 3;
		}
		k = i;
		if(!done) {
			int x2 = 0;
			frange(j, l) {
				if(k % 3 == 1) {
					x2 += (1<<j);
				}
				k /= 3;
			}
			tot[x] = mv[x2];
		}
		else {
			// cout << x << " " << li << " " << r << "\n";
			tot[x] = tot[li] + tot[r];
		}
	}

	frange(_, q) {
		string str;
		cin >> str;
		int v = 0;
		frange(i, l) {
			if(str[l-i-1] == '1') v += po3[i];
			else if(str[l-i-1] == '?') v += 2*po3[i];
		}
		// int to = 0;
		// frange(i, 1<<l) {
		// 	bool done = true;
		// 	frange(j, l) {
		// 		if(str[j] == '?') continue;
		// 		else {
		// 			if(bool(str[j] - '0') != bool(i&(1<<(l-j-1)))) done = false;
		// 		}
		// 	}
		// 	if(done) to += mv[i];
		// }
		// cout << str << " " << v << " ";
		cout << tot[v] << "\n";
	}
}