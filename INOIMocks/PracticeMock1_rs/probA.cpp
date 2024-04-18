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
	// freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
	usaco();
	fastio();
	int n, m;
	cin >> n >> m;

	multiset<char> st;

	vector<char> vec(n), v2(n);;

	frange(i, n) {
		string str;
		cin >> str;
		vec[i] = *min_element(all(str));
		v2[i] = *max_element(all(str));
		st.insert(v2[i]);
	}

	frange(i, n) {
		st.erase(st.find(v2[i]));
		if(st.empty() || vec[i] < *st.begin()) cout << 1;
		else cout << 0;
		st.insert(v2[i]);
	}
}