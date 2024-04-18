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

int main()
{
    int n;
    lli kv;
    scd(n);
    sclld(kv);
    vll vec(n);
    frange(i, n)
    {
        lli k = i + 1;
        lli m = 2021;
        lli k3 = (k * k) % m * k % m;
        lli k2 = k * k % m;
        lli v = 123 * k3 + 456 * k2 + 789 * k + 822;
        v %= m;
        vec[i] = v;
    }
    sort(all(vec));
    printf("%lld", vec[kv - 1]);
}