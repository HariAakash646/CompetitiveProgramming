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
    vll vec(2 * n);
    frange(i, 2 * n) sclld(vec[i]);
    vector<pair<lli, int>> tmp(2 * n);
    frange(i, 2 * n)
    {
        tmp[i] = mp(vec[i], i);
    }
    sort(all(tmp));
    vi col(2 * n);
    frange(i, n)
    {
        col[tmp[i].s] = 1;
    }
    stack<pii> stk;
    lli tot = 0;
    string out = "";
    frange(i, 2 * n)
    {
        if (stk.size() && stk.top().s != col[i])
        {
            auto p = stk.top();
            stk.pop();
            tot += abs(vec[p.f] - vec[i]);
            out += ')';
        }
        else
        {
            stk.push(mp(i, col[i]));
            out += '(';
        }
    }
    cout << out;
}