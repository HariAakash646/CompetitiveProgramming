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

void usaco()
{
    freopen("input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int n, q;
vi v1;
vi v2;

int check(lli k, int l) {
    int lo = 1;
    int hi = l;

    while(lo != hi) {
        int mid = (lo + hi)/2;
        if(2*k + v2[l-mid] <= v1[mid]) {
            hi = mid;
        }
        else {
            lo = mid+1;
        }
    }
        return lo;
}

int main() {
    usaco();
    scd(n);
    scd(q);
    v1 = v2 = vi(n+1);
    forr(i, 1, n+1) {
        scd(v1[i]);
        v2[i] = -v1[i];
    }
    sort(v1.begin()+1, v1.end());
    sort(v2.begin()+1, v2.end());
    vll pref1(n+1);
    vll pref2(n+1);

    forr(i, 1, n+1) {
        pref1[i] = pref1[i-1] + v1[i];
        pref2[i] = pref2[i-1] + v2[i];
    }
    frange(_, q) {
        lli k;
        int l;
        sclld(k);
        scd(l);
        int id = check(k, l);
        lli v = 2*lli(k) * (l - id) + pref2[l-id] + pref1[id];
        id--;
        v = min(v, 2*lli(k) * (l-id) + pref2[l-id] + pref1[id]);
        
        printf("%lld\n", v);

    }
    

}