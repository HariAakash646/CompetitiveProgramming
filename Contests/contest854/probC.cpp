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
#define MP make_pair
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
    frange(i, t)
    {
        string str;
        cin >> str;
        int n = str.size();
        vector<char> vec(n);
        frange(i, n)
        {
            vec[i] = str[i];
        }
        sort(all(vec));
        if (vec.size() > 2 && vec[0] != vec[1])
        {
            bool eq = true;
            forr(i, 2, n)
            {
                if (vec[i] != vec[i - 1])
                {
                    eq = false;
                    break;
                }
            }
            if (eq)
            {
                int c = n / 2;
                frange(i, c) cout << vec[1];
                cout << vec[0];
                frange(i, c - ((n - 1) % 2)) cout << vec[1];
                cout << "\n";
                continue;
            }
        }
        vector<char> ans(n);
        int j = 0;
        bool done = false;
        frange(i, (n + 1) / 2)
        {
            ans[n - i - 1] = vec[j];
            j++;
            if (i != n - i - 1)
            {
                ans[i] = vec[j];
                j++;
            }
            else
                break;
            if (ans[i] != ans[n - i - 1])
            {
                forr(k, i + 1, n - i - 1)
                {
                    ans[k] = vec[j];
                    j++;
                }
                break;
            }
            if (n - j > 2 && vec[j] != vec[j + 1])
            {
                bool eq = true;
                forr(k, j + 2, n)
                {
                    if (vec[k] != vec[k - 1])
                    {
                        eq = false;
                        break;
                    }
                }
                if (eq)
                {
                    for (auto e : ans)
                    {
                        if (e == 0)
                            break;
                        cout << e;
                    }
                    int c = (n - j) / 2;
                    frange(k, c) cout << vec[j + 1];
                    cout << vec[j];
                    frange(k, c - (((n - j) - 1) % 2)) cout << vec[j + 1];
                    reverse(all(ans));
                    for (auto e : ans)
                    {
                        if (e == 0)
                            break;
                        cout << e;
                    }
                    cout << "\n";
                    done = true;
                    break;
                }
            }
        }
        if (done)
            continue;
        // reverse(all(ans));
        for (auto e : ans)
        {
            cout << e;
        }
        cout << "\n";
    }
}