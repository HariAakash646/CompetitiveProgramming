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
    int t;
    cin >> t;
    frange(_, t)
    {
        int n;
        cin >> n;
        vs vec(n);
        multiset<string> rev;
        bool one = false;
        frange(i, n)
        {
            string str;
            cin >> vec[i];
            str = vec[i];
            string s1 = str;
            reverse(all(str));
            if (str == s1)
                one = true;

            rev.insert(str);
        }
        if (one)
        {
            cout << "YES\n";
            continue;
        }
        bool done = false;
        for (auto e : vec)
        {
            // reverse(all(e));
            auto itr = rev.find(e);
            // rev.erase(itr);
            // itr = rev.find(e);
            if (itr != rev.end())
            {
                cout << "YES\n";
                done = true;
                break;
            }
            if (e.size() == 3)
            {
                string str = e.substr(0, 2);
                if (rev.find(str) != rev.end())
                {
                    cout << "YES\n";
                    done = true;
                    break;
                }
            }
            else if (e.size() == 2)
            {
                string str = e + "$";
                auto it = rev.upper_bound(str);
                if (it != rev.end())
                {
                    if (e == (*it).substr(0, 2))
                    {
                        cout << "YES\n";
                        done = true;
                        break;
                    }
                }
            }
            reverse(all(e));
            rev.erase(rev.find(e));
        }

        if (!done)
            cout << "NO\n";
    }
}