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
    string str;
    cin >> n >> str;
    int l = 0;
    int r = -1;
    map<char, int> mp1;
    // mp1[str[0]]++;
    set<char> st;
    for (auto e : str)
        st.insert(e);
    int c = st.size();
    int v = 0;
    int mi = n;
    while (r < n - 1)
    {
        r++;
        if (mp1[str[r]] == 0)
        {
            v++;
        }
        mp1[str[r]]++;

        if (v >= c)
        {
            while (l <= r)
            {
                mp1[str[l]]--;
                if (mp1[str[l]] == 0)
                {
                    v--;
                    break;
                }
                l++;
            }
            mi = min(mi, r - l + 1);
            l++;
        }
    }
    printf("%d", mi);
}