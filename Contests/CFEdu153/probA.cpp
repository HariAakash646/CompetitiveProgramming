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

bool substr(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    bool sub = false;
    for (int i = 0; i + m < n; i++)
    {
        bool done = true;
        frange(j, m)
        {
            if (s1[i + j] != s2[j])
                done = false;
        }
        if (done)
            sub = true;
    }
    return sub;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        string str;
        cin >> str;
        int n = str.size();
        string o1 = "";
        frange(i, n) o1 += '(';
        frange(i, n) o1 += ')';
        string o2 = "";
        frange(i, n) o2 += "()";
        if (o1.find(str) == string::npos)
            cout << "YES\n"
                 << o1;
        else if (o2.find(str) == string::npos)
            cout << "YES\n"
                 << o2;
        else
            cout << "NO";
        cout << "\n";
    }
}