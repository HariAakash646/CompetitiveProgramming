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
    scd(n);
    vector<bitset<3000>> graph(n);

    frange(i, n)
    {
        string adj;
        cin >> adj;
        frange(j, n)
        {
            graph[i][j] = adj[j] - '0';
        }
    }
    lli tot = 0;
    frange(i, n)
    {
        bitset<3000> v = graph[i];
        // cout << v << "\n";
        frange(j, i + 1) v[j] = 0;
        forr(j, i + 1, n)
        {
            if (v[j] == 0)
                continue;
            v[j] = 0;
            bitset<3000> b = v & graph[j];
            // cout << v << " " << graph[j] << " " << b << "\n";
            tot += b.count();
        }
    }
    printf("%lld", tot);
}