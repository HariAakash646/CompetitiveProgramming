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

int n;

int dist(string t, string s) {
    int ans = 0;
    for(int i=1; i<=n; i++) {
        int pos = -1;
        for(int j=i; j<=n; j++) {
            if(s[j]==t[i]) {
                pos = j;
                break;
            }
        }
        ans += abs(pos-i);
        for(int j=pos; j>i; j--) swap(s[j], s[j-1]);
    }
    return ans;
}

int main() {
	// usaco();
	string str;
	cin >> n >> str;

	int rc = 0;
	int gc = 0;
	int yc = 0;

	frange(i, n) {
		if(str[i] == 'R') rc++;
		else if(str[i] == 'G') gc++;
		else yc++;
	}

	// if(rc == gc) {
	// 	string str1, str2;
	// 	frange(i, n) {
	// 		if(i % 2) {
	// 			str1 += 'R';
	// 			str2 += 'G';
	// 		}
	// 		else {
	// 			str1 += 'G';
	// 			str2 += 'R';
	// 		}
	// 	}
	// 	printf("%lld", min(dist(str, str1), dist(str, str2)));
	// }
	// else if(rc == gc+1) {
	// 	string str1;
	// 	frange(i, n) {
	// 		if(i % 2==0) str1 += 'R';
	// 		else str1 += 'G';
	// 	}
	// 	printf("%lld", dist(str, str1));
	// }
	// else if(rc == gc-1) {
	// 	string str1;
	// 	frange(i, n) {
	// 		if(i % 2) str1 += 'R';
	// 		else str1 += 'G';
	// 	}
	// 	printf("%lld", dist(str, str1));
	// }
	// else printf("-1");


	int mi = 1e9;
	int x = 1;
	frange(i, n) x *= 3;
	frange(i, x) {
		string out;
		int v = i;
		int pr = 5;
		bool done = false;

		int rt = 0, gt = 0, yt= 0;

		frange(j, n) {
			if(v % 3 == pr) {
				done = true;
				break;
			}
			if(v % 3 == 2) {out += 'R';rt++;}
			else if(v % 3 == 1) {out += 'G'; gt++;}
			else {out += 'Y'; yt++;}
			pr = v % 3;
			v /= 3;
		}

		if(rt != rc || gt != gc || yt != yc) continue;
		
		if(done) continue;
		mi = min(mi, dist(str, out));
	}
	if(mi < 1e9)
	printf("%d", mi);
	else printf("-1");

}