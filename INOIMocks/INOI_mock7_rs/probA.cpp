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

struct BIT
{
    int size;
    vector<lli> bit;
    vector<lli> vec;

    BIT(int n) : size(n), bit(n + 1), vec(n + 1) {}

    int lsb(int x)
    {
        return x & (-x);
    }

    void set(int id, lli v)
    {
        add(id, v - vec[id]);
    }

    void add(int id, lli v)
    {
        if (id == 0)
            return;
        vec[id] += v;
        while (id <= size)
        {
            bit[id] += v;
            id += lsb(id);
        }
    }

    lli query(int id)
    {
        lli tot = 0;
        if (id == 0)
            return tot;
        while (id >= 1)
        {
            tot += bit[id];
            id -= lsb(id);
        }
        return tot;
    }
};

int main() {
	usaco();
	int n;
	scd(n);

	vi vec(n+1);
	vi pos(n+1);
	forr(i, 1, n+1) {
		scd(vec[i]);
		pos[vec[i]] = i;
	}

	vll dp(n+1, 1e18);
	dp[0] = 0;

	forr(i, 1, n+1) {
		for(int j=i-1; j>=0; j--) {
			lli tot = 0;
			BIT bit(n);
			forr(k, j+1, i+1) {
				// printf("%d %d %d %d\n", i, j, j+1+i-k, k);
				tot += bit.query(j+1+(i-k));
				bit.add(vec[k], 1);
			}
			dp[i] = min(dp[i], tot + dp[j]);
		}
		printf("%lld ", dp[i]);
	}
	printf("%lld", dp[n]);




}