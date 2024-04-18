#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.size();
    int m = str2.size();
    vi forw(m + 1);
    forw[0] = -1;
    int curr = 1;
    frange(i, n)
    {
        if (str1[i] == str2[curr - 1])
        {
            forw[curr] = i;
            curr++;
        }
        if (curr > m)
            break;
    }
    // for (auto i : forw)
    //     cout << i << " ";
    // cout << "\n";
    vi rev(m + 1);
    rev[m] = n;
    curr = m - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (str1[i] == str2[curr])
        {

            rev[curr] = i;
            curr--;
        }
        if (curr < 0)
            break;
    }
    // for (auto i : rev)
    //     cout << i << " ";
    // cout << "\n";
    int ma = 0;
    frange(i, m + 1)
    {
        ma = max(ma, rev[i] - forw[i] - 1);
    }
    cout << ma;
}