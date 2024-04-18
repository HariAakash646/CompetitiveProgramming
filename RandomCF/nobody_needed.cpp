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

template <class T>
struct BIT
{
    int size;
    vector<T> bit;
    vector<T> vec;

    BIT(int n) : size(n), bit(n + 1), vec(n + 1) {}

    int lsb(int x)
    {
        return x & (-x);
    }

    void set(int id, T v)
    {
        add(id, v - vec[id]);
    }

    void add(int id, T v)
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

    T query(int id)
    {
        T tot = 0;
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
	// usaco();
	int t;
	scd(t);

	frange(_, t) {
		int n, q;
		scd(n);
		scd(q);
		vi vec(n+1);
		vi pos(n+1);
		forr(i, 1, n+1) {scd(vec[i]); pos[vec[i]]=i;}

		vb vis(n+1);
		BIT<lli> bit(n+1);

		vector<pair<pii, int>> quer(q);

		frange(i, q) {
			scd(quer[i].f.f);
			scd(quer[i].f.s);
			quer[i].s = i;
		}
		sort(all(quer), greater<>());
		vll out(q);
		vll dp(n+1);
		vvi fact(n+1);
		int id = n+1;
		for(auto p : quer) {
			while(id > p.f.f) {
				id--;
				dp[id]++;
				bit.add(id, 1);
				for(int i=2*vec[id]; i<=n; i+=vec[id]) {
					if(pos[i] >= id) {
						dp[pos[i]]++;
						fact[id].pb(pos[i]);
						for(auto e : fact[pos[i]]) dp[e] += dp[pos[i]];
						bit.add(pos[i], dp[pos[i]]);
					}
					dp[pos[i]] = 0;
				}
				dp[id]= 0;
			}
			out[p.s] = bit.query(p.f.s);
		}
		frange(i, q) printf("%lld ", out[i]);
		printf("\n");
	}
}