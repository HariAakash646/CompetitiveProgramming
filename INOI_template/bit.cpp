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
typedef long long lli;
typedef vector<lli> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef set<int> seti;
typedef map<int, int> mpii;
typedef multiset<int> mseti;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

// Checked with CSES 1648

template <class T>
struct BIT {
	int size;
	vector<T> vec, bit;

	BIT(int n) : size(n), vec(n+1), bit(n+1) {}

	int lsb(int x) {
		return x & (-x);
	}

	void add(int id, T v) {
		vec[id] += v;
		while(id <= size) {
			bit[id] += v;
			id += lsb(id);
		}
	}

	void set(int id, T v) {
		add(id, v - vec[id]);
	}

	T query(int id) {
		T tot = 0;
		if(id == 0) return tot;

		while(id >= 1) {
			tot += bit[id];
			id -= lsb(id);
		}
		return tot;
	}

};

int main() {
	// usaco();
	int n, m;
    scd(n);
    scd(m);
     
    BIT<lli> bit(n);
 
    frange(i, n)
    {
    	int a;
        scd(a);
        bit.set(i+1, a);
    }
    int q, b, c;
    frange(i, m)
    {
        scd(q);
        scd(b);
        scd(c);
        if (q == 1)
        {
            bit.set(b, c);
        }
        else
        {
            printf("%lld\n", bit.query(c) - bit.query(b-1));
        }
    }
}