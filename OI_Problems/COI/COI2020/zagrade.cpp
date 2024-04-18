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
typedef long double ld;

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    int n, q;
    fastio();
    cin >> n >> q;
    string str = "";
    frange(i, n) str += "(";
    stack<int> stk;
    int id = 1;
    stk.push(id);
    forr(i, 2, n + 1)
    {
        if (stk.empty())
        {
            stk.push(i);
            continue;
        }
        int v = stk.top();
        cout << "? " << v << " " << i << endl;
        // fflush(stdout);
        int a;
        cin >> a;
        if (a)
        {
            str[v - 1] = '(';
            str[i - 1] = ')';
            stk.pop();
        }
        else
        {
            stk.push(i);
        }
    }
    int k = stk.size();
    frange(i, k / 2)
    {
        int v = stk.top();
        stk.pop();
        str[v - 1] = '(';
    }
    frange(i, k / 2)
    {
        int v = stk.top();
        stk.pop();
        str[v - 1] = ')';
    }
    cout << "! " << str << endl;
}