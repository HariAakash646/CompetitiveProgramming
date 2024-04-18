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
    string num;
    cin >> num;
    int n = num.size();

    int ma = 1;
    int mv = 0;
    frange(i, 1 << (n - 1))
    {
        int sz = 1;
        string curr = "";
        set<string> st;
        bool iter = true;
        frange(k, n)
        {
            curr += num[k];
            if (i & (1 << k))
            {
                sz++;
                if (curr.size() != 1 && curr[0] == '0')
                {
                    iter = false;
                    break;
                }
                st.insert(curr);
                curr = "";
            }
        }
        if (curr.size() != 1 && curr[0] == '0')
        {
            iter = false;
        }
        if (!iter)
            continue;
        st.insert(curr);
        if (st.size() == sz)
        {
            if (sz >= ma)
            {
                ma = sz;
                mv = i;
            }
        }
    }
    frange(k, n)
    {
        cout << num[k];
        if (mv & (1 << k))
            cout << '-';
    }
}
