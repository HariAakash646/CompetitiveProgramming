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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    int t;
    cin >> t;

    frange(_, t)
    {
        int n;
        string str;
        cin >> str;
        n = str.size();

        stack<int> stk;
        bool done = true;
        for (auto e : str)
        {
            int so = 1;
            if (stk.size() == 0)
                so = 1;
            else
            {
                so = stk.top();
            }
            if (e == '+')
            {
                if (stk.size() == 0)
                    stk.push(1);
                else if (stk.top() != 0)
                    stk.push(-1);
                else
                    stk.push(0);
            }
            else if (e == '-')
            {
                int t = stk.top();
                stk.pop();
                if (t == 1)
                {
                    if (stk.size())
                    {
                        stk.pop();
                        stk.push(t);
                    }
                }
            }
            else
            {
                if (e == '1')
                {
                    if (so == -1)
                    {
                        stk.pop();
                        stk.push(1);
                    }
                    else if (so == 0)
                    {
                        done = false;
                        break;
                    }
                }
                else
                {
                    if (so == -1)
                    {
                        stk.pop();
                        stk.push(0);
                    }
                    else if (so == 1)
                    {
                        done = false;
                        break;
                    }
                }
            }
        }
        if (done)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}