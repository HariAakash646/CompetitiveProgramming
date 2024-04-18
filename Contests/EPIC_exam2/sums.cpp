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
    vll vec(n + 1);
    forr(i, 1, n + 1) sclld(vec[i]);
    vll dpa(n + 1), dpi(n + 1);

    forr(i, 1, n + 1)
    {
        if (i % 2)
        {
            dpa[i] = max(dpa[i - 1] + vec[i], vec[i]);
            dpi[i] = min(dpi[i - 1] + vec[i], vec[i]);
        }
        else
        {
            dpa[i] = max(dpa[i - 1] - vec[i], -vec[i]);
            dpi[i] = min(dpi[i - 1] - vec[i], -vec[i]);
        }
    }
    printf("%lld", max(abs(*max_element(all(dpa))), abs(*min_element(all(dpi)))));
}