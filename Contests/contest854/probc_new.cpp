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

int n;
vector<char> vec;
vector<char> ans;

void equal(int j, int st, int en)
{
    // printf("%d %d %d\n", j, st, en);
    int c = (en - st) / 2;
    frange(k, c) ans[st + k] = vec[j + 1];
    ans[st + c] = vec[j];
    frange(k, c - (((en - st) - 1) % 2)) ans[en - k - 1] = vec[j + 1];
}

void work(int j, int st, int en)
{
    forr(i, st, en + 1)
    {
        ans[i] = vec[j];
        j++;
    }
}

void rec(int j, int st, int en)
{
    if (n - j > 2 && vec[j] != vec[j + 1] && vec[j + 1] == vec[n - 1])
    {
        equal(j, st, en + 1);
    }
    else if (st < en)
    {
        ans[en] = vec[j];
        ans[st] = vec[j + 1];
        if (vec[j] != vec[j + 1])
        {
            work(j + 2, st + 1, en - 1);
        }
        else
            rec(j + 2, st + 1, en - 1);
    }
    else if (st == en)
        ans[st] = vec[j];
}

int main()
{
    int t;
    cin >> t;
    frange(i, t)
    {
        string str;
        cin >> str;
        n = str.size();
        vec = vector<char>(n);
        frange(i, n)
        {
            vec[i] = str[i];
        }
        sort(all(vec));
        ans = vector<char>(n);
        rec(0, 0, n - 1);
        for (auto e : ans)
        {
            cout << e;
        }
        cout << "\n";
    }
}